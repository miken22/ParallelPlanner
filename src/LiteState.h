#pragma once
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <memory>

/*
	State representation for planning tasks. Is an extension of a vector of integers to represent the state,
	maintains a shared_ptr reference to it's parent in the state space, path cost and heuristic estimate.

    Written by Michael Nowicki
*/


class LiteState : public std::vector<int> {

private:
	// Reference to ancestor, used for parallel searches
	std::shared_ptr<LiteState> parent;
	// Heuristic estimate
	std::size_t h;
	// Path cost
	std::size_t g;
	// Reference to operator that got us to the state
	std::size_t op_id;

public:
	
	LiteState() : g(0), h(-1), op_id(0) {	}

	~LiteState() {	}

	std::size_t get_f() const { return g + h; }	// Get f = g + h
	std::size_t get_g() const { return g; }	// get g
	std::size_t get_h() const { return h; }	// get h
	std::size_t get_op_id() const { return op_id; } // get operator id

	void set_h(int& value) { h = value; }	// Set h
	void set_g(int& _g) { g = _g; }	// set g
	void set_op_id(int& opid) { op_id = opid; } // set operator id

	void set_parent(std::shared_ptr<LiteState> _p) { parent = _p; } // set reference to parent state (backwards throught statespace)
	
	std::shared_ptr<LiteState> get_parent() { return parent; } // return reference to parent state

};
