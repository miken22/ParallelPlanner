#include "PIDA.h"
#include <limits>
/*
	This is the first iterative deepening algorithm developed with parallel heuristic evaluation for this project. The idea
	behind this algorithm is to performs IDA* like normal, but instead of doing the heuristic calculation the
	main thread puts the children on a stack of nodes to process. The remaining threads are in a constant loop
	and continue to check this process stack for nodes, if it removes a node it does the heuristic evaluation and
	places the node in a priority queue called the open list. It is the open list that the main thread removes nodes
	from to do the state space search.

    Written by Michael Nowicki
*/

bool PIDA::find_plan(const int& h_choice) {

	bool s = false;
	bool k = false;
	bool* solved = &s;
	bool* killed = &k;

	// This boolean vector is used to represent which threads are active. There may be a case where both the
	// open and process lists are empty causing the main thread to increase to the next bound, but one of
	// the spawned threads is still processing the heuristic. This will make the main thread wait until it
	// has a chance to process that (and possibly more) nodes, guaranteeing to check every valid path for the bound.
	busy.resize(K-1,false);

    double heuristic_timer = 0;

	timer.start_timing_search();

	// Need to create an instance of the heuristic to process the initial state
	heuristic = Utilities::get_heuristic(h_choice, goals, operators, tg);
	// Set up initial bound
	int init_h = heuristic->calc_h(std::make_shared<LiteState>(initial_state));
    delete heuristic;
	
	// Test beginning heuristic to ensure it is a solvable task.
	if (init_h == std::numeric_limits<int>::max()) {
		std::cout << "Initial estimate assumes unsolvable." << std::endl;
		return false;
	}
	
	// Finish initializing state
	int init_g = 0;
	initial_state.set_g(init_g);
	initial_state.set_h(init_h);

	// Main parallel section, primary thread performs a search in the Parallel_Search() function while threads compute
	// heuristic values of states in the Compute_Heuristics() function.
#pragma omp parallel shared(solved, killed) num_threads(K) reduction(+ : heuristic_timer)
	{
		if (omp_get_thread_num() == 0) {
			parallel_search(solved, killed);
		}
		else {
			// Make private instances of heuristic for each thread
			Heuristic* thread_heuristic = Utilities::get_heuristic(h_choice, goals, operators, tg);
//			thread_heuristic->find_goal_ordering(initial_state);
			compute_heuristics(thread_heuristic, solved, killed, heuristic_timer);
			delete thread_heuristic;
		}
	}

    std::cout << "Average time each thread spent performing heuristic computation: " << (heuristic_timer/(K-1)) << " seconds" << std::endl;

	Utilities::clear(open_list);
	Utilities::clear(process_list);
	
	return *solved;
}

bool PIDA::search_is_safe() {
	bool safe = false;
#pragma omp critical
	{
		if ((std::find(busy.begin(), busy.end(), true) != busy.end())) {
			safe = true;
		}
	}
	// Have to do this since you cannot return or break in an OMP section
	if (safe) {
		return safe;
	}
	return (!open_list.empty() || !process_list.empty());
}

void PIDA::parallel_search(bool* solved, bool* killed) {

	// Successor function
	SuccessorGenerator successor_generator(goals, Search::protect_goals);

	int bound = initial_state.get_f();

	std::cout << "Initial heuristic estimate: " << bound << std::endl;
	// Main loop
	while (!(*killed) && !(*solved)) {

		StateSpace state_space;

		int nodes_expanded = 0;
		int nodes_generated = 0;
		int nodes_rejected = 0;
		int min = std::numeric_limits<int>().max();

		std::shared_ptr<LiteState> root(new LiteState(initial_state));

		open_list.push(root);
		state_space.add_initial_state(root);

		while (search_is_safe()) {

			if (!timer.is_still_valid()) {
				*killed = true;
				break;
			}

			// Current node being processed
			std::shared_ptr<LiteState> current;
			// Used to indicate if a node was safely removed from the stack
			bool safe = false;

			// Lock open_list to safely evaluate its elements
#pragma omp critical
			{
				if (!open_list.empty()) {
					current = open_list.top();
					open_list.pop();
					safe = true;
				}
			}
			// If node is not safely removed, loop
			if (!safe) {
				continue;
			}

			// Depth check, store smallest f value for next iteration
			if (current->get_f() > bound) {
				int f = current->get_f();
				if (f < min) {
					min = f;
				}
				nodes_rejected++;
				continue;
			}
	
			// Goal check
			if (state_space.state_is_goal(*current, goals)) {
				timer.stop_timing_search();
				// Stop slave threads from performing unnecessary evaluations.
                *killed = true;

				std::vector<int> plan = state_space.trace_path_from_goal(current);

				Validate vp(operators, plan, initial_state, goals);
				*solved = vp.try_plan();

				std::cout << "Nodes generated during iteration: " << nodes_generated << std::endl;
				std::cout << "Nodes expanded during iteration: " << nodes_expanded << std::endl;

   				std::cout << "Parallel search took " << timer.get_search_time() << " seconds." << std::endl;
				std::cout << "Plan is of length " << plan.size() << std::endl;

				break;
			}

			nodes_expanded++;

			const std::vector<Operator>& applicable_operators = get_applicable_ops(*current);

			for (std::size_t i = 0; i < applicable_operators.size(); i++) {

				const Operator& op = applicable_operators[i];

				std::shared_ptr<LiteState> child = successor_generator.get_successor(current, op);

				// This checks to verify if we have found the state before, if we have and can get there in fewer steps (g value) we can
				// ignore this child.
				if (state_space.child_is_duplicate(child)) {
					continue;
				}

				nodes_generated++;

#pragma omp critical
				{
					process_list.push(child);
				}

			}
		}

		state_space.clear();

		if (*solved) {
			break;
		}
		else {

            std::cout << "Nodes generated during iteration: " << nodes_generated << std::endl;
            std::cout << "Nodes expanded during iteration: " << nodes_expanded << std::endl;
            std::cout << "Nodes rejected during iteration: " << nodes_rejected << std::endl;

            if (min >= 100000) {
                std::cout << "Disabling goal protection." << std::endl;
                Search::protect_goals = false;
            } else {
                bound = min;
			}
		}

		std::cout << "Depth reached, adjusting bound to " << bound << std::endl;
		if (!timer.is_still_valid()) {
			break;
		}
	}
	// Signal to threads that time has expired
	*killed = true;
	if (!*solved) {
		std::cout << "Plan could not be found in search time given." << std::endl;
	}

}

void PIDA::compute_heuristics(Heuristic *thread_heuristic, bool* solved, bool* killed, double& heuristic_timer) {

	// Keep threads in loop until either a solution has been found or a thread signals to end the search
	while (!*solved && !*killed) {
		std::shared_ptr<LiteState> current;

		// Lock the process_list to safely examine it and remove the top if not empty
		#pragma omp critical
		{
			if (!process_list.empty()) {
				current = process_list.top();
				process_list.pop();
				busy[omp_get_thread_num() - 1] = true;
   			}
		}
		// Make sure an item was actually removed
		if (!busy[omp_get_thread_num() - 1]) {
			continue;
		}
		// Heuristic calculation
		double hTime = omp_get_wtime();
		int h = thread_heuristic->calc_h(current);
		heuristic_timer += (omp_get_wtime() - hTime);
		current->set_h(h);
		// Lock the open_list for the main thread and place the node with it's new h value on top
		#pragma omp critical
		{
			open_list.push(current);
			busy[omp_get_thread_num() - 1] = false;
		}
	}
}
