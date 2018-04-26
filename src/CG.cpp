#include "CG.h"
#include "StrongConComp.h"
#include "Parser.h"
#include "Variable.h"
#include "Operator.h"
#include <iostream>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>

/*
	This class is based on the causal graph heuristic presented in [Hel06] and [Hel04].

    Written by Michael Nowicki
*/
void CG::build_cg() {
	
	// We create arcs in the CG based on the preconditions/effects of the operators in the planning task
	for (std::size_t i = 0; i < operators.size(); i++) {
		const std::vector<Operator::Precond>& precond = operators[i].get_precond();
		// Collection of variables from the preconditions
		std::vector<Variable *> pre_source;
		// Store all required precondition variables for Operator[i]
		for (std::size_t k = 0; k < precond.size(); k++) {
			pre_source.push_back(precond[k].var);
		}

		std::vector<Operator::Effect> effect = operators[i].get_effect();
		// We cycle through the effects, two possible cases:
		//	 Case 1: Add an arc (u,v) if u is a precondition of v
		//	 Case 2: Add arcs (u,v), (v,u) if u and v are both effects.
		for (std::size_t k = 0; k < effect.size(); k++) {
			Variable *dependent_var = effect[k].var;	// Higher in CG hierarchy
			// Case 1:
			for (std::size_t j = 0; j < pre_source.size(); j++) {
				Variable *src = pre_source[j];			// Lower in CG hierarchy
				if (dependent_var != src) {
					Dep_Vars& dependents = cg[src];
					Dep_Vars& ancestors = reverse_cg[dependent_var];
					add_pre_eff_arc(ancestors, dependents, src, dependent_var);
				}
			}
			// Case 2:
			for (std::size_t j = k+1; j < effect.size(); j++) {
				Variable *src = effect[j].var;
				if (dependent_var != src) {
					add_eff_eff_arc(src, dependent_var);
				}
			}
		}
	}
}

void CG::add_pre_eff_arc(Dep_Vars& ancestors, Dep_Vars& dependents, Variable* src, Variable* dependent_var) {
	dependents[dependent_var]++;
	ancestors[src]++;
}

void CG::add_eff_eff_arc(Variable* effect_var_1, Variable* effect_var_2) {
	// Add arc in the first direction:
	Dep_Vars& src1 = cg[effect_var_1];
	Dep_Vars& dep1 = reverse_cg[effect_var_2];
	src1[effect_var_2]++;
	dep1[effect_var_1]++;

	// Other direction:
	Dep_Vars& src2 = cg[effect_var_2];
	Dep_Vars& dep2 = reverse_cg[effect_var_1];
	src2[effect_var_1]++;
	dep2[effect_var_2]++;
}

bool CG::is_acyclic(Sets& graph_components) {
	if (graph_components.size() == variables.size()) {
		return true;
	}
	return false;
}

// Take causal graph and create a simple adjacency list representation to be searched
// for strongly connected components in the graph.
void CG::find_components(Sets& graph_components) {

	std::map<Variable *, int> mapping;
	for (std::size_t i = 0; i < variables.size(); i++) {
		mapping[variables[i]] = i;
	}

	std::vector<std::vector<int> > adjacency_list;
	adjacency_list.resize(variables.size());

	for (Causal_Graph::const_iterator it = cg.begin(); it != cg.end(); it++) {
		Dep_Vars neighbours = it->second;
		int id = mapping[it->first];
		for (Dep_Vars::const_iterator dep_it = neighbours.begin(); dep_it != neighbours.end(); dep_it++) {
			// Get neighbour list, for each variable find its integer mapping, add to parent adjacency list
			adjacency_list[id].push_back(mapping[dep_it->first]);
		}
	}

	// Split into CC's
	StrongConComp scc(adjacency_list);
	std::vector<std::vector<int> > components = scc.find_components();	// Identified using Dijkstra's path-based CC algorithm

	graph_components.clear();
	graph_components.resize(components.size());
	// Convert from integer mapping back to variable references:
	for (std::size_t i = 0; i < components.size(); i++) {
		std::vector<int> component = components[i];
		for (std::size_t j = 0; j < component.size(); j++) {
			graph_components[i].push_back(variables[component[j]]);
		}
	}
}

