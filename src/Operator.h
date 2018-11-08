/**
 * Written by Michael Nowicki 2018
 */
#pragma once
#include "Variable.h"
#include "State.h"

#include <vector>
#include <string>

class Operator
{
public:
	struct Precond{
		Variable var;
		int pre;
		Precond(Variable _var, const int& _pre) : var(_var), pre(_pre) {}
	};
	struct Effect{
		Variable var;
		int before;
		int after;	// before is the effect condition, after is the value var must be assigned after applying the operator
		Effect(Variable _var, const int& _before, const int& _after) : var(_var), before(_before), after(_after) {}
	};

    Operator() = delete;

	Operator(const std::string& a, const std::vector<Precond>& pre, const std::vector<Effect>& eff, const int& _cost) :
			 action(a), preconditions(pre), effects(eff), cost(_cost) {}

    Operator(const Operator& _operator) : action(_operator.action), cost(_operator.cost), num(_operator.num)
    {
        preconditions = std::move(_operator.preconditions);
        effects = std::move(_operator.effects);
    }

    Operator operator=(const Operator& _operator)
    {
        action = _operator.action;
        cost = _operator.cost;
        num = _operator.num;
        preconditions = std::move(_operator.preconditions);
        effects = std::move(_operator.effects);
        return *this;
    }

	~Operator() {}

	const std::vector<Precond>& get_precond() const { return preconditions; }
	const std::vector<Effect>& get_effect() const { return effects; }

	std::string get_action() const { return action; }
	std::size_t get_num() const { return num; }
	std::size_t get_cost() const { return cost; }
	
	bool can_be_used(const State& assignment) const;
	
	void set_num(int& n) { num = n; }

private:
	std::string action;
	std::vector<Precond> preconditions;
	std::vector<Effect> effects;
	std::size_t cost;
	std::size_t num;
};