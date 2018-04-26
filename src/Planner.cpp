/*
	A* state space search algorithm.

    Written by Michael Nowicki
*/
#include "Planner.h"
#include "BucketQueue.h"
#include <memory>
#include <iostream>
#include <limits>

bool Planner::find_plan() {

	SuccessorGenerator successor_generator(goals, Search::protect_goals);
	Timer timer;

	int nodes_expanded = 0;
	int nodes_generated = 0;
	double heuristic_time = 0;

	int g = 0;
	int init_h = heuristic->calc_h(std::make_shared<LiteState>(initial_state));
	int best_f = init_h;
	int best_h = std::numeric_limits<int>::max();

	if (init_h == std::numeric_limits<int>::max()) {
		std::cout << "Initial estimate assumes unsolvable." << std::endl;
		return false;
	}

	initial_state.set_h(init_h);
	initial_state.set_g(g);

	std::cout << "Initial heuristic estimate: " << init_h << std::endl;

	timer.start_timing_search();

	nodes_expanded = 0;
	nodes_generated = 0;

	StateSpace state_space;
	BucketQueue open_list;

	std::shared_ptr<LiteState> root(std::make_shared<LiteState>(initial_state));

	state_space.add_initial_state(root);

	open_list.push(root);

	while (!open_list.empty() && timer.is_still_valid()) {

		std::shared_ptr<LiteState> current = open_list.top();
		open_list.pop();

		if (current->get_f() > best_f) {
            std::cout << "New f value: " << current->get_f() << std::endl;
            best_f = current->get_f();
		}
		else if (current->get_h() < best_h) {
            std::cout << "New best h value: " << current->get_h() 
					  << " [Current path cost: " << current->get_g() 
					  << "]" << std::endl;
            best_h = current->get_h();
		}

		if (state_space.state_is_goal(*current, goals)) {

			timer.stop_timing_search();

			/** While technically the algorithm should return a plan for the task we extend it a bit
				further by validating the plan and returning whether or not the plan is valid. */
			// Get the sequence of operators that lead to this goal state
			std::vector<int> plan = state_space.trace_path_from_goal(current);
			// Verify that the sequence is valid
			Validate vp(operators, plan, initial_state, goals);
			bool solved = vp.try_plan();
			// General information
			std::cout << "Nodes generated during search: " << nodes_generated << std::endl;
			std::cout << "Nodes expanded during search: " << nodes_expanded << std::endl;

			std::cout << "Sequential search took " << timer.get_search_time() << " seconds." << std::endl;
			std::cout << "Time spent calculating heuristic: " << heuristic_time << " seconds." << std::endl;
			std::cout << "Plan is of length " << plan.size() << std::endl;
            
			return solved;
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

			if (child->get_h() == 0) {
				// Delayed heuristic evaluation, set to parents h value
				int h = heuristic->calc_h(child);
				child->set_h(h);
			}
			else {
				int q = 0;
			}
			
			child->set_parent(current);

			nodes_generated++;

			open_list.push(child);

		}
	}

	state_space.clear();

	std::cout << "Time limit exceeded." << std::endl;
	std::cout << "Nodes generated during search: " << nodes_generated << std::endl;
	std::cout << "Nodes expanded during search: " << nodes_expanded << std::endl;
	
	return false;
}