// This will loop through all goal variables, and flags them, as well as the variables they depend on as "important" to
// the planner
void CG::set_goal_variables() {
	std::map<Variable *, int>::const_iterator g_it;
	for (g_it = goals.begin(); g_it != goals.end(); g_it++) {
		g_it->first->set_as_needed();
		g_it->first->set_level(0);
		important_vars++;
		backtrack_cg(g_it->first, 1);
	}
}

void CG::backtrack_cg(Variable* search_var, int level) {
	Dep_Vars dependents = reverse_cg[search_var];
	for (Dep_Vars::const_iterator dep_it = dependents.begin(); dep_it != dependents.end(); dep_it++) {
		Variable *var = dep_it->first;
		if (!var->is_needed()) {
			var->set_as_needed();
			var->set_level(level);
			important_vars++;
			backtrack_cg(var, level++);
		}
	}
}

void CG::remove_cycles(const Sets& graph_components) {

	for (std::size_t i = 0; i < graph_components.size(); i++) {

		const std::vector<Variable *>& component = graph_components[i];

		if (component.size() == 1) {
			continue;
		}
		// Look at nodes in component and skews the weights if one or more nodes are goal variables,
		// then calls an ordering method to decide how to remove the cycles according to edge weights.
		for (std::size_t j = 0; j < component.size(); j++) {
			
			Variable * cur_var = component[j];
			Dep_Vars dependents = cg[cur_var];

			if (dependents.size() == 0) {
				continue;
			}

			Dep_Vars::const_iterator itr = dependents.begin();
			while (itr != dependents.end()) {
				// Get neighbours of dependent variable, check if it points back to current variable, compare edge weights and remove lowest cost
				Variable* dependent_var = itr->first;
				itr++;

				// If dependent is a goal var skew the edge weights
				if (goals.find(dependent_var) != goals.end()) {
					cg[cur_var][dependent_var] += 2 * operators.size();
					reverse_cg[dependent_var][cur_var] += 2 * operators.size();
				}
			}
		}
		break_component(component);
	}
}

void CG::break_component(const std::vector<Variable *>& component) {

	std::map<Variable *, int> node_weights;

	// Find cumulative weight of each ndoe
	for (std::size_t i = 0; i < component.size(); i++) {
		int weight = 0;
		std::pair<Variable *, int> mapping;	// Map variable to weight in component

		// We trace the ancestors of the ith node in the connected component and sum the weights of the arcs
		const Dep_Vars& rev_cg_dep = reverse_cg[component[i]];
		Dep_Vars::const_iterator it = rev_cg_dep.begin();
		for (; it != rev_cg_dep.end(); it++) {
			// Only add the weight of the ancestors if it is in the connected component
			if (std::find(component.begin(), component.end(), it->first) != component.end()) {
				weight += it->second;
			}
		}

		mapping = std::make_pair(component[i], weight);
		node_weights.insert(mapping);
	}

	std::vector<Variable *> ordering;

	// Iteratively remove them from the map in order of increasing weight
	while (node_weights.size() > 1) {

		int min = 1000000;
		Variable* node;
		std::map<Variable *, int>::const_iterator it = node_weights.begin();
		// Find min node
		for (; it != node_weights.end(); it++) {
			if (it->second < min) {
				min = it->second;
				node = it->first;
			}
		}
		// Set node at lower level
		ordering.push_back(node);

		// Remove cost from node_weights map.
		Dep_Vars arcs = cg[node];
		Dep_Vars::const_iterator arc_it = arcs.begin();

		for (; arc_it != arcs.end(); arc_it++) {
			// Remove cost induced by node in SCC
			if (std::find(component.begin(), component.end(), arc_it->first) != component.end()) {
				// If source of arc has not already been placed at lower level of ordering
				if (std::find(ordering.begin(), ordering.end(), arc_it->first) == ordering.end()) {
					node_weights[arc_it->first] -= arc_it->second;
				}
			}
		}
		node_weights.erase(node);
	}
	// Push last remaining node on ordering
	ordering.push_back(node_weights.begin()->first);

	// Remove arcs from causal graph that violate ordering
	for (std::size_t i = 0; i < ordering.size(); i++) {

		Variable* lower_node = ordering[i];
		Dep_Vars& inward_arcs = reverse_cg[lower_node];

		for (std::size_t j = i + 1; j < ordering.size(); j++) {
			Variable* higher_node = ordering[j];

			// If there is an arc (v, v') that violates the ordering that v < v':
			if (inward_arcs.find(higher_node) != inward_arcs.end()) {
				Dep_Vars& outward_arcs = cg[higher_node];
				outward_arcs.erase(lower_node);	// Delete arc
				inward_arcs.erase(higher_node);
			}
		}
	}
}

