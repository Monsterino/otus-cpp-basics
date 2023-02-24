#include "Layer.h"
#include <stdlib.h>



Layer::Layer(int num_neurons) 
	:_num_neurons{ num_neurons }
    ,_num_weights{1} {};

int Layer::get_num_neurons(){
    return _num_neurons;
 
}
int Layer::get_num_output_elements(){
    return _num_output_elements;
}

int Layer::get_num_input_elements(){
    return _num_input_elements;
}

int Layer::get_batch_size(){
    return _batch_size;
}

int Layer::get_num_weights(){
    return _num_weights;
}


void Layer::get_weights(){
    for (size_t i = 0; i < _num_weights; i++)
    {
       std::cout << weights[i] << ' ';
    }
    std::cout << std::endl;
}

void Layer::initialize(const int size[4]){
    for (size_t i = 1; i < 4; i++)
    {
        _num_weights *= size[i];
    }
    _batch_size = size[0];

    _num_input_elements = _num_weights * _batch_size;
    _num_output_elements = _num_neurons * _batch_size;
    _num_weights *=_num_neurons;
    weights = new double[_num_weights];
}

void Layer::initialize(){
    _batch_size  = prev_layer->get_batch_size();
    _num_input_elements = prev_layer->get_num_output_elements();
    _num_output_elements = _num_neurons * _batch_size;
    _num_weights = prev_layer->get_num_output_elements()/_batch_size *_num_neurons;
    
    weights = new double[_num_weights];
}

void Layer::weights_initialization(const int& num_weights){
  //  std::crand
  //  for (size_t i = 0; i < num_weights; i++)
  //  {
        
   // }
    
}