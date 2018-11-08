/**
 * Main entry point for the parallel planner application. The underlying causal graph heuristic and planner
 * implementation is based on the ideas of Fast-Downward by Malte Helmert.
 * 
 *  Written by Michael Nowicki 2018
 */
#include "Constants.h"
#include "Utilities.h"

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <exception>
#include <signal.h>

void display_usage()
{
    const std::string usage =
        "\nThank you for trying my automated planner. The correct way to start the application is:\n"
        "  ./Biuld/Path/Planner ./Build/Path/tests/test_name.sas -planner (0,1,2,3) -heuristic (0,1,2) [-cores (1,...)]\n\n"
        "The options are as follows:\n"
        "  -planner: Choose between the following options\n"
        "    0 - Sequential A* Planner\n"
        "    1 - Iterative Deepening A* Planner\n"
        "    2 - Parallel A* Planner\n"
        "    3 - Parallel Iterative Deepening A* Planner\n\n"
        "  -heuristic: Choose between the following options\n"
        "    0 - Blind Heuristic\n"
        "    1 - Causal Graph Heuristic\n"
        "    2 - Extended Causal Graph Heuristic\n\n"
        "  -cores: Must be set if using Parallel A* or PIDA* Planners, otherwise ignored\n"
        "    The number entered is the number of cores to be used. If the number is less than one then the default number of cores is used\n\n"
        "Written by Michael Nowicki";
    std::cout << usage << std::endl;
    exit(0);
}

void signal_handler(int signal_id)
 {
	std::cerr << "Caught signal " << signal_id << ". Terminating." << std::endl;
	exit(signal_id);
}

void catch_signal_interupts()
{
	signal(SIGABRT, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGSEGV, signal_handler);
    signal(SIGINT,  signal_handler);
}

void validate_input(const int& argc, char* argv[])
{
    if ((argc < 6 || argc > 8) || Utilities::option_exists(argv, argv + argc, "-h"))
    {
        display_usage();
		exit(-1);
    }
}

void validate_options(const std::map<std::string, int>& options)
{
    if (options.at(Options::PLANNER) == -1 )
    {
        std::cerr << "Invalid planner option selected." << std::endl;
        exit(-1);
    }
    if (options.at(Options::HEURISTIC) == -1)
    {
        std::cerr << "Invalid heuristic type selected." << std::endl;
        exit(-1);
    }
    if ((options.at(Options::PLANNER) == 2 || options.at(Options::PLANNER) == 3) && options.at(Options::NUMBER_OF_CORES) < 2)
    {
        std::cerr << "Number provide a number of cores greater than 1 to run a parallel planners. See -h for usage details." << std::endl;
        exit(-1);
    }
}

int main(int argc, char* argv[])
{
    catch_signal_interupts();
    validate_input(argc, argv);

    std::map<std::string, int> options {
        { Options::PLANNER,         -1 },
        { Options::HEURISTIC,       -1 },
        { Options::NUMBER_OF_CORES, -1 }
    };

    Utilities::parse_command_line_options(argc, argv, options);
    validate_options(options);

    // Parse Problem
    std::string problem_file = argv[1];
    try
    {
        Utilities::Parser::parse_input_problem(problem_file);
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Error while parsing the problem file " << problem_file << ". Exception: " << e.what() << std::endl;
        exit(-1);
    }

    // Construct DTGs

    // Construct CG

    // Get Heuristic Instance

    // Get and start planner

}
