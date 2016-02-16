#ifndef STRONGCONCOMP_H
#define STRONGCONCOMP_H

#include "Variable.h"
#include "Parser.h"
#include "CG.h"
#include <map>
#include <algorithm>
#include <stack>
#include <vector>

/*
	Written by Michael Nowicki
*/


class StrongConComp{
private:
	std::stack<int> unassigned_cc;
	std::stack<int> curr_path;
	std::map<int, int> preorder_map;
	std::vector<int> vars_assigned;
	std::vector<std::vector<int> > graph; // Adjacency list for graph
	std::vector<std::vector<int> > connected_components;
	
	void dfs(const int& index);

public:
	std::vector<std::vector<int> > find_components();
	StrongConComp(const std::vector<std::vector<int> >& graph) : graph(graph) {}
};
#endif
