#include "Dense.h"

#include <vector>
#include <iostream>

namespace Layer {

	Dense::Dense(int num_neurons) :Layers()
	{
		_num_neurons = num_neurons;
		kernel_init = new Initializator::Ones();
		bias_init = new Initializator::Zeros();
	};

	Dense::Dense(int num_neurons, Initializator::Weight_initializator* kernel, Initializator::Weight_initializator* bias) :Layers() {
		_num_neurons = num_neurons;
		kernel ? kernel_init = kernel : kernel_init = new Initializator::Ones();
		bias ? bias_init = bias : bias_init = new Initializator::Zeros();
	};



	void Dense::initialize(const int* size) {

		for (size_t i = 1; i < 4; i++)
		{
			_num_weights *= *(size + i);
			_dimension_input_size[i - 1] = *(size + i);
			_dimension_output_size[i - 1] = *(size + i);

		}

		_batch_size = *(size);
		_num_input_elements = _num_weights * _batch_size;
		_num_output_elements = _num_neurons * _batch_size;
		_num_weights *= _num_neurons;
		_dimension_output_size[2] = _num_neurons;

		weights = new double[_num_weights];
		bias = new double[_num_neurons];
		output_data = new double[_num_output_elements];
		weights_initialization(kernel_init);
		bias_initialization(bias_init);

	}

	void Dense::initialize() {

		int* dimension_ptr = prev_layer->get_dimension_output_size();
		for (size_t i = 0; i < 3; i++)
		{
			_dimension_input_size[i] = *(dimension_ptr + i);
			_dimension_output_size[i] = *(dimension_ptr + i);

		}

		_batch_size = prev_layer->get_batch_size();
		_num_input_elements = prev_layer->get_num_output_elements();
		_num_output_elements = _num_neurons * _batch_size;
		_num_weights = prev_layer->get_num_output_elements() / _batch_size *_num_neurons;
		_dimension_output_size[2] = _num_neurons;


		weights = new double[_num_weights];
		bias = new double[_num_neurons];
		output_data = new double[_num_output_elements];

		weights_initialization(kernel_init);
		bias_initialization(bias_init);

	}

	void Dense::weights_initialization(Initializator::Weight_initializator* initializator) {

		initializator->set_num_weights(_num_weights);
		initializator->initializate_weight(weights);
		if (initializator != kernel_init) {
			delete kernel_init;
			kernel_init = initializator;
		}
	}
	
	void Dense::bias_initialization(Initializator::Weight_initializator* initializator) {
		initializator->set_num_weights(_num_neurons);
		initializator->initializate_weight(bias);

		if (initializator != bias_init) {
			delete bias_init;
			bias_init = initializator;
		}

	}

	double* Dense::predict(const double* input_data) {
		for (int batch = 0; batch < _batch_size; batch++)
		{
			for (int neuron = 0; neuron < _num_neurons; neuron++)
			{
				double output_value = 0;
				for (int input_element = 0; input_element < _dimension_input_size[2]; input_element++)
				{
					output_value += input_data[input_element + _dimension_input_size[2] * batch] * weights[input_element + _dimension_input_size[2] * neuron];
				}

				output_data[neuron + (_num_neurons)*batch] = output_value + bias[neuron];
			}
		}
		return output_data;
	}

}