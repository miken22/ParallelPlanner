#pragma once
#include "Operator.h"
#include "Variable.h"
#include <vector>
#include <algorithm>

/*
	This class is based on the ideas presented in [Hel04] and [Hel06], and the structures
    used to store the DTG and the pruning techniques are based on the implementation
    by Malte Helmert's preprocessor for Fast-Downward (http://www.fast-downward.org).

	Written by Michael Nowicki
*/

class DTG{
	typedef std::vector<std::pair<Variable *, int> > Condition;
public:
	DTG() {}
	DTG(const Variable& variable);
	struct Rule{
		Condition condition;
		int value;	// Value that the arc leads to (d')
		int op_id;  // Operator index that causes this
		int cost;   // Cost of operator
		Rule(int _value, int op) : value(_value), op_id(op) {}
	};

	std::vector<std::vector<Rule> > vertices;

	void addEdge(Variable *var, const Operator::Effect& effects, const Operator& op, const int& op_id, const int& from, const int& to, CG& cg);

	const std::vector<std::vector<Rule> > get_vertices() const { return vertices; }
	void write_dtgs(const int& i);

};
extern void build_DTGs(const std::vector<Variable *>& variables, const std::vector<Operator>& operators, std::vector<DTG>& transition_graphs, CG& cg);
