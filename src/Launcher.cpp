#include "Parser.h"
#include "Heuristic.h"
#include "Utilities.h"
#include "Search.h"
#include "Variable.h"
#include "Operator.h"
#include "CG.h"
#include "DTG.h"
#include "LiteState.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <omp.h>
#include <fstream>
#include <string>
#include <math.h>
#include <signal.h>

/*
    Written by Michael Nowicki
*/
int K;

void signal_handler(int signal_id);

int main(int argc, char *argv[]) {

	// Catch system signals.
	signal(SIGABRT, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGSEGV, signal_handler);
	signal(SIGINT, signal_handler);;

	std::vector<int> options;

	int plan_choice = -1;
	int heuristic_choice = -1;
	K = -1;
	bool use_cache = false;
	bool protect_goals = false;

	if (argc == 1) {
		std::cout << "Not enough parameters provided." << std::endl;
		exit(-1);
	}

	options = Utilities::parse_command_line(argc, argv);

	/* Handle Command Line options*/
	if (options[0] > 4 || options[0] < 0) {
		std::cout << "Invalid plan selected, using sequential IDA*." << std::endl;
		plan_choice = 0;
	}
	else{
		plan_choice = options[0];
	}

	if (options[1] > 3 || options[1] < 0) {
		std::cout << "Invalid heuristic selected, using the blind heuristic." << std::endl;
		heuristic_choice = 3;
	}
	else{
		heuristic_choice = options[1];
	}

	if (plan_choice > 1) {
        int num_proc = omp_get_num_procs();
		if (options[2] < 1) {
			std::cout << "Invalid number of cores selected for multiprocessor search, setting to " << omp_get_num_procs() << std::endl;
			K = omp_get_num_procs();
		}
		else {
			K = (int)pow(2,options[2]);
		}
	}
	if (options[3] == 1) {
        protect_goals = true;
	}


	/* Parse SAS+ file and create causal structures needed for planning */

	std::vector<Variable *> variables;
	std::vector<Operator> operators;
	std::map<Variable *, int> goals;
	std::vector<DTG> transition_graphs;

	Heuristic* heuristic;
	Search* agent;
	LiteState initial_state;
	
	clock_t startTime = clock();
	std::filebuf fb;

	if (fb.open(argv[1], std::ios::in)) {
		std::istream problem(&fb);
		// Handle SAS+ file
		parse_input(problem, variables, goals, operators, initial_state);
	}
	else {
		std::cout << "Problem loading input file." << std::endl;
		exit(-1);
	}
	fb.close();

	// Create causal graph
	CG causal_graph = CG(variables, operators, goals);
	// Create domain transition graphs
	build_DTGs(variables, operators, transition_graphs, causal_graph);
	double duration = (clock() - startTime) / (double)CLOCKS_PER_SEC;
	std::cout << "Finished parsing and creating causal structures in " << duration << " seconds." << std::endl;

	switch (heuristic_choice) {
		case(0) :
			std::cout << "Using the original Causal Graph Heuristic." << std::endl;
			break;
		case(1) :
			std::cout << "Using the Constraint Causal Graph Heuristic." << std::endl;
			break;
		case(2) :
			std::cout << "Using the Constrained Causal Graph Heuristic with Actions." << std::endl;
			break;
		default :
			std::cout << "Using a blind heuristic." << std::endl;
	}

	std::cout << "Using goal protection: " << Utilities::bool_to_str(protect_goals) << std:: endl;
    if (protect_goals) {
        std::cout << "Using goal protection may result in solvable tasks being rendered unsolvable" << std::endl;
    }

	/*  The main search  */

	bool solved = false;

	// Initialize sequential search agent and heuristic function; begin search.
	if (plan_choice <= 1) {
		heuristic = Utilities::get_heuristic(heuristic_choice, goals, operators, transition_graphs);
		agent = Utilities::get_search_agent(plan_choice, initial_state, goals, operators, transition_graphs, heuristic, protect_goals);
		// Search
		solved = agent->find_plan();
		// Clean up
		delete heuristic;
		delete agent;
	}
	// Initialize parallel search agent; begin search.
	else {	
		std::cout << "Running parallel search with " << K << " threads." << std::endl;
		agent = Utilities::get_parallel_search_agent(plan_choice, initial_state, goals, operators, transition_graphs, K, protect_goals);
		solved = agent->find_plan(heuristic_choice);
		delete agent;
	}
	// Free all allocated memory
    Utilities::delete_variables(variables);

	if (!solved) {
		std::cout << "No plan could be found for this problem." << std::endl;
	}
	return 0;
}

void signal_handler(int signal_id) {
	std::cout << "Caught signal " << signal_id << ". Terminating." << std::endl;
	exit(signal_id);
}
