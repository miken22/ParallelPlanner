#include "DTG.h"
#include "CG.h"
#include <string>
#include <iostream>


DTG::DTG(const Variable& var){
	vertices.resize(var.domain_size());
}
// Takes the effect being worked on, operator, op id, and the nodes for the transition
void DTG::addEdge(Variable *var, const Operator::Effect& effect, const Operator& op, const int& op_id, const int& from, const int& to, CG& cg){

	// Get causal graph and map of neighbours to variable var, if var does not effect an effect variable
	// then we do not add the condition to the label on the DTG.
	std::map<Variable *, std::map<Variable *, int> > cg_graph = cg.get_causal_graph();

	// Transition says what value becomes, which operator does it
	Rule transition = Rule(to, op_id);
	// Vector stores variables and values that must be true to apply the operator
	Condition& condition = transition.condition;

	const std::vector<Operator::Precond>& prec = op.get_precond();
	for (std::size_t i = 0; i < prec.size(); i++){
		if (cg_graph.at(prec[i].var).find(var) != cg_graph.at(prec[i].var).end()){
			if (prec[i].var->is_needed()) {
				condition.push_back(std::make_pair(prec[i].var, prec[i].pre));
			}
		}
	}
	const std::vector<Operator::Effect>& effect_list = op.get_effect();
	for (std::size_t i = 0; i < effect_list.size(); i++){
		Operator::Effect eff = effect_list[i];
		Variable *eff_var = eff.var;
		if (eff_var->is_needed()) {
			if (eff.before != -1 && eff_var != var){	// Since rules only matter if the variable must be a particular value.
				std::map<Variable *, int> cg_neighbours = cg_graph[eff_var];
				if (cg_neighbours.find(var) != cg_neighbours.end()){
					condition.push_back(std::make_pair(eff_var, eff.before));
				}
			}
		}
	}
	transition.cost = op.get_cost();
	vertices[from].push_back(transition);
}

void build_DTGs(const std::vector<Variable *>& variables, const std::vector<Operator>& operators,
	std::vector<DTG>& transition_graphs, CG& cg){

	std::cout << "Building Domain Transition Graphs...";

	transition_graphs.resize(variables.size());
	// Initialize DTG for each variable:
	for (std::size_t i = 0; i < variables.size(); i++){
		Variable *var = variables[i];
		transition_graphs[var->get_id()] = DTG(*var);
	}

	// Cycle through operators, assigning values to correct DTG:
	for (std::size_t i = 0; i < operators.size(); i++){
		Operator op = operators[i];
        std::vector<Operator::Effect> effects = op.get_effect();

		for (std::size_t k = 0; k < effects.size(); k++){
			Variable *var = effects[k].var;

			if (var->is_needed()){
				//std::cout << "Adding to DTG of " << var->get_name() << std::endl;
				Operator::Effect eff = effects[k];
				int pre_val = eff.before;
				if (pre_val != -1){
					// Case 1 for adding edges in DTGs, v = d -> v = d'
					transition_graphs[var->get_id()].addEdge(var,eff, op, op.get_num(), eff.before, eff.after, cg);
				}
				else {
					// Case 2, v can be anything before changing to v = d', add edge for all other d in Dv to d'
					for (int j = 0; j < var->domain_size(); j++){
						if (j != eff.after){
							transition_graphs[var->get_id()].addEdge(var, eff, op, op.get_num(), j, eff.after, cg);
						}
					}
				}
			}
		}
	}


	/*for (size_t i = 0; i < transition_graphs.size(); i++){
		transition_graphs[i].write_dtgs(i);
	}*/

	std::cout << "complete." << std::endl;
}
/*
void DTG::write_dtgs(const int& i){
    char c = i + 48;
    ofstream dtgfile;
    std::string file_name = (std::string("dtg") + c + std::string(".txt"));
    dtgfile.open(file_name.c_str());

    for (int i = 0; i < vertices.size(); i++) {
        dtgfile << "  From value " << i << ":" << std::endl;
        for (int j = 0; j < vertices[i].size(); j++) {
            const Rule& trans = vertices[i][j];
            dtgfile << "    " << "To value " << trans.value << std::endl;
            for (int k = 0; k < trans.condition.size(); k++)
                dtgfile << "      if " << trans.condition[k].first->get_name() << " = " << trans.condition[k].second << std::endl;
        }
    }
    dtgfile.close();
}
*/
