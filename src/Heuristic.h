#pragma once
#include "DTG.h"
#include "LiteState.h"
#include "Operator.h"
#include <map>
#include <vector>

/*
	Written by Michael Nowicki
*/

class Heuristic{
public:
	// States
	typedef std::vector<int> Var_Assignment;
	// The DTG's
	const std::vector<DTG> transition_graphs;
	// The goals
	const std::map<Variable *, int> goals;
	// The actions
	const std::vector<Operator> ops;
	// Test ordering for CSP Heuristic
	std::vector<Variable *> goal_order;

	// To minimize overhead each thread that computes heuristic estimates must have private copies of these data structures
	Heuristic(std::vector<DTG> tg, std::map<Variable *, int> goal, std::vector<Operator> operators);
	Heuristic() {}
	virtual ~Heuristic() {}

	// Solve the path cost for the specified variable, desired value, and local state
    virtual int find_path(const int& goal_var, const int& goal_val, Var_Assignment& assignment) = 0;
	// Compute heuristic value for state.
	virtual int calc_h(std::shared_ptr<LiteState> state);

};
