#include "Search.h"


/** This protects goal variables from being undone when determining the plan. There are domains where
    this function will not allow the task to be solvable, will need to look into.                     */
bool Search::op_changes_goal(const Operator& op, const LiteState& assignment) {

    const std::vector<Operator::Effect>& effects = op.get_effect();
    std::map<Variable *, int>::const_iterator goal_it;

    for (std::size_t i = 0; i < effects.size(); i++) {
		Variable *v = effects[i].var;
        goal_it = goals.find(v);
        if (goal_it != goals.end()) {
            if (goal_it->second == assignment[v->get_id()]) {
                return true;
            }
        }
	}
    return false;
}

std::vector<Operator> Search::get_applicable_ops(const LiteState& assignment) {

	std::vector<Operator> applicable_ops;

	for (std::size_t i = 0; i < operators.size(); i++) {
		
		const Operator& op = operators[i];
		
		if (protect_goals) {
			if (op_changes_goal(op, assignment)) {
				continue;
			}
		}

		if (op.can_be_used(assignment)) {
			applicable_ops.push_back(op);
		}
	}

	return applicable_ops;
}
