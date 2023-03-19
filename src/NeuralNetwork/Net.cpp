#include "Net.h"

#include <string>
#include <iostream>

Net::Net(int w, int h, int z, int batch) 
	: Player(), input_size{w,h,z,batch}{};


Net::~Net() {
	for (size_t i = 0; i < network_topology.size(); i++)
	{
		delete network_topology[i];
	}
}

int* Net::get_size(){
    std::cout << "w: " << input_size[0] << "; h: " << input_size[1] << "; z: " << input_size[2] << "; batch: " << input_size[3] << std::endl;
    return input_size;
}

std::vector<Layers*> Net::topology() {
	return network_topology;
}

void Net::add_layer(Layers* layer){
    network_topology.push_back(layer);

	int id_element = network_topology.size() - 1;
	network_topology[id_element]->set_name("Layer_" + std::to_string(id_element));

	if (network_topology.size() > 1) {

		network_topology[id_element]->set_prev(network_topology[id_element - 1]);
		network_topology[id_element - 1]->set_next(network_topology[id_element]);
		network_topology[id_element]->initialize();
	}
	else
	{
		network_topology[0]->initialize(input_size);
	}
}



double* Net::predict(double* input_data) {
	double* data = input_data;

	for (size_t i = 0; i < network_topology.size(); i++)
	{
		data = network_topology[i]->predict(data);

	}
	return data;
}


short Net::choose_move(TikTakToe_engine& game) {
	std::map<int, int*>* all_states = game.get_all_states();

	std::map<int, int*>::iterator states_iterator;

	int index_best_move;
	double best_q_value;

	if (game.get_player() == 'X')
	{
		index_best_move = -1;
		best_q_value = -1;
	}
	else
	{
		index_best_move = 1;
		best_q_value = 1;
	}

	double current_state[9] = { 0,0,0,0,0,0,0,0,0 };

	for (states_iterator = (*all_states).begin(); states_iterator != (*all_states).end(); ++states_iterator) {

		for (size_t i = 0; i < 9; i++)
		{
			current_state[i] = (double) *(states_iterator->second + i);
		}
		double value = *(this->predict(current_state));


		if ((value > best_q_value)&&(game.get_player() == 'X')) {
			best_q_value = value;
			index_best_move = states_iterator->first;
		}

		if ((value < best_q_value) && (game.get_player() == 'O')) {
			best_q_value = value;
			index_best_move = states_iterator->first;
		}

		delete[] states_iterator->second;
	}

	delete all_states;

	return index_best_move + 1;

};

