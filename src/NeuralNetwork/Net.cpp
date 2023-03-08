#include <string>

#include "Net.h"



Net::Net(int w, int h, int z, int batch) 
	: input_size{w,h,z,batch}{};

int* Net::get_size(){
    std::cout << "w: " << input_size[0] << "; h: " << input_size[1] << "; z: " << input_size[2] << "; batch: " << input_size[3] << std::endl;
    return input_size;
}

std::vector<Layer*> Net::topology() {
	return network_topology;
}

void Net::add_layer(Layer* layer){
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



