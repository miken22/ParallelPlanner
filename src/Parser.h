#pragma once
#include "Variable.h"
#include "Operator.h"
#include "LiteState.h"
#include "CG.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>


/*
    This parser is based off the Parser written by Malte Helmert for Fast-Downward's
    preprocessor (http://www.fast-downward.org).
    
    Written by Michael Nowicki
*/

void read_header(std::istream& str);
void check_marker(std::istream& str, std::string marker);

Variable* initialize_variable(std::istream& str);
void get_variables(std::istream& str, std::vector<Variable *>& variables);

void get_init(std::istream& str, std::vector<Variable *>& variables, LiteState& initial_state);
void get_goal(std::istream& str, std::map<Variable *, int>& goals, const std::vector<Variable *>& variables);

Operator create_operator(std::istream& str, std::vector<Variable *>& variables);
void get_operators(std::istream& str, std::vector<Operator>& operators, std::vector<Variable *>& variables);

void parse_input(std::istream& str, std::vector<Variable *>& variables, std::map<Variable *, int>& goals,
				 std::vector<Operator>& operators, LiteState& initial_state);