// For heuristic cache functions, similar to tracing important variables but instead
// we record every ancestor for a specific goal variable again using a DFS
void CG::trace_ancestors() {
	std::map<Variable *, int>::const_iterator g_it;
	for (g_it = goals.begin(); g_it != goals.end(); g_it++) {
		dfs(g_it->first, g_it->first);
		std::vector<int> ancestors = g_it->first->get_ancestors();
		// Root of backtrack through CG
		std::sort(ancestors.begin(), ancestors.end());
	}
}
// DFS to trace ancestors, takes the goal variable we are recording for, and the current variable we are at
// in the recursive search.
void CG::dfs(Variable* goal_var, Variable* search_var) {
	Dep_Vars dependents = reverse_cg[search_var]; // Get ancestor in CG

	for (Dep_Vars::const_iterator dep_it = dependents.begin(); dep_it != dependents.end(); dep_it++) {
		Variable *var = dep_it->first;
		if (var->is_needed()) {
			std::vector<int> ancestors = goal_var->get_ancestors();
			// If we haven't placed the variable in the set of ancestors we add it
			if (std::find(ancestors.begin(), ancestors.end(), var->get_id()) == ancestors.end()) {
				goal_var->add_ancestor(var->get_id());
			}
			// Continue DFS from ancestors node
			dfs(goal_var, var);
		}
	}
}

void CG::view_cg() {

	std::ofstream cgfile;
	cgfile.open("cg.tgf");

	for(std::size_t i = 0; i < variables.size(); i++) {
		Dep_Vars neighbours = cg[variables[i]];
		Dep_Vars::const_iterator it;
		for(it = neighbours.begin(); it != neighbours.end(); it++) {
			cgfile << variables[i]->get_id() << " " << it->first->get_id() << std::endl;
		}
		cgfile << std::endl;
	}
	cgfile.close();
}


CG::CG(std::vector<Variable *>& variables, std::vector<Operator>& operators, const std::map<Variable *, int>& goals)
	  : variables(variables), operators(operators), goals(goals) {

	// Initialize
	for (std::size_t i = 0; i < variables.size(); i++) {
		cg[variables[i]] = Dep_Vars();
		reverse_cg[variables[i]] = Dep_Vars();
	}

	build_cg();

	// Identify Strongly Connected Components to break cycles in CG
	Sets graph_components;
	CG::find_components(graph_components);
	std::sort(graph_components.begin(), graph_components.end(), OrderSets());

	if (is_acyclic(graph_components)) {
	//	view_cg();
		std::cout << "The causal graph is acyclic, should be poly-time solvable with " << graph_components.size() << " strongly connected components." << std::endl;
	}
	else {
		std::cout << "The graph is cyclic. There are " << graph_components.size() << " strongly connected components in the causal graph." << std::endl;

		while (!is_acyclic(graph_components)) {
			remove_cycles(graph_components);
			graph_components.clear();
			find_components(graph_components);
			sort(graph_components.begin(), graph_components.end(), OrderSets());
		}
		view_cg();
		std::cout << "Cycles removed, there are now " << graph_components.size() << " connected components in the problem." << std::endl;
	}

	/*
	Backtrack through causal graph from goal nodes, if there is a path then the variable may effect reaching the goal and is flagged. If there
	are variables that have no impact on any variables that effect the goal or goals themselves they can be totally ignored.
	*/
	set_goal_variables();

	//trace_ancestors();

}
