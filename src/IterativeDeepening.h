#ifndef ITERATIVEDEEPENING_H
#define ITERATIVEDEEPENING_H
#include "Variable.h"
#include "Operator.h"
#include "New_CGH.h"
#include "Heuristic.h"
#include "CGHeuristic.h"
#include "CSP_Heuristic.h"
#include "StateSpace.h"
#include "Search.h"
#include "LiteState.h"
#include "Timer.h"
#include "CG.h"
#include "DTG.h"
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <climits>

/*
    Written by Michael Nowicki
*/
class IterativeDeepening : public Search {
private:
	StateSpace state_space;
   	Timer timer;

	bool solved;
	int nodes_expanded;
	int nodes_generated;
	int nodes_rejected;
	double heuristic_timer;

	void print_steps(std::stack<LiteState> path);
	int dfs_search(LiteState& current, int& bound, std::stack<LiteState>& path, Timer& timer);

	LiteState get_successor(const Operator& op, const LiteState& assignment);

public:
	IterativeDeepening(LiteState& init, 
                       const std::map<Variable *, int>& gs, 
                       const std::vector<Operator>& ops, 
                       const std::vector<DTG>& dtg, Heuristic* h, 
                       bool protection);

	bool find_plan(const int& h_choice) { return false; }
	bool find_plan();
};

#endif
