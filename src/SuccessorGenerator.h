#ifndef SUCCESSORGENERATOR_H
#define SUCCESSORGENERATOR_H

#include "LiteState.h"
#include "Operator.h"
#include "StateSpace.h"
#include <vector>
#include <stack>
#include <map>
#include <memory>

class SuccessorGenerator{

	const std::map<Variable *, int> goals;
	bool protect_goals;
	
private:
	bool op_changes_goal(const Operator& op, const std::vector<int>& assignment);

	void apply_operator(const Operator& op, LiteState& child);

public:
	SuccessorGenerator(){}
	SuccessorGenerator(const std::map<Variable *, int> goal, bool protect) : goals(goal), protect_goals(protect) {}
	~SuccessorGenerator(){}

	std::shared_ptr<LiteState> get_successor(std::shared_ptr<LiteState> current_state, const Operator& op);
	
};

#endif