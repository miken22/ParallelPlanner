#pragma once
#include "CG.h"
#include "DTG.h"
#include "Heuristic.h"
#include "Operator.h"
#include "Variable.h"
#include "LiteState.h"
#include <vector>
#include <queue>

/*
    Written by Michael Nowicki
*/
class CGHeuristic : public Heuristic {
	struct Node{
		int id;
		int distance;
		Var_Assignment local_state;

		Node(int v, int d) : id(v), distance(d) {}
		~Node() {}

		int get_id() const { return id; }
		int get_distance() const { return distance; }
		void set_distance(int& d) { distance = d; }
		// This is needed to store how the world looks in the abstracted plan.
		void set_local_state(const Var_Assignment& state) { local_state = state; }
		Var_Assignment get_local_state() const { return local_state; }
	};

	struct NodeComp{
		bool operator()(const Node& n1, const Node& n2) {
			return (n1.get_distance() > n2.get_distance());
		}
	};

	typedef std::priority_queue<Node, std::vector<Node>, NodeComp> PriorityQueue;

protected:
	int find_path(const int& goal_var, const int& goal_val, Var_Assignment& assignment);
public:
	CGHeuristic(const std::vector<DTG> tg, const std::map<Variable *, int> goal, const std::vector<Operator> operators)
                : Heuristic(tg, goal, operators) {}
};
