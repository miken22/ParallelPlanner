#include "StrongConComp.h"

/*
	This class implements Dijkstra's Path-Based conneceted component algorithm. The algorithm performs a depth first search
	on each node in the graph, maintaining a record of nodes that have been visited.

	There is a stack S that maintains a record of which nodes have been assigned to a connected component.
	There is a stack P that keeps track of nodes visited that have not been assigned to a connected component.
	There is a count C that keeps track of the number of nodes visited during the DFS.
	There is a vector a that maps each node to -1 until it is assigned to a connected component
	There is a vector p called preorder_map that stores where the vertex was found along the path. These are initially -1 to indicate is has
	not been visited yet.

	The algorithm proceeds as follows:

	For each node v in G(V,E):
		1. Set p[v] = C
		2. Push v onto P and S
		3. For each neighbour w of v:
			if p[w] == -1: recursively search w;
			else if a[v] == -1:
				Keep popping vertices from P until the top vertex u on the stack has p[u] > p[w]
		4. If v is on top of P
			Pop vertices from S until v has been popped and assign them to the same connected component.
			Then pop v from P.

	Written by Michael Nowicki
*/



int ctr = 1;
int cc_number = 0;

std::vector<std::vector<int> > StrongConComp::find_components() {

	vars_assigned.resize(graph.size(),-1);

	for (std::size_t i = 0; i < graph.size(); i++) {
		preorder_map[i] = -1;
	}
	connected_components.resize(graph.size());
	//Surround with a while loop until all nodes are processed

	std::vector<int>::const_iterator it = std::find(vars_assigned.begin(), vars_assigned.end(), -1);

	while (it != vars_assigned.end()) {
		for (std::size_t i = 0; i < graph.size(); i++) {
			if (vars_assigned[i] == -1) {
				dfs(i);
			}
			ctr = 1;
		}
		it = std::find(vars_assigned.begin(), vars_assigned.end(), -1);
	}
	vars_assigned.clear();
	preorder_map.clear();
	connected_components.resize(cc_number);
	cc_number = 0;
	return connected_components;
}

void StrongConComp::dfs(const int& index) {

	// Set preorder value for first node in graph (vertex at location 0 in array)
	preorder_map[index] = ctr;
	ctr++;

	// Push onto stacks S and P
	unassigned_cc.push(index);	// S
	curr_path.push(index);	// P

	for (std::size_t i = 0; i < graph[index].size(); i++) {
		int& neighbour = graph[index][i];
		if (preorder_map[neighbour] == -1) {
			dfs(neighbour);	// Recursive call of neighbours
		}
		else if (vars_assigned[neighbour] == -1) {	// If w has not be assigned to a scc:
			while (preorder_map[curr_path.top()] > preorder_map[neighbour]) {
				curr_path.pop();
			}
		}
	}
	if (curr_path.top() == index) {
		while (!unassigned_cc.empty()) {
			int& comp_part = unassigned_cc.top();
			unassigned_cc.pop();
			connected_components[cc_number].push_back(comp_part);
			vars_assigned[comp_part] = 1;
			if (comp_part == index) {
				curr_path.pop();
                cc_number++;
				break;
			}
		}
	}
}
