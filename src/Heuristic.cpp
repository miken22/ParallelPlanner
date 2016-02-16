#include "Heuristic.h"

/*	Abstract Base Class that all heuristics implement.

	Written by Michael Nowicki							*/

bool StepComparator(const std::pair<Variable *, int>& p1, const std::pair<Variable *, int>& p2);

Heuristic::Heuristic(const std::vector<DTG> tg, const std::map<Variable *, int> goal, const std::vector<Operator> operators)
				: transition_graphs(tg), goals(goal), ops(operators) { }
                
/**
    To compute the heuristic value of a state we iterate over all variables v such that s*(v) is defined
    and sum the cost of achieving each goal value individually.
*/
int Heuristic::calc_h(std::shared_ptr<LiteState> state){

	int h = 0;
	bool new_entry = true;
	int solved_goals = 0;
	int number_goal = goals.size();
	// Start each search from the current state assignment
	LiteState assignment = *state;

	std::map<Variable *, int>::const_iterator goal_it = goals.begin();
	for (; goal_it != goals.end(); goal_it++) {
		
		Variable *v = goal_it->first;
		const int goal_id = v->get_id();
		const int goal_val = goal_it->second;
		
        int result;
        result = find_path(goal_id, goal_val, assignment);

        if (result == 0) {
            solved_goals++;
        }
        h += result;
	
	}

	return h;
}

// Takes the initial state, tries to order goal variables by number of steps needed to solve each subtask.
/*void Heuristic::find_goal_ordering(const LiteState& initial_state) {

	goal_order.clear();

	std::vector<std::pair<Variable *, int> > step_list;

	std::map<Variable *, int>::const_iterator goal_it = goals.begin();
	for (; goal_it != goals.end(); goal_it++) {

		// Start each search from the current state assignment, needs to be reset each iteration to ignore goal
		// variable interactions to begin with.
		Var_Assignment assignment = initial_state.get_values();

		Variable *v = goal_it->first;
		const int goal_id = v->get_id();
		const int goal_val = goal_it->second;

		// Heuristic estimate for the number of steps needed to solve the subtask
		int steps = find_path(goal_id, goal_val, assignment);
	
		step_list.push_back(std::make_pair(v, steps));
	}

	std::sort(step_list.begin(), step_list.end(), StepComparator);

	for (std::size_t i = 0; i < step_list.size(); i++) {
		goal_order.push_back(step_list[i].first);
	}
	return;
}*/

// Simple comparator to order goal variables
bool StepComparator(const std::pair<Variable *, int>& p1, const std::pair<Variable *, int>& p2){
	return p1.second > p2.second;
}