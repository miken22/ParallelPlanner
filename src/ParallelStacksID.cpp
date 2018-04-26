#include "ParallelStacksID.h"
#include <limits>

/*
	This is the second iterative deepening algorithm developed with parallel heuristic evaluation. The idea
	behind this algorithm is to performs cost bound ID like normal, but instead of doing the heuristic calculation the
	main thread puts the children on a stack of nodes to process. The remaining threads are in a constant loop
	and continue to check this process stack for nodes, if it removes a node it does the heuristic evaluation and
	places the node in an alternate state called the open list. It is the open list that the main thread removes nodes
	from to do the state space search.

    Written by Michael Nowicki
*/

bool ParallelStacksID::find_plan(const int& h_choice) {

	bool s = false;
	bool k = false;
	bool* solved =& s;
	bool* killed =& k;

	busy.resize(K, false);

	double heuristic_timer;
    heuristic_timer = 0;

    // Need to create an instance of the heuristic to process the initial state
	heuristic = Utilities::get_heuristic(h_choice, goals, operators, tg);
	// Set up initial bound
	int init_h = heuristic->calc_h(std::make_shared<LiteState>(initial_state));
	
	// Test beginning heuristic to ensure it is a solvable task.
	if (init_h == std::numeric_limits<int>::max()) {
		std::cout << "Initial estimate assumes unsolvable." << std::endl;
		return false;
	}

	initial_state.set_h(init_h);
    delete heuristic;


#pragma omp parallel shared(solved, killed) num_threads(K) reduction(+ : heuristic_timer)
	{
		// Each thread gets a private copy of the heuristic function for its use

		if (omp_get_thread_num() == 0) {;
			parallel_search(solved, killed);
		}
		else {
			Heuristic* thread_heuristic = Utilities::get_heuristic(h_choice, goals, operators, tg);
			compute_heuristics(thread_heuristic, solved, killed, heuristic_timer);
            delete thread_heuristic;
		}
	}

    std::cout << "Average time each thread spent performing heuristic computation: " << (heuristic_timer/(K-1)) << " seconds" << std::endl;

	Utilities::clear(open_list);
	Utilities::clear(process_list);

	return *solved;
}

bool ParallelStacksID::search_is_safe() {

	bool safe = false;

#pragma omp critical
	{
		if ((std::find(busy.begin(), busy.end(), true) != busy.end())) {
			safe = true;
		}
	}

	// Ugly but needed, see PIDA implementation for explanation
	if (safe) {
		return safe;
	}

	return (!open_list.empty() || !process_list.empty());
}

void ParallelStacksID::parallel_search(bool* solved, bool* killed) {


	// Successor function
	SuccessorGenerator successor_generator(goals, Search::protect_goals);
	timer.start_timing_search();
	// Set up initial bound
	int bound = 0;

	// Finish initializing state
	initial_state.set_g(bound);

	std::cout << "Initial heuristic estimate: " << initial_state.get_h() << std::endl;
	bound = initial_state.get_h();

	// Main loop
	while (!(*killed) && !(*solved)) {

        // Initialize components for search
		int nodes_expanded = 0;
		int nodes_generated = 0;
		int nodes_rejected = 0;
		int min = std::numeric_limits<int>().max();

        // Create state space
		StateSpace state_space;

		std::shared_ptr<LiteState> root(new LiteState(initial_state));

		state_space.add_initial_state(root);

		open_list.push(root);

		// Stack based DFS, continues to run while both the main thread and the children both have States to process
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

                *killed = true;

				std::vector<int> op_steps = state_space.trace_path_from_goal(current);
				Validate vp = Validate(operators, op_steps, initial_state, goals);
				*solved = vp.try_plan();

				std::cout << "Nodes generated during iteration: " << nodes_generated << std::endl;
				std::cout << "Nodes expanded during iteration: " << nodes_expanded << std::endl;

				std::cout << "Parallel search took " << timer.get_search_time() << " seconds." << std::endl;
				std::cout << "Plan is of length " << op_steps.size() << std::endl;

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

void ParallelStacksID::compute_heuristics(Heuristic *heuristic, bool* solved, bool* killed, double& heuristic_timer) {

	// Keep threads in loop until
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
		double startTime = omp_get_wtime();
		int h = heuristic->calc_h(current);
		heuristic_timer += (omp_get_wtime() - startTime);

		current->set_h(h);
		// Lock the open_list for the main thread and place the node with it's new h value on top
		#pragma omp critical
		{
			open_list.push(current);
			busy[omp_get_thread_num() - 1] = false;
		}
	}
}
