#pragma once
#include <Variable.h>
#include <Operator.h>
#include <State.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>


/**
 * Parser is based on the SAS+ parser implemented in FastDownward
 */
class Parser
{
public:

    Parser() {}

    void parse_input_problem(const std::string& problem_file);

private:

    void parse(std::istream&            str, 
               std::vector<Variable>&   variables, 
               std::map<Variable, int>& goals,
               std::vector<Operator>&   operators,
               State&                   initial_state);

    void read_header(std::istream& str);
    void check_marker(std::istream& str, std::string marker);

    Variable initialize_variable(std::istream& str);
    void get_variables(std::istream& str, std::vector<Variable>& variables);
    void get_init(std::istream& str, std::vector<Variable>& variables, State& initial_state);
    void get_goal(std::istream& str, std::map<Variable, int>& goals, const std::vector<Variable>& variables);

    Operator create_operator(std::istream& str, std::vector<Variable>& variables);
    void get_operators(std::istream& str, std::vector<Operator>& operators, std::vector<Variable>& variables);
        
};
