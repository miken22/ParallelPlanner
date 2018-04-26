#include "Validate.h"

/*
	This class is used to try and run a brute force search for the goal using the operators
	as recorded during the search. If at any point it detects an operator was applied when
	preconditions were not satisfied, or if the result of all operators applied is not the
	goal state then the plan is ruled invalid. Otherwise the plan is deemed to be valid.

	Written by Michael Nowicki

*/

bool Validate::try_plan() {

	int bad_step = -1;
	LiteState assignment = initial_state;

	std::cout << "Trying potential plan:" << std::endl;
	std::cout << "***********************" << std::endl;

	for (std::size_t i = 0; i < op_steps.size(); i++) {
		const Operator& op = ops[op_steps[i]];

		std::cout << op.get_action() << std::endl;
		
		const std::vector<Operator::Precond>& preconditions = op.get_precond();
		for (std::size_t j = 0; j < op.get_precond().size(); j++) {
			Variable *v = preconditions[j].var;
			if (assignment[v->get_id()] != preconditions[j].pre) {
				bad_step = i;
				break;
			}
		}
		if (bad_step != -1) {
			break;
		}

		const std::vector<Operator::Effect>& effects = op.get_effect();
		for (std::size_t j = 0; j < effects.size(); j++) {
			Variable *v = effects[j].var;
			if (effects[j].before != -1) {
				if (assignment[v->get_id()] != effects[j].before) {
					bad_step = i;
					break;
				}
			}
		}
		if (bad_step != -1) {
			break;
		}

		for (std::vector<Operator::Effect>::const_iterator eff_it = effects.begin(); eff_it != effects.end(); eff_it++) {
			Variable *v = eff_it->var;
			int id = v->get_id();
			assignment[id] = eff_it->after;
		}
	}

	if (bad_step == -1) {
		for (std::map<Variable *, int>::const_iterator goal_it = goals.begin(); goal_it != goals.end(); goal_it++) {
			if (goal_it->second != assignment[goal_it->first->get_id()]) {
				bad_step = op_steps.size() + 1;
				break;
			}
		}
	}

	if (bad_step == -1) {
		std::cout << "************************" << std::endl;
		std::cout << "Plan has been validated." << std::endl;
		std::cout << "************************" << std::endl;
		return true;
	}
	else if (bad_step == (op_steps.size() + 1)) {
		std::cout << "***************************************************" << std::endl;
		std::cout << "Something went wrong validating plan at goal state." << std::endl;
		std::cout << "***************************************************" << std::endl;
		return false;
	}
	else{
		std::cout << "*******************************************" << std::endl;
		std::cout << "Plan has been found to be invalid at step " << bad_step << std::endl;
		std::cout << "*******************************************" << std::endl;
		return false;
	}
}
