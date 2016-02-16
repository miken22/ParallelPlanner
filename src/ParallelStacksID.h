#ifndef PARALLELSTACKSID_H
#define PARALLELSTACKSID_H
#include "Variable.h"
#include "Operator.h"
#include "Heuristic.h"
#include "Search.h"
#include "Validate.h"
#include "StateSpace.h"
#include "Timer.h"
#include "SuccessorGenerator.h"
#include "Utilities.h"
#include "LiteState.h"
#include "CG.h"
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

class ParallelStacksID : public Search {
private:

	typedef std::stack<std::shared_ptr<LiteState>, std::vector<std::shared_ptr<LiteState>> > Stack;

	// The main list of states to be expanded, tested for goal state
	Stack open_list;
	// Set of successors for threads to evaluate
	Stack process_list; // This lets us maintain the order in which nodes are generated
	// Vector of booleans to indicate if one or more thread is active.
	std::vector<bool> busy;
	Timer timer;
	// Check that at least one of the lists has a state, or one of the threads is currently processing a successor state
	bool search_is_safe();
	// Main search method
	void parallel_search(bool* solved, bool* killed);
	// Heuristic evaluation method for the N-1 threads.
	void compute_heuristics(Heuristic *heuristic, bool* solved, bool* killed, double& heuristic_timer);
public:
	ParallelStacksID(LiteState& init, 
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

#endif
