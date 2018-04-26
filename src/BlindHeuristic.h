#pragma once
#include "Heuristic.h"
#include "LiteState.h"
#include <vector>

class BlindHeuristic : public Heuristic {

protected:
    int find_path(const int& goal_var, const int& goal_val, std::vector<int>& assignment) { return 0; }

public:
    BlindHeuristic() {}
    ~BlindHeuristic() {}


	inline int calc_h(LiteState& state) { return 0; }
};
