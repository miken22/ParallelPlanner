#include "IterativeDeepening.h"
#include "Validate.h"
#include <limits>

/*
	Sequential IDA* implementation.

    Written by Michael Nowicki
*/

LiteState IterativeDeepening::get_successor(const Operator& op, const LiteState& assignment) {
	LiteState child = assignment;
	std::vector<Operator::Effect> effect = op.get_effect();
	std::vector<Operator::Effect>::const_iterator eff_it = effect.begin();
	for (; eff_it != effect.end(); eff_it++) {
		Variable *v = eff_it->var;
		int id = v->get_id();
		child[id] = eff_it->after;
	}
	return child;
}

bool IterativeDeepening::find_plan() {

	int init_h = heuristic->calc_h(std::make_shared<LiteState>(initial_state));

	int bound = 0;
	int result = 0;

	// Test beginning heuristic to ensure it is a solvable task.
	if (init_h == std::numeric_limits<int>::max()) {
		std::cout << "Initial estimate assumes unsolvable." << std::endl;
		return false;
	}

	initial_state.set_g(bound);
	initial_state.set_h(init_h);
	bound = init_h;

	std::cout << "Initial heuristic estimate: " << init_h << std::endl;
    timer.start_timing_search();

	while (timer.is_still_valid()) {

		state_space = StateSpace();

		std::shared_ptr<LiteState> root(new LiteState(initial_state));

		state_space.add_initial_state(root);
		nodes_expanded = 0;
		nodes_generated = 0;
		nodes_rejected = 0;
		//std::vector<LiteState> path;
		std::stack<LiteState> path;

		result = dfs_search(initial_state, bound, path, timer);

		if (solved) {
            break;
		}
		else {

            std::cout << "Nodes generated during iteration: " << nodes_generated << std::endl;
            std::cout << "Nodes expanded during iteration: " << nodes_expanded << std::endl;
            std::cout << "Nodes rejected during iteration: " << nodes_rejected << std::endl;

            if (result >= 100000 && Search::protect_goals) {
                std::cout << "Disabling goal protection." << std::endl;
                Search::protect_goals = false;
            } else {
                bound = result;
			}
		}

		state_space.clear();

		std::cout << "Depth reached, adjusting bound to " << bound << std::endl;
	}
    if (!solved) {
		std::cout << "Time limit exceeded." << std::endl;
	}

	return solved;
}

int IterativeDeepening::dfs_search(LiteState& current, int& bound, std::stack<LiteState>& path, Timer& timer) {
	
    if(!timer.is_still_valid()){
        return current.get_g();
    }
	
	// Perform heuristic evaluation
    double startTime = omp_get_wtime();
	int h = heuristic->calc_h(std::make_shared<LiteState>(current));
    heuristic_timer += (omp_get_wtime() - startTime);
    current.set_h(h);

	// Uses stack to trace path through state space
	path.push(current);

	// Bound check
	if (current.get_f() > bound){
        // Remove this state from the back of the vector
		path.pop();
		//path.erase(path.begin() + path.size() - 1);
		nodes_rejected++;
		int f = current.get_f();
		state_space.remove(std::shared_ptr<LiteState>(new LiteState(current)));
		return f;
	}

	if (state_space.state_is_goal(current, goals)){

		timer.stop_timing_search();
		print_steps(path);
		solved = true;

        std::cout << "Nodes generated during search: " << nodes_generated << std::endl;
        std::cout << "Nodes expanded during search: " << nodes_expanded << std::endl;

        std::cout << "Sequential search took " << timer.get_search_time() << " seconds." << std::endl;
        std::cout << "Time spent calculating heuristic: " << heuristic_timer << " seconds." << std::endl;
		
		return current.get_f();
	}

	nodes_expanded++;
	int min = Search::protect_goals;

	const std::vector<Operator>& applicable_operators = get_applicable_ops(current);

	for (std::size_t i = 0; i < applicable_operators.size(); i++) {

		const Operator& op = applicable_operators[i];

		// Generate successor state, set path cost
		LiteState child = get_successor(op, current);
		int new_g = current.get_g() + op.get_cost();
		child.set_g(new_g);

		// Check if state has been visited, if it has check if we have reached it in fewer steps (lower g value)
		if (state_space.child_is_duplicate(std::shared_ptr<LiteState>(new LiteState(child)))) {
			nodes_rejected++;
			continue;
		}

		// Record operator
		int op_id = op.get_num();
		child.set_op_id(op_id);

		nodes_generated++;

        int t = 0;
 		// Explore child node
		t = dfs_search(child, bound, path, timer);
		if (t < min){
			min = t;
		}
		// Get out of recursion when done. 
		if (solved){
			break;
		}
	}
	// We have generated no children that have lead to a solution and are backtracking.
	// Erase node as we backtrack through state space
	path.pop();
	return min;
}

void IterativeDeepening::print_steps(std::stack<LiteState> path){

	// Record of plan
	std::vector<int> op_steps;

	// When we are at the bottom of the stack it is the initial state, we ignore it
	while (path.size() > 1) {
		op_steps.push_back(path.top().get_op_id());
		path.pop();
	}

	// Re-order the steps to trace plan from root to solution
	std::reverse(op_steps.begin(), op_steps.end());

	// Validator
	Validate vp = Validate(operators, op_steps, initial_state, goals);
	vp.try_plan();

	std::cout << "Plan is of length " << op_steps.size() << std::endl;

}

IterativeDeepening::IterativeDeepening(LiteState& init, 
                                       const std::map<Variable *, int>& gs, 
                                       const std::vector<Operator>& ops, 
                                       const std::vector<DTG>& dtg, 
                                       Heuristic* h, 
                                       bool protection)	: Search(init, gs, ops, dtg, h, protection) {
	solved = false;
	nodes_expanded = 0;
	nodes_generated = 0;
	nodes_rejected = 0;
	heuristic_timer = 0;
}
