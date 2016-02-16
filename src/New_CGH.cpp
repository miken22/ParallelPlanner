/*
    Alternate computation of the causal graph heuristic. Performs the same style search
    using the arcs in the DTG of a variable instead. This focuses on label costs, and
    the cost to satisfy the preconditions out of the destination node.

    Written by Michael Nowicki
*/
#include "New_CGH.h"
#include <ctime>
#include <limits>
#include <algorithm>

/*
	Preprocessing method to populate the priority queue with all arcs (d, d') in the DTG of variable v. If d is the source
	node we compute the cost of satisfying the labels on the arc (if they exist), update the local state to reflect
	the change, and set the arc weight as being the cost of satisfying all preconditions.
*/
New_CGH::PriorityQueue New_CGH::fill_queue(const int& goal_var,
	Var_Assignment& assignment, Var_Assignment& distances) {

	New_CGH::PriorityQueue open_list;

	// Get collection of nodes in variables DTG
	std::vector<std::vector<DTG::Rule> > vertices = transition_graphs[goal_var].get_vertices();

	const int& goal_val = assignment[goal_var];

	// We iterate through the adjacency list the current value of the goal node.
	for (int i = 0; i < vertices[goal_val].size(); i++){
		DTG::Rule& transition = vertices[goal_val][i];
	    std::vector<std::pair<Variable *, int> > conditions = transition.condition;

		// If i is the integer value for the current value of the variable we solve the cost of the labels on the
		// outward arcs
		int label_cost = 0;
		Var_Assignment local_state = assignment;
		// Recursively solve each label on the arc and sum the results, update the world state to reflect satisfied conditions.
		for (std::size_t k = 0; k < conditions.size(); k++){
			int pre_var = conditions[k].first->get_id();
			int new_val = conditions[k].second;
            int path_cost = find_path(pre_var, new_val, assignment);
            
            if (path_cost == std::numeric_limits<int>::max()) {
                label_cost = std::numeric_limits<int>::max();
            }
            else {
			 label_cost += path_cost;
            }
			local_state[pre_var] = new_val;     // We want to start with the preconditions being set as satisfied for each arc out of d
		}
		// We make a node in an abstracted graph representing the pair v,v' with a distance equal to satisfying the preconditions and place on the queue
		// and use i to identify which arc this specific transition represents.
		Vertex arc(goal_val, transition.value, label_cost, i);
		arc.set_local_state(local_state);
		open_list.push(arc);
	}
	return open_list;
}

/*
	Will form estimate based on transition costs for d to d' for each node factoring in the label
	leaving d'. This formulation is an attempt to improve upon the current CG Heuristic.
*/
int New_CGH::find_path(const int& goal_var, const int& goal_val, Var_Assignment& assignment){

	if (goal_val == assignment[goal_var]){
		return 0;
	}

	// Adjacency list representing the DTG for the goal variable.
	std::vector<std::vector<DTG::Rule> > vertices = transition_graphs[goal_var].get_vertices();

	New_CGH::PriorityQueue open_list;
	Var_Assignment distances;	// Store list of distances

	distances.resize(vertices.size(), 100000);
	distances[assignment[goal_var]] = 0;

	// Populate priority queue with initial distances to each node in domain
	open_list = fill_queue(goal_var, assignment, distances);

	// Perform modified Dijkstra search on DTG to find path to goal.
	while (!open_list.empty()){

		Vertex vertex = open_list.top();
		open_list.pop();

		const int& src_node = vertex.get_src();	// v
		const int& dest_node = vertex.get_dest();	// v'
		const int& dist = vertex.get_distance();	// cost to satisfy preconditions of vertex
		const int& arc_id = vertex.get_id();		// This way we can identify which vertex specifically was taken from v, v' as there may be multiple.

        Var_Assignment local_state = vertex.get_local_state();  // We get the state of the world as it exists up to this point

		if (src_node == goal_val){
			return dist;
		}

		// Test if we hit a node with no outward transitions, return the cost if it's the goal or continue otherwise.
		if (arc_id < 0){
			if (src_node == goal_val){
				return dist + 1;
			}
			continue;
		}
		
		DTG::Rule& transition = vertices[src_node][arc_id];

		// If the cost of satisfying preconditions and transition cost is better than current distance we update
		if (distances[dest_node] > dist + transition.cost){

			if (dest_node == goal_val){
				Vertex n(dest_node, -1, dist + transition.cost, -1);
				open_list.push(n);
				continue;
			}

			// Update state of temporary world state of abstract problem, this traces the DTG of each variable
			// and precondition, setting them accordingly so that the calculation for the next step is based on
			// how the world appears given the variable has the value v' and satisfied the preconditions of the
			// specific arc.
			local_state[goal_var] = dest_node;
			for (std::size_t i = 0; i < transition.condition.size(); i++){
				const int& pre_var = transition.condition[i].first->get_id();
				const int& new_val = transition.condition[i].second;
				local_state[pre_var] = new_val;
			}

			// Set the distance of reaching v' = label cost + arc cost
			distances[dest_node] = dist + transition.cost;

			// No outward arcs, create a node to represent getting to that value
			if (vertices[dest_node].size() == 0){
				Vertex n(dest_node, -1, distances[dest_node], -1);
				n.set_local_state(local_state);
				open_list.push(n);
				continue;
			}

			// Now we cycle through the outward edges of v', make a new pair v',v''
			for (int j = 0; j < vertices[dest_node].size(); j++){

				DTG::Rule& out_tran = vertices[dest_node][j];
                std::vector<std::pair<Variable *, int> > conditions = out_tran.condition;

				// Skip cycles since the distance is greater than the shortest path there already.
				if (out_tran.value == src_node){
					continue;
				}

				/** We solve the label cost out of v'' and add the cost of reaching v' and make that the distance
                    of (v',v''). Uses the same method as when the priority queue was initialized above. */
				int label_cost = 0;
				for (std::size_t k = 0; k < out_tran.condition.size(); k++){
					// Recursively solve the labels using the updated temporary world state.
                    const int& pre_var = out_tran.condition[k].first->get_id();
                    const int& new_val = out_tran.condition[k].second;
                    int path_cost = find_path(pre_var, new_val, local_state);
                    
					if (path_cost == std::numeric_limits<int>::max() || label_cost == std::numeric_limits<int>::max()) {
                        label_cost = std::numeric_limits<int>::max();
                    } 
                    else {
                        label_cost += path_cost;
                    }
                }

				// Add the cost of reaching v' to the cost of each outward arc
                if (label_cost != std::numeric_limits<int>::max()) {
				    label_cost += distances[dest_node];
                } 
				Vertex n(dest_node, out_tran.value, label_cost, j);
				n.set_local_state(local_state);
				open_list.push(n);
			}
		}
	}
	return distances[goal_val];
}
