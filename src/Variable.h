/**   
 * The Variable class and its necessary structures are based on the Variable implementation
 * by Malte Helmert's preprocessor for Fast-Downward (http://www.fast-downward.org).
 * 
 * Written by Michael Nowicki 2018
 */
#pragma once
#include <vector>
#include <string>

class Variable
{
public:
    Variable() = delete;
	
    Variable(int values) : values(values), needed_for_goal(false) {}
    Variable(const Variable& variable): 
        id(variable.id), level(variable.level), values(variable.values),
        needed_for_goal(variable.needed_for_goal)
    {
        ancestors = std::move(variable.ancestors);
    }

    Variable operator=(const Variable& other)
    {
        id = other.id;
        level = other.level;
        values = other.values,
        needed_for_goal = other.needed_for_goal;
        ancestors = std::move(other.ancestors);
        return *this;
    }

	~Variable()
    {
        ancestors.clear();
    }

	void set_id(int val) { id = val; }
	void set_as_needed() { needed_for_goal = true; }
	void add_ancestor(int ancestor) { ancestors.push_back(ancestor); }
	void set_level(int _level) { level = _level; }

    int get_id() const { return id; }
	int get_level() const { return level; }
	int domain_size() const{ return values; }

	std::vector<int> get_ancestors() { return ancestors; }

    bool is_needed() const { return needed_for_goal; } 


    inline bool operator==(const Variable& other) {
        return id == other.get_id();
    }

private:
	// Unique variable id
	int id;
	// Rough level of variable in CG
    int level;
	// Represents the size of a variables domain
	int values;
	// Indicate if relevant to the task
	bool needed_for_goal;
	// Collection of ancestors used for heuristic caching
    std::vector<int> ancestors;

};