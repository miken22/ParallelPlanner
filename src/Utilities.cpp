#include "Utilities.h"


/** Parse command line input */

char* Utilities::GetOption(char ** begin, char ** end, const std::string&  option) {
	char ** itr = std::find(begin, end, option);
	if (itr != end && ++itr != end) {
		return *itr;
	}
	return 0;
}

bool Utilities::OptionExists(char** begin, char** end, const std::string& option) {
	return std::find(begin, end, option) != end;
}

std::vector<int> Utilities::parse_command_line(int argc, char *argv[]) {
	std::vector<int> options;
	options.resize(4, -1);

	if (OptionExists(argv, argv + argc, "-s")) {
		char *c = GetOption(argv, argv + argc, "-s");
		options[0] = *c - 48;
	}
	if (OptionExists(argv, argv + argc, "-h")) {
		char *c = GetOption(argv, argv + argc, "-h");
		options[1] = *c - 48;
	}
	if (OptionExists(argv, argv + argc, "-p")) {
		char *c = GetOption(argv, argv + argc, "-p");
		options[2] = *c - 48;
	}
    if (OptionExists(argv, argv + argc, "-g")) {
        options[3] = 1;
	}
	return options;
}

/** Select search agent */

Search* Utilities::get_search_agent(const int& agent_choice, LiteState& initial_state, const std::map<Variable *, int>& goals,
								const std::vector<Operator>& operators, const std::vector<DTG>& transition_graphs, Heuristic *heuristic, bool protection) {


	switch(agent_choice) {
		case(0) :
            std::cout << "Running sequential A* solver." << std::endl;
            return new Planner(initial_state, goals, operators, transition_graphs, heuristic, protection);	
        case(1):
            std::cout << "Running sequential IDA*." << std::endl;
            return new IterativeDeepening(initial_state, goals, operators, transition_graphs, heuristic, protection);
	}
}

Search* Utilities::get_parallel_search_agent(const int& agent_choice, LiteState& initial_state, const std::map<Variable *, int>& goals,
	const std::vector<Operator>& operators, const std::vector<DTG>& transition_graphs, const int& K, bool protection) {
	
    switch(agent_choice) {
        case(2):
            std::cout << "Running parallel iterative deepening A* implemented with a priority queue and a stack." << std::endl;
            return new PIDA(initial_state, goals, operators, transition_graphs, K, protection);
        case(3):
            std::cout << "Running parallel iterative deepening implemented with two stacks." << std::endl;
            return new ParallelStacksID(initial_state, goals, operators, transition_graphs, K, protection);
    }
}


/** Select heuristic function. */

Heuristic* Utilities::get_heuristic(const int& heuristic_choice, const std::map<Variable *, int>& goals, const std::vector<Operator>& operators,
                                    const std::vector<DTG>& transition_graphs) {
	if (heuristic_choice == 0) {
		return new CGHeuristic(transition_graphs, goals, operators);
	}
	else if (heuristic_choice == 1) {
		return new New_CGH(transition_graphs, goals, operators);
	}
	else if (heuristic_choice == 2) {
		return new CSP_Heuristic(transition_graphs, goals, operators);
	}
	else {
		return new BlindHeuristic();
	}
}

void Utilities::delete_variables(std::vector<Variable *>& variables) {

    for (std::size_t i = 0; i < variables.size(); i++) {
        delete variables[i];
    }
    variables.clear();

}
