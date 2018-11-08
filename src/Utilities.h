/**
 * Written by Michael Nowicki 2018
 */
#pragma once
#include "Constants.h"

#include <vector>
#include <map>
#include <algorithm>

namespace Utilities
{
    int get_option(char ** begin, char ** end, const std::string&  option)
    {
        char ** itr = std::find(begin, end, option);
        if (itr != end && ++itr != end) {
            return std::stoi(*itr);
        }
        return 0;
    }

    bool option_exists(char** begin, char** end, const std::string& option)
    {
        return std::find(begin, end, option) != end;
    }

    void parse_command_line_options(const int& argc, char* argv[], std::map<std::string, int>& options)
    {
        if (option_exists(argv, argv + argc, "-" + Options::PLANNER))
        {
            options[Options::PLANNER] = get_option(argv, argv + argc, "-" + Options::PLANNER);
        }
        if (option_exists(argv, argv + argc, "-" + Options::HEURISTIC))
        {
            options[Options::HEURISTIC] = get_option(argv, argv + argc, "-" + Options::HEURISTIC);
        }
        if (option_exists(argv, argv + argc, "-" + Options::NUMBER_OF_CORES))
        {
            options[Options::NUMBER_OF_CORES] = get_option(argv, argv + argc, "-" + Options::NUMBER_OF_CORES);
        }
    }

    namespace Parser
    {
        void parse_input_problem(const std::string& problem_file)
        {
            
        }
    }
}
