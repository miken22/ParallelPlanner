#include "CGHeuristic.h"
#include <queue>
#include <functional>
#include <limits>

/**
	Will form estimate based on transition costs for d to d' for each node factoring in the label
	leaving d'. This heuristic is based on Malte Helmert's formulation (2004). This is not admissible
	since it does not consider joint action costs (see logistics for simple reason).

    Written by Michael Nowicki
*/
int CGHeuristic::find_path(const int& goal_var, const int& goal_val, Var_Assignment& assignment) {

	// Base case
	if (goal_val == assignment[goal_var]) {
		return 0;
	}

	// Get DTG of variable being solved for
	const std::vector<std::vector<DTG::Rule> >& var_transition_graph = transition_graphs[goal_var].get_vertices();

	PriorityQueue open_list;
	std::vector<int> distances;	// Store list of distances
	distances.resize(var_transition_graph.size(), std::numeric_limits<int>::max());

	int current_value = assignment[goal_var];

	Node n(current_value, 0);
	n.set_local_state(assignment);
	distances[current_value] = 0;

	open_list.push(n);

	// Perform Dijkstra style search on DTG to find path to goal.
	while (!open_list.empty()) {

		Node n = open_list.top();
		int curr_node = n.get_id();
		int distance = n.get_distance();
		Var_Assignment local_state = n.get_local_state();
		
		open_list.pop();
		
		// Since first time we look at goal value in DTG is min path we can return our estimate.
		if (curr_node == goal_val) {
			return distance;
		}

		// Act as control to ignore depricated values
		if (distance <= distances[curr_node]) {

			const std::vector<DTG::Rule>& transition_nodes = var_transition_graph[curr_node];
			
			for (std::size_t i = 0; i < transition_nodes.size(); i++) {

				const DTG::Rule& transition = transition_nodes[i];
				const std::vector<std::pair<Variable *, int> >& conditions = transition.condition;

				if (transition.value == current_value) {
					continue;
				}

				int next_value = transition.value;
				int label_cost = 0;

				/** We update the local state of this node to reflect that these preconditions have
				been satisfied and push the node onto the queue. When the node is removed the
				heuristic performs the necessary computations given that the world state matches
				the preconditions when we are at v'. */

				Var_Assignment new_local_state = local_state;

				if (!conditions.empty()) {
					// Solve each necessary condition recursively
					for (std::size_t j = 0; j < conditions.size(); j++) {
						int pre_var = conditions[j].first->get_id();
						int new_val = conditions[j].second;
                        int path_cost = find_path(pre_var, new_val, local_state);
                        
                        // Set to max if no path could be found, or if we detected no path can be
                        // found when attempting to solve another variable.
                        if (path_cost == std::numeric_limits<int>::max() || label_cost == std::numeric_limits<int>::max()) {
                            label_cost = std::numeric_limits<int>::max();
                        }
                        else {
						  label_cost += path_cost;
                        }
						new_local_state[pre_var] = new_val;
					}
				}
				/** Check the distances array, if the cost, plus labels, plus action are better than current
                    estimate we update. The RHS of the inequality reflects 2(a) from A Planning Heuristic
                    based on Causal Graph Analysis by Malte Hemlert. */
				if (distances[next_value] > distance + label_cost + transition.cost) {
					distances[next_value] = distance + label_cost + transition.cost;
					                   
					Node n = Node(next_value, distances[next_value]);
					n.set_local_state(new_local_state);
					open_list.push(n);
				}
			}
		}
	}
	return std::numeric_limits<int>::max();
}
