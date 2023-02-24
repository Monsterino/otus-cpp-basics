#include "Net.h"



Net::Net(int w, int h, int z, int batch) 
	: size{w,h,z,batch}{};

int* Net::get_size(){
    std::cout << "w: " << size[0] << "; h: " << size[1] << "; z: " << size[2] << "; batch: " << size[3] << std::endl;
    return size; 
}

void Net::add_layer(Layer* layer){
    network_topology.push_back(layer);
}

std::vector<Layer*> Net::topology(){
    return network_topology;
}


void Net::initialize(){
    network_topology[0]->initialize(size);

    for (size_t i = 1; i < network_topology.size(); i++)
    {
        network_topology[i]->prev_layer = network_topology[i-1];
        network_topology[i-1]->next_layer = network_topology[i];
        network_topology[i]->initialize();
    }
}
