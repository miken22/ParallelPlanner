#ifndef PLANNER_H
#define PLANNER_H

#include "CGHeuristic.h"
#include "New_CGH.h"
#include "CSP_Heuristic.h"
#include "Variable.h"
#include "LiteState.h"
#include "StateSpace.h"
#include "Search.h"
#include "SuccessorGenerator.h"
#include "Operator.h"
#include "Timer.h"
#include "Validate.h"
#include "CG.h"
#include "omp.h"
#include "DTG.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>
#include <ctime>

/*
	Written by Michael Nowicki
*/

class Planner : public Search {
	struct CompareHeuristics{
		CompareHeuristics(){}
		bool operator()(const std::shared_ptr<LiteState>& s1, const std::shared_ptr<LiteState>& s2){
			int f1 = s1->get_f();
			int f2 = s2->get_f();
			if (f1 == f2) {
				const int g1 = s1->get_g();
				const int g2 = s2->get_g();
				return (g1 > g2);
			}
			return f1 > f2;
		}
	};

public:
	Planner(LiteState& init, 
            const std::map<Variable *, int>& gs, 
            const std::vector<Operator>& ops,
            const std::vector<DTG>& dtg, 
            Heuristic *h, 
            bool protection) : Search(init, gs, ops, dtg, h, protection) {}

	bool find_plan(const int& h_choice) { return false; }
	bool find_plan();

};
#endif
