#include "SuccessorGenerator.h"

bool SuccessorGenerator::op_changes_goal(const Operator& op, const std::vector<int>& assignment) {

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

void SuccessorGenerator::apply_operator(const Operator& op, LiteState& child) {

	int initial_val = 0;
	child.set_g(initial_val);
	child.set_h(initial_val);

	const std::vector<Operator::Effect>& effect = op.get_effect();
	std::vector<Operator::Effect>::const_iterator eff_it = effect.begin();
	for (; eff_it != effect.end(); eff_it++) {
		Variable *v = eff_it->var;
		child[v->get_id()] = eff_it->after;
	}
}

std::shared_ptr<LiteState> SuccessorGenerator::get_successor(std::shared_ptr<LiteState> current_state, const Operator& op) {

	
	// We create a copy of the current state for the successor and then
    // apply the operator to update the values each variable in the child state.
	LiteState child = *current_state;
	apply_operator(op, child);

	int new_g = current_state->get_g() + op.get_cost();
	int op_id = op.get_num();
	child.set_g(new_g);

	child.set_parent(current_state);
	child.set_op_id(op_id);

	return std::make_shared<LiteState>(child);

}
