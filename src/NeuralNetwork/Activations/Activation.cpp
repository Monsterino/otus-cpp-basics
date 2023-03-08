#include "Activation.h"
#include <stdlib.h>
#include <cmath>


Relu::Relu() : Layer () {
	_num_input_elements = 0;
	_num_neurons = 0;
	_num_weights = 0;
};


void Relu::initialize(const int* size){
	_batch_size = *(size);

    for (size_t i = 1; i < 4; i++)
    {
		_dimension_input_size[i - 1] = *(size + i);
		_dimension_output_size[i - 1] = *(size + i);
		_num_input_elements *= *(size + i);

    }

	_num_input_elements *= _batch_size;
	
	_num_output_elements = _num_input_elements;

	output_data = new double[_num_output_elements];

}

void Relu::initialize(){

	int* dimension_ptr = prev_layer->get_dimension_output_size();
	for (size_t i = 0; i < 3; i++)
	{
		_dimension_input_size[i] = *(dimension_ptr + i);
		_dimension_output_size[i] = *(dimension_ptr + i);

	}

    _batch_size  = prev_layer->get_batch_size();
    _num_input_elements = prev_layer->get_num_output_elements();
    _num_output_elements = _num_input_elements;
    
	output_data = new double[_num_output_elements];
}



double* Relu::predict(const double* input_data) {
	for (size_t i = 0; i < _num_input_elements; i++)
	{
		input_data[i] > 0 ? output_data[i] = input_data[i] : output_data[i] = 0;
	}

	return output_data;
}





Tanh::Tanh() : Layer() {
	_num_input_elements = 0;
	_num_neurons = 0;
	_num_weights = 0;
};


void Tanh::initialize(const int* size) {
	_batch_size = *(size);

	for (size_t i = 1; i < 4; i++)
	{
		_dimension_input_size[i - 1] = *(size + i);
		_dimension_output_size[i - 1] = *(size + i);
		_num_input_elements *= *(size + i);

	}

	_num_input_elements *= _batch_size;

	_num_output_elements = _num_input_elements;

	output_data = new double[_num_output_elements];

}

void Tanh::initialize() {

	int* dimension_ptr = prev_layer->get_dimension_output_size();
	for (size_t i = 0; i < 3; i++)
	{
		_dimension_input_size[i] = *(dimension_ptr + i);
		_dimension_output_size[i] = *(dimension_ptr + i);

	}

	_batch_size = prev_layer->get_batch_size();
	_num_input_elements = prev_layer->get_num_output_elements();
	_num_output_elements = _num_input_elements;

	output_data = new double[_num_output_elements];
}



double* Tanh::predict(const double* input_data) {
	for (size_t i = 0; i < _num_input_elements; i++)
	{
		output_data[i] = (exp(input_data[i]) - exp(-input_data[i])) / (exp(input_data[i]) + exp(-input_data[i]));
	}
	return output_data;
}


