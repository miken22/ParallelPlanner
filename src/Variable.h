#ifndef VARIABLE_H
#define VARIABLE_H
#include <vector>
#include <string>

/*
    The Variable class and its necessary structures are based on the Variable implementation
    by Malte Helmert's preprocessor for Fast-Downward (http://www.fast-downward.org).
    
	Written by Michael Nowicki
*/

class Variable{
inline friend bool operator==(const Variable& lhs, const Variable& rhs){
    return lhs.get_id() == rhs.get_id();
}

private:
	// Collection of ancestors used for heuristic caching
    std::vector<int> ancestors;
	// Represents the size of a variables domain
	int values;
	// Indicate if relevant to the task
	bool needed_for_goal;
	// Unique variable id
	int id;
	// Rough level of variable in CG
	int level;
public:
	Variable(int values):
		values(values) {
			needed_for_goal = false;

	}

	~Variable(){}

	void set_id(int val) { id = val; }
	void set_as_needed() { needed_for_goal = true; }
	void add_ancestor(int ancestor){ ancestors.push_back(ancestor); }
	void set_level(int _level) { level = _level; }

    int get_id() const { return id; }
	int get_level() const { return level; }
	int domain_size() const{ return values; }

	//std::vector<int> get_values(){ return values; }
	std::vector<int> get_ancestors() { return ancestors; }

	bool is_needed() const { return needed_for_goal; }	// To indicate if variable is immediate goal variable or has a causal effect on a goal variable

};

#endif
