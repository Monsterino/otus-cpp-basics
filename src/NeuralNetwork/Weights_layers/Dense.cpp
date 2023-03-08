#include "Dense.h"
#include <stdlib.h>




Dense::Dense(int num_neurons):Layer()
{
	_num_neurons = num_neurons;
	kernel_init = new Ones();
	bias_init = new Zeros();
};

Dense::Dense(int num_neurons, Weight_initializator* kernel, Weight_initializator* bias) :Layer() {
	_num_neurons = num_neurons;
	kernel ? kernel_init = kernel : kernel_init = new Ones();
	bias ? bias_init = bias : bias_init = new Zeros();
};



void Dense::initialize(const int* size){

    for (size_t i = 1; i < 4; i++)
    {
        _num_weights *= *(size+i);
		_dimension_input_size[i - 1] = *(size + i);
		_dimension_output_size[i - 1] = *(size + i);

    }
	
	_batch_size = *(size);
    _num_input_elements = _num_weights * _batch_size;
    _num_output_elements = _num_neurons * _batch_size;
    _num_weights *=_num_neurons;
	_dimension_output_size[2] = _num_neurons;

    weights = new double[_num_weights];
	bias = new double[_num_neurons];
	output_data = new double[_num_output_elements];
	weights_initialization(kernel_init);
	bias_initialization(bias_init);

}

void Dense::initialize(){

	int* dimension_ptr = prev_layer->get_dimension_output_size();
	for (size_t i = 0; i < 3; i++)
	{
		_dimension_input_size[i] = *(dimension_ptr + i);
		_dimension_output_size[i] = *(dimension_ptr + i);

	}

    _batch_size  = prev_layer->get_batch_size();
    _num_input_elements = prev_layer->get_num_output_elements();
    _num_output_elements = _num_neurons * _batch_size;
    _num_weights = prev_layer->get_num_output_elements()/_batch_size *_num_neurons;
	_dimension_output_size[2] = _num_neurons;
	
    
    weights = new double[_num_weights];
	bias = new double[_num_neurons];
	output_data = new double[_num_output_elements];
	weights_initialization(kernel_init);
	bias_initialization(bias_init);

}

void Dense::weights_initialization(Weight_initializator* initializator) {

	initializator->set_num_weights(_num_weights);
	initializator->initializate_weight(weights);
	if (initializator != kernel_init) {
		delete kernel_init;
		kernel_init = initializator;
	}

	
}
void Dense::bias_initialization(Weight_initializator* initializator) {
	
	initializator->set_num_weights(_num_neurons);
	initializator->initializate_weight(bias);

	if (initializator != bias_init) {
		delete bias_init;
		bias_init = initializator;
	}

}

double* Dense::predict(const double* input_data) {
	for (int k = 0; k < _batch_size; k++)
	{
		for (int j = 0; j < _num_neurons; j++)
		{
			double output_value = 0;
			for (size_t i = 0; i < _dimension_input_size[2]; i++)
			{
				//				output_value += *(input_data+(_batch_size*k) + i) *  *(weights+((_dimension_input_size[2]-1) * j + i + j));
				output_value += *((input_data + i + _dimension_input_size[2] *k)) *  weights[(_dimension_input_size[2] - 1) * j + i + j];
			}
			
			output_data[j + (_num_neurons)*k]= output_value +  *(bias+j) ;
			//std::cout << output_data[j + (_num_neurons)*k] << std::endl;
		}
	}
	//std::cout << std::endl;
	return output_data;
}

