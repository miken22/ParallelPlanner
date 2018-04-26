#pragma once
#include "LiteState.h"
#include "Operator.h"
#include <string>
#include <vector>
#include <map>
#include <memory>

/*
    Written by Michael Nowicki
*/

class StateSpace{
	typedef std::map<LiteState, int> Graph;
	Graph state_space; 
public:
	StateSpace() {}
	~StateSpace();

	void add_initial_state(std::shared_ptr<LiteState> state);
	void remove(std::shared_ptr<LiteState> state);
	void clear();

	bool child_is_duplicate(std::shared_ptr<LiteState> state);
	bool state_is_goal(const LiteState& assignment, const std::map<Variable *, int>& goals);

	std::vector<int> trace_path_from_goal(std::shared_ptr<LiteState> goal_state);
};
