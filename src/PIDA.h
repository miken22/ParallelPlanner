#pragma once
#include "Variable.h"
#include "Operator.h"
#include "Heuristic.h"
#include"BucketQueue.h"
#include "New_CGH.h"
#include "Search.h"
#include "SuccessorGenerator.h"
#include "LiteState.h"
#include "Utilities.h"
#include "CG.h"
#include "Timer.h"
#include "DTG.h"
#include <vector>
#include <stack>
#include <queue>
#include <omp.h>
#include <climits>
#include <memory>


/*
	Written by Michael Nowicki
*/

class PIDA : public Search {
// For the open list of the main thread, sort by f value
struct OLComparator{
	bool operator()(const std::shared_ptr<LiteState>& s1, const std::shared_ptr<LiteState>& s2) {
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
private:

	typedef std::stack<std::shared_ptr<LiteState>, std::vector<std::shared_ptr<LiteState>> > Stack;

	// The fringe used by the main thread to expand states
	BucketQueue open_list;
	// The set of generated successors for the other threads to evaluate
	Stack process_list;
	// Simple vector to indicate if one or more threads are active
	std::vector<bool> busy;

	Timer timer;
	// Check that at least one of the lists has a state, or one of the threads is currently processing a successor state
	bool search_is_safe();
	// Main search method
	void parallel_search(bool* solved, bool* killed);
	// Heuristic evaluation method for the N-1 threads.
	void compute_heuristics(Heuristic *heuristic, bool* solved, bool* killed, double& heuristic_timer);
public:
	PIDA(LiteState& init, 
         const std::map<Variable *, int>& gs, 
         const std::vector<Operator>& ops, 
         const std::vector<DTG>& dtg,
         const int& _K, 
         bool protection) : Search(init, gs, ops, dtg, _K, protection) { }
	// Not usable
	bool find_plan() { return false; }
	// Takes an integer representing the heuristic choice and attempts to solve the task using parallel IDA*.
	bool find_plan(const int& h_choice);
};
