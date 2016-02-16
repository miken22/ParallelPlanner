/**
    Written by Michael Nowicki
*/
#ifndef CSP_HEURISTIC_H
#define CSP_HEURISTIC_H
#include "Heuristic.h"
#include "CG.h"
#include "DTG.h"
#include "Operator.h"
#include "Variable.h"
#include "LiteState.h"
#include <vector>
#include <ctime>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

class CSP_Heuristic : public Heuristic{

	struct Node{
		std::size_t id;
		std::size_t transition_id;
		std::size_t distance;
		std::size_t op_id;
		Var_Assignment local_state;

		Node(int v, int tid, int d, int op, Var_Assignment& state) : id(v), transition_id(tid) ,distance(d), op_id(op), local_state(state) {}
		~Node(){}

		int get_source() const { return id; }
		int get_transition_id() const { return transition_id; }
		int get_op_id() const { return op_id; }
		int get_distance() const { return distance; }
		void set_distance(int& d) { distance = d; }
        Var_Assignment get_local_state() const { return local_state; }
	};

	struct NodeComp{
		bool operator()(const Node& n1, const Node& n2){
			return (n1.get_distance() > n2.get_distance());
		}
	};

	// Type for priority queue for ease of reading.
	typedef std::priority_queue<CSP_Heuristic::Node, std::vector<CSP_Heuristic::Node>, CSP_Heuristic::NodeComp> PriorityQueue;

private:
	CSP_Heuristic::PriorityQueue fill_queue(const int& goal_var, const int& current_value, Var_Assignment assignment);
	int find_path(const int& goal_var, const int& goal_val, Var_Assignment& assignment);
public:
	CSP_Heuristic(std::vector<DTG> tg, std::map<Variable *, int> goal, std::vector<Operator> operators)
                    : Heuristic(tg, goal, operators){}
};

#endif
