/**
		Utility class to select the search agent and heuristic. Handles command line parsing.

		Written by Michael Nowicki
*/
#ifndef UTILITIES_H
#define UTILITIES_H
#include "CG.h"
#include "Search.h"
#include "Planner.h"
#include "Heuristic.h"
#include "BlindHeuristic.h"
#include "LiteState.h"
#include "DTG.h"
#include "IterativeDeepening.h"
#include "ParallelStacksID.h"
#include "PIDA.h"
#include <vector>
#include <map>

class Utilities{
private:
	// Read cmd line, check if flag can be found.
	static bool OptionExists(char** begin, char** end, const std::string& option);
	// Get the character after the flag.
	static char* GetOption(char ** begin, char ** end, const std::string&  option);

public:

	static std::vector<int> parse_command_line(int argc, char *argv[]);

	/* For sequential search */
	static Search* get_search_agent(const int& agent_choice, 
                                    LiteState& initial_state, 
                                    const std::map<Variable *, int>& goals,
		                            const std::vector<Operator>& operators, 
                                    const std::vector<DTG>& transition_graphs, 
                                    Heuristic *heuristic, 
                                    bool protection);
	/* For parallel search */
	static Search* get_parallel_search_agent(const int& agent_choice, 
                                             LiteState& initial_state, 
                                             const std::map<Variable *, int>& goals,
		                                     const std::vector<Operator>& operators, 
                                             const std::vector<DTG>& transition_graphs, 
                                             const int& K, 
                                             bool protection);
	// Get heuristic function for search.
	static Heuristic* get_heuristic(const int& heuristic_choice, 
                                    const std::map<Variable *, int>& goals,
                                    const std::vector<Operator>& operators,
                                    const std::vector<DTG>& transition_graphs);

	// Delete variables for the MPT
	static void delete_variables(std::vector<Variable *>& variables);

	// Convert booleans to strings
	inline const static std::string bool_to_str(bool b) { return b ? "true" :"false"; }

	// Generic clear method for priority queues and stacks
	template <class ContainerAdaptor>
	static void clear(ContainerAdaptor& container) {
		while (!container.empty()) {
			container.pop();
		}
	}

};


#endif
