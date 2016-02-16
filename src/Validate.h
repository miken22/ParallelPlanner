#ifndef VALIDATE_H
#define VALIDATE_H
#include "Operator.h"
#include "LiteState.h"

/*
	Written by Michael Nowicki
*/

class Validate{

private:
	const std::vector<Operator> ops;
	const std::vector<int> op_steps;
	LiteState initial_state;
	std::map<Variable *, int> goals;
public:
	Validate(const std::vector<Operator>& _ops, const std::vector<int>& _op_steps, LiteState& ls, const std::map<Variable *, int>& g)
             : ops(_ops), op_steps(_op_steps), initial_state(ls), goals(g) {}

	bool try_plan();
};

#endif
