/**
	Heuristic based on the causal graph using the constraint shortest path problem
	framework for estimating the cost of achieving the goal.

	Written by Michael Nowicki                                                  */
#include "CSP_Heuristic.h"

CSP_Heuristic::PriorityQueue CSP_Heuristic::fill_queue(const int& goal_var, const int& current_value, Var_Assignment assignment) {

   	CSP_Heuristic::PriorityQueue open_list;
   
	std::vector<std::vector<DTG::Rule> > transition_graph = transition_graphs[goal_var].get_vertices();

    for (std::size_t j = 0; j < transition_graph[current_value].size(); j++){
        // Create an adjacency list of the nodes in the graph
        const DTG::Rule& transition = transition_graph[current_value][j];
        int label_cost = 0;
        Var_Assignment local_state = assignment;
        std::vector<std::pair<Variable *, int> > conditions = transition.condition;

        // Recursively solve each label on the arc and sum the results, update the world state to reflect satisfied conditions.
        for (std::size_t k = 0; k < conditions.size(); k++){
            const int& pre_var = conditions[k].first->get_id();
            const int& new_val = conditions[k].second;
            int next_label_cost = find_path(pre_var, new_val, assignment);
            if (next_label_cost == std::numeric_limits<int>::max() || label_cost == std::numeric_limits<int>::max()) {
                label_cost = std::numeric_limits<int>::max();
            } else {
                label_cost += next_label_cost;
            }
            local_state[pre_var] = new_val;     // We want to start with the preconditions being set as satisfied for each arc out of d
		}
		Node n(current_value, j, label_cost, transition.op_id, local_state);
		open_list.push(n);
	}
    return open_list;
}

int CSP_Heuristic::find_path(const int& goal_var, const int& goal_val, Var_Assignment& assignment){

	// Base case
	if (goal_val == assignment[goal_var]){
		return 0;
	}

	// Get DTG for the variable being searched
    const std::vector<std::vector<DTG::Rule> >& transition_graph = transition_graphs[goal_var].get_vertices();
	std::vector<std::vector<int> > distances;
	
	const int& current_value = assignment[goal_var];

	distances.resize(transition_graph.size());
	for (std::size_t i = 0; i < transition_graph.size(); i++) {
		distances[i].resize(transition_graph[i].size(), std::numeric_limits<int>::max());
	}

	// Create structures for search
	PriorityQueue open_list = fill_queue(goal_var, current_value, assignment);

	while (!open_list.empty()) {

		Node best_node = open_list.top();
		open_list.pop();

        int destination = -1;

		const int& source = best_node.get_source();
		const int& transition_id = best_node.get_transition_id();
		const int& op_id = best_node.get_op_id();
		int distance = best_node.get_distance();
		Var_Assignment local_assignment = best_node.get_local_state();

		if (source == goal_val){
		    assignment = local_assignment; // Update world state to reflect reaching the goal
			assignment[goal_var] = goal_val;
            return distance;    // Only handles uniform action costs where transitions have cost 1.
        }

        // Indicates that the node has no outward arcs, since it isn't the goal node then we cannot proceed to
        // another node in the graph so we continue our search.
		if (transition_id < 0){
			continue;
		}

        const Operator& action = ops[op_id];
		destination = transition_graph[source][transition_id].value;

		// Prevent revisitting node/transition pairs again.
		if (distances[source][transition_id] < distance + action.get_cost()){
			continue;
		}

        // We apply the operator to try to capture the effects of the action on other state variables
		const std::vector<Operator::Effect>& effects = action.get_effect();
		for (std::size_t i = 0; i < effects.size(); i++) {
			const int& var_num = effects[i].var->get_id();
			const int& new_val = effects[i].after;
			local_assignment[var_num] = new_val;
		}

		distance += action.get_cost();
		distances[source][transition_id] = distance;

		// If the transition leads us to a goal value we don't care about the state of the world after, so we
		// place the node into the queue with the distance of achieving the goal to ensure we return the minimum
		// cost of achieving the state.
		if (destination == goal_val){
			Node n(destination, -1, distance, -1, local_assignment);
			open_list.push(n);
			continue;
		}

		if (transition_graph[destination].size() == 0){
			// If destination node has no outward arcs we put -1 for operators/transition ID's. When this node is removed it is either the goal
			// in which case we return the distance to that node, or continue as that node leads nowhere useful.
			Node n(destination, -1, distance, -1, local_assignment);
			open_list.push(n);
		}
		else {
            Var_Assignment next_assignment = local_assignment;
			// Iterate through the outward arcs of d' in the DTG
            for (std::size_t i = 0; i < transition_graph[destination].size(); i++) {
				if (transition_graph[destination][i].value == source){
					continue;
				}
                int out_cost = 0;
                const DTG::Rule& transition = transition_graph[destination][i];
                const std::vector<std::pair<Variable *, int> >& conditions = transition.condition;
				// Compute the cost of achieving the preconditions on the arc t out of d'
                for (std::size_t k = 0; k < transition.condition.size(); k++) {
					const int& pre_var = conditions[k].first->get_id();
                    const int& new_val = conditions[k].second;
                    int next_out_cost = find_path(pre_var, new_val, next_assignment);
                    
                    if (next_out_cost == std::numeric_limits<int>::max() || out_cost == std::numeric_limits<int>::max()) {
                        out_cost = std::numeric_limits<int>::max();
                    } 
                    else {
                        out_cost += next_out_cost;   
                    }
                    
                    // Only update the precondition if we know that their is a path to that variables
                    // successive value 
                    if (next_out_cost < std::numeric_limits<int>::max()) {
                        next_assignment[pre_var] = new_val;  
                    }
                    
                }
                
                int next_distance;
                if (out_cost == std::numeric_limits<int>::max()) {
                    next_distance = out_cost;
                }
                else {
                    next_distance = distance + out_cost;
                }
                
                Node node(destination, i, next_distance, transition.op_id, next_assignment);
                open_list.push(node);
            }
		}
	}
	// Failed to reach the goal value, return 'infinite' (arbitrarily large number)
    return std::numeric_limits<int>::max();
}
