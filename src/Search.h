/**
	Abstract class for search agents to implement.
	Written by Michael Nowicki
*/
#ifndef SEARCH_H
#define SEARCH_H
#include "LiteState.h"
#include "Heuristic.h"
#include "DTG.h"
#include "Operator.h"
#include "Variable.h"
#include <map>
#include <vector>
#include <iostream>

class Search {

public:

	LiteState initial_state;
	const std::map<Variable *, int> goals;
	const std::vector<Operator> operators;
	const std::vector<DTG> tg;
	Heuristic* heuristic;
	const int K;
	bool protect_goals;

	Search(LiteState& init, 
           const std::map<Variable *, int>& gs, 
           const std::vector<Operator>& ops, 
           const std::vector<DTG>& dtg, 
           Heuristic *h, 
           bool protection) : initial_state(init), goals(gs), operators(ops), tg(dtg), heuristic(h), K(0), protect_goals(protection) { }

	Search(LiteState& init, 
           const std::map<Variable *, int>& gs, 
           const std::vector<Operator>& ops, 
           const std::vector<DTG>& dtg, 
           const int& K, 
           bool protection) : initial_state(init), goals(gs), operators(ops), tg(dtg), K(K), protect_goals(protection) { }

	virtual ~Search(){}

	virtual bool find_plan() = 0;
	virtual bool find_plan(const int& h_choice) = 0;

	virtual bool op_changes_goal(const Operator& op, const LiteState& assignment);

	std::vector<Operator> get_applicable_ops(const LiteState& assignment);
};

#endif
