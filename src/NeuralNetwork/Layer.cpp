#include "Layer.h"
#include <stdlib.h>
#include <stdlib.h>



Layer::Layer() :_num_input_elements{ 1 }
			   ,_num_neurons{ 1 }
			   , _num_weights{ 1 }{};

int Layer::get_num_neurons() {
	return _num_neurons;

}

int Layer::get_num_output_elements() {
	return _num_output_elements;
}

int Layer::get_num_input_elements() {
	return _num_input_elements;
}

int Layer::get_batch_size() {
	return _batch_size;
}

int Layer::get_num_weights() {
	return _num_weights;
}

int* Layer::get_dimension_input_size() {
	return _dimension_input_size;
}

int* Layer::get_dimension_output_size() {
	return _dimension_output_size;
}

double* Layer::get_output() {
	return output_data;
}


void Layer::set_prev(Layer* prev_lr ) {
	prev_layer = prev_lr;
}

void Layer::set_next(Layer* next_lr) {
	prev_layer = next_lr;
}

void Layer::set_name(std::string name_lr) {
	name = name_lr;
}


void Layer::get_weights() {
	std::cout << "Weights:" << std::endl;
	for (int i = 0; i < _num_weights; i++)
	{
		std::cout << weights[i] << ' ';
	}
	std::cout << std::endl;

	std::cout << "Bias:" << std::endl;
	for (int i = 0; i < _num_neurons; i++)
	{
		std::cout << bias[i] << ' ';
	}
	std::cout << std::endl;

}



void Layer::initialize(const int* size) {}

void Layer::initialize() {}

void Layer::weights_initialization(Weight_initializator* initializator) {}
void Layer::bias_initialization(Weight_initializator* initializator) {}

double* Layer::predict(const double* input_data) {return 0;}





