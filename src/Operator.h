#pragma once
#include <vector>
#include "Variable.h"
#include "Parser.h"
#include "LiteState.h"

/*
    The operator and its necessary structures are based on the Operator implementation
    by Malte Helmert's preprocessor for Fast-Downward (http://www.fast-downward.org).
    
    Written by Michael Nowicki
*/

class Variable;

class Operator {
public:
	struct Precond{
		Variable *var;
		int pre;
		Precond(Variable *_var, const int& val) : var(_var), pre(val) {}
	};
	struct Effect{
		Variable *var;
		int before;
		int after;	// before is the effect condition, after is the value var must be assigned after applying the operator
		Effect(Variable *_var, const int& bef, const int& aft) : var(_var), before(bef), after(aft) {}
	};
private:
	std::string action;
	std::vector<Precond> preconditions;
	std::vector<Effect> effects;
	std::size_t cost;
	std::size_t num;

public:
	Operator(const std::string& a, const std::vector<Precond>& pre, const std::vector<Effect>& eff, const int& c) :
			 action(a), preconditions(pre), effects(eff), cost(c) {}
	~Operator() {}

	const std::vector<Precond>& get_precond() const { return preconditions; }
	const std::vector<Effect>& get_effect() const { return effects; }

	std::string get_action() const { return action; }
	std::size_t get_num() const { return num; }
	std::size_t get_cost() const { return cost; }
	
	bool can_be_used(const LiteState& assignment) const;
	
	void set_num(int& n) { num = n; }
};
