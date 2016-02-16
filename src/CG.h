#ifndef CG_H
#define CG_H

#include "Parser.h"
#include "Variable.h"
#include <vector>
#include <map>


/*
	This class is based on the ideas presented in [Hel04] and [Hel06], and the structures
    used to store the causal graph and the pruning techniques are based on the implementation
    by Malte Helmert's preprocessor for Fast-Downward (http://www.fast-downward.org).

	Written by Michael Nowicki
*/

class Variable;
class Operator;

class CG{

struct OrderSets{
	bool operator()(std::vector<Variable *> v1, std::vector<Variable *> v2){
		if (v1.size() == v2.size()) {
			// greater level # implies lower level (larger number => farther from goal)
			if (v1.front()->get_level() > v2.front()->get_level()) {
				return true;
			}
		}
		return v1.size() < v2.size();
	}
};

struct sort_node_weights{
	bool operator()(const std::pair<Variable *, int>& left, const std::pair<Variable *, int>& right){
		return left.second < right.second;
	}
};

	typedef std::vector<std::vector<Variable *> > Sets;
	typedef std::map<Variable *, int> Dep_Vars;	// Collection of outward edges and weights
	typedef std::map<Variable *, Dep_Vars> Causal_Graph;	// Acts as more detailed "adjacency list"
	Causal_Graph cg;
	Causal_Graph reverse_cg;	// Allows searching cg in reverse to find ancestors

	const std::vector<Variable *>& variables;
	const std::vector<Operator>& operators;
	const std::map<Variable *, int>& goals;

	unsigned int important_vars;

private:

	void build_cg(); // Main method to build structures.
	void add_pre_eff_arc(Dep_Vars& ancestors, Dep_Vars& dependents, Variable* src, Variable* dependent_var); // Add edge for case one 
	void add_eff_eff_arc(Variable* effect_var_1, Variable* effect_var_2); // Add edge for case two

	void remove_cycles(const Sets& graph_components);	// Imposes a hierarchical ordering on important variables
	void break_component(const std::vector<Variable *>& component); // If cycles are detected this will greedily remove them
	void find_components(Sets& graph_components);	// Breaks the directed graph into connected components

	void set_goal_variables(); // trace the causal graph, flag goals and relevant ancestors.
	void backtrack_cg(Variable* search_var, int level);	// DFS of ancestor version of Causal Graph to identify important variables

	void trace_ancestors(); // If the heuristic cache is used this traces all ancestors of the goals using a DFS of the reverse CG
	void dfs(Variable* goal_var, Variable* search_var);	// DFS function for above method

	void view_cg(); // Write CG to text file using .tgf format

	std::vector<int> remove_least_edges(std::vector<std::map<Variable *, int> >& induced_graph, std::map<Variable *, int>& mapping); // Remove edges of least weight

public:
	CG(std::vector<Variable *>& variables, std::vector<Operator>& operators, const std::map<Variable *, int>& goals);

	void show_cg(); // Print CG to console

	bool is_acyclic(Sets& graph_components); // Trivial acyclic test

	Causal_Graph get_causal_graph() { return cg; }	// Getter
	Causal_Graph get_reverse_cg() const { return reverse_cg; } // Getter
	
};
#endif
