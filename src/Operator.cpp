#include "Operator.h"

/*
    Written by Michael Nowicki
*/

bool Operator::can_be_used(const LiteState& assignment) const {

	for (std::size_t i = 0; i < preconditions.size(); i++) {
		Variable *v = preconditions[i].var;
		if (assignment[v->get_id()] != preconditions[i].pre) {
			return false;
		}
	}

	for (std::size_t i = 0; i < effects.size(); i++) {
		Variable *v = effects[i].var;
		if (effects[i].before != -1) {
			if (assignment[v->get_id()] != effects[i].before) {
				return false;
			}
		}
	}

	return true;
}