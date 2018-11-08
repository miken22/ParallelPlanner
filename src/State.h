/**
 * Written by Michael Nowicki 2018
 */
#pragma once
#include <vector>
#include <memory>
#include <limits>

class State : public std::vector<int>
{
public:
    
    State() : h(-1), g(-1), op_id(-1) {};

    State(const State& state) : h(state.h), g(state.g), op_id(state.op_id) {}
    
    State operator=(const State& other_state)
    {
        h = other_state.get_h();
        g = other_state.get_g();
        op_id = other_state.get_op_id();
        parent = other_state.get_parent();
		return *this;
    }

	~State() {	}

	std::size_t get_f() const { return g + h; }	// Get f = g + h
	std::size_t get_g() const { return g; }	// get g
	std::size_t get_h() const { return h; }	// get h
	std::size_t get_op_id() const { return op_id; } // get operator id
    std::shared_ptr<State> get_parent() const { return parent; } // get parent state

	void set_h(int& _h) { h = _h; }	// Set h
	void set_g(int& _g) { g = _g; }	// set g
	void set_op_id(int& _op_id) { op_id = _op_id; } // set operator id
    void set_parent(std::shared_ptr<State> _p) { parent = _p; } 

private:
	// Reference to ancestor, used for parallel searches
	std::shared_ptr<State> parent;
	// Heuristic estimate
	std::size_t h;
	// Path cost
	std::size_t g;
	// Reference to operator that got us to the state
    std::size_t op_id;
};