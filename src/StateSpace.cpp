#include "StateSpace.h"
#include <algorithm>

/** This state space class is implemented as a map using the state values (vector of integers)
    as the key and stores the state as the value. This allows for O(lg(n)) search time for
    duplicates, but this could be improved to be more efficient in space usage.

    Written by Michael Nowicki                                                                 */

/** Place the starting state into the state space */
void StateSpace::add_initial_state(std::shared_ptr<LiteState> state){
	state_space.insert(std::make_pair(*state, 0));
}

/** Check if the state is in the state space, if it is we check if the state was reached in fewer steps or not */
bool StateSpace::child_is_duplicate(std::shared_ptr<LiteState> state){

	Graph::iterator graph_it = state_space.find(*state);

	if (graph_it != state_space.end()){	
		// Check if we reached the same state but in fewer steps
		if (state->get_g() < graph_it->second) {
			int h = graph_it->first.get_h();
			state->set_h(h);
			state_space.erase(graph_it);
			state_space.insert(std::make_pair(*state, state->get_g()));
			return false;	// Is duplicate, but found in fewer steps so it could lead to a better solution.
		}
		return true;	// Otherwise we can ignore it
	}
	else {
		state_space.insert(std::make_pair(*state, state->get_g()));
	}
	return false;	// not generated yet
}

/** Work back through state space to find sequence of operators */
std::vector<int> StateSpace::trace_path_from_goal(std::shared_ptr<LiteState> goal_state){

	std::shared_ptr<LiteState> current = goal_state;
	std::vector<int> plan;
	
	while (current->get_g() > 0){
		plan.push_back(current->get_op_id());
		current = current->get_parent();
	}

	std::reverse(plan.begin(), plan.end());
	return plan;
}
/** Goal test */
bool StateSpace::state_is_goal(const LiteState& assignment, const std::map<Variable *, int>& goals){
	for (std::map<Variable *, int>::const_iterator goal_it = goals.begin(); goal_it != goals.end(); goal_it++){
		if (goal_it->second != assignment[goal_it->first->get_id()]){
			return false;
		}
	}
	return true;
}

void StateSpace::remove(std::shared_ptr<LiteState> state){
	Graph::iterator graph_it = state_space.find(*state);
	state_space.erase(graph_it);
}


void StateSpace::clear(){
	state_space.clear();
}

StateSpace::~StateSpace(){
    state_space.clear();
}
