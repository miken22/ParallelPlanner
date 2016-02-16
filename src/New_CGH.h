#ifndef New_CGH_H
#define New_CGH_H

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
class New_CGH : public Heuristic {
	/*
		Vertices are a tuple <source, destination, cost> that also retains a copy of the state of the world
		at the time the source node is reached and has satisfied the preconditions out to the destination.
	*/
	struct Vertex{
		// Source Value, Destination Value
		int from, to, distance, id;
		Var_Assignment local_state;

		Vertex(const int& f, const int& t, const int& d, const int& i) : from(f), to(t), distance(d), id(i){}
		~Vertex(){}

		int get_src() const { return from; }
		int get_dest() const { return to; }
		int get_distance() const { return distance; }
		int get_id() const { return id; }

        void set_local_state(const Var_Assignment& state) { local_state = state; }
		Var_Assignment get_local_state() { return local_state; }
	};

	struct VertexComp{
		bool operator()(const Vertex& a1, const Vertex& a2){
			if (a1.get_distance() > a2.get_distance()){
				return true;
			}
			return false;
		}
	};
private:

	typedef std::priority_queue<Vertex, std::vector<Vertex>, VertexComp> PriorityQueue;

	PriorityQueue fill_queue(const int& goal_var, 
                             Var_Assignment& assignment,
                             Var_Assignment& distances);
                             
	int find_path(const int& goal_var, const int& goal_val, Var_Assignment& assignment);
public:
	New_CGH(std::vector<DTG> tg, std::map<Variable *, int> goal, std::vector<Operator> operators)
            : Heuristic(tg, goal, operators){}
};
#endif
