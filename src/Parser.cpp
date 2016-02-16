#include "Parser.h"

/*
    Written by Michael Nowicki
*/

void read_header(std::istream& str){
	check_marker(str, "begin_version");
	int holder = 0;
	str >> holder;
	if (holder != 3){
		std::cerr << "Unexpected version of of translated problem" << std::endl;
		exit(-1);
	}
	check_marker(str, "end_version");

	check_marker(str, "begin_metric");
	str >> holder;
	if (holder != 0){
		std::cerr << "Currently does not support action costs" << std::endl;
		exit(-1);
	}
	check_marker(str, "end_metric");
}

void check_marker(std::istream& str, std::string marker){
	std::string word;
	str >> word;

	if (word != marker){
		std::cerr << "Unexpected input recieved, terminating program." << std::endl;
		exit(-1);
	}
}

Variable* initialize_variable(std::istream& str){
	check_marker(str, "begin_variable");
	int range, layer;
	std::string name;
	str >> std::ws >> name >> layer >> range >> std::ws;
	// Read through unnecessary info.
	for (std::size_t i = 0; i < range; i++){
		getline(str, name);
	}
	check_marker(str, "end_variable");

	return new Variable(range);
}

void get_variables(std::istream& str, std::vector<Variable *>& variables){
	int var_count = 0;
	str >> var_count;
	variables.reserve(var_count);
	for (int i = 0; i < var_count; i++) {
		variables.push_back(initialize_variable(str));
		variables.back()->set_id(i);
	}
	std::cout << "Variables parsed: " << variables.size() << std::endl;
}
void get_init(std::istream& str, std::vector<Variable *>& variables, LiteState& initial_state){
	check_marker(str, "begin_state");
	initial_state.resize(variables.size());
	for (size_t i = 0; i < variables.size(); i++){
		int assignment = 0;
		str >> assignment;
		initial_state[variables[i]->get_id()] = assignment;
	}
	check_marker(str, "end_state");
	std::cout << "Initial configuration loaded" << std::endl;
}

void get_goal(std::istream& str, std::map<Variable *, int>& goals, const std::vector<Variable *>& variables){
	check_marker(str, "begin_goal");
	int num_goal_facts = 0;
	str >> num_goal_facts;
	for (int i = 0; i < num_goal_facts; i++){
		int var_id;
		int value;
		str >> var_id;
		str >> value;
		goals.insert(std::make_pair(variables[var_id], value));
	}
	check_marker(str, "end_goal");
	std::cout << "Goal configuration loaded" << std::endl;
}

Operator create_operator(std::istream& str, std::vector<Variable *>& variables){

	std::vector<Operator::Precond> preconditions;
	std::vector<Operator::Effect> effects;
	std::string action;
	int cost;

	check_marker(str, "begin_operator");
	str >> std::ws;
	int num_cond = 0; // used to count both pre and post conditions
	getline(str, action);
	str >> num_cond;
	for (int i = 0; i < num_cond; i++){
		int var_id, value;
		str >> var_id >> value;
		preconditions.push_back(Operator::Precond(variables[var_id], value));
	}

	str >> num_cond;
	for (int i = 0; i < num_cond; i++){
		int cond_eff, var_id, pre, post;
		str >> cond_eff >> var_id >> pre >> post;
		effects.push_back(Operator::Effect(variables[var_id], pre, post));
	}

	str >> cost;
	if (cost == 0){
		cost = 1;
	}
	check_marker(str, "end_operator");

	return Operator(action, preconditions, effects, cost);

}

void get_operators(std::istream& str, std::vector<Operator>& operators, std::vector<Variable *>& variables){
	int op_count = 0;
	str >> op_count;
	for (int i = 0; i < op_count; i++){
		Operator op = create_operator(str, variables);
		op.set_num(i);
		operators.push_back(op);
	}
	std::cout << "Operators parsed: " << operators.size() << std::endl;
}

void parse_input(std::istream& str, std::vector<Variable *>& variables, std::map<Variable *, int>& goals,
				 std::vector<Operator>& operators, LiteState& initial_state){

	std::cout << "Beginning to parse SAS+ file:" << std::endl;

	read_header(str);
	get_variables(str, variables);

	int mutex_size = 0;
	str >> mutex_size;
	for (int i = 0; i < mutex_size; i++){
		int group_size = 0;
		check_marker(str, "begin_mutex_group");
		str >> group_size;
		for (int j = 0; j < group_size; j++){
			int v1, v2;
			str >> v1;
			str >> v2;
		}
		check_marker(str, "end_mutex_group");
	}

	get_init(str, variables, initial_state);
	get_goal(str, goals, variables);
	get_operators(str, operators, variables);

	bool num_of_axioms;
	str >> num_of_axioms;
	if (num_of_axioms){
		std::cout << "Currently cannot handle axioms in problem" << std::endl;
		exit(-2);
	}
	str.clear();
}
