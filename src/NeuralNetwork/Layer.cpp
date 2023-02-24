#include "Layer.h"

Layer::Layer(int num_neurons) 
	:_num_neurons{ num_neurons } {};

int Layer::get_num_neurons(){
    return _num_neurons;
 
}

void Layer::initialize(const int size[4]){
    int num_elements = 1;
    for (size_t i = 0; i < 4; i++)
    {
        num_elements *= size[i];
    }
    
}

void Layer::initialize(){

}