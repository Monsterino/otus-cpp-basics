#include "Layer.h"

#include <vector>
#include <iostream>


	Layers::Layers() :_num_input_elements{ 1 }
		, _num_neurons{ 1 }
	, _num_weights{ 1 } {};

	Layers::~Layers() {
		delete[] weights;
		delete[] bias;
		delete[] output_data;
	}

	int Layers::get_num_neurons() {
		return _num_neurons;

	}

	int Layers::get_num_output_elements() {
		return _num_output_elements;
	}

	int Layers::get_num_input_elements() {
		return _num_input_elements;
	}

	int Layers::get_batch_size() {
		return _batch_size;
	}

	int Layers::get_num_weights() {
		return _num_weights;
	}

	int* Layers::get_dimension_input_size() {
		return _dimension_input_size;
	}

	int* Layers::get_dimension_output_size() {
		return _dimension_output_size;
	}

	double* Layers::get_output() {
		return output_data;
	}


	void Layers::set_prev(Layers* prev_lr) {
		prev_layer = prev_lr;
	}

	void Layers::set_next(Layers* next_lr) {
		prev_layer = next_lr;
	}

	void Layers::set_name(std::string name_lr) {
		name = name_lr;
	}


	void Layers::get_weights() {
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



	void Layers::initialize(const int* size) {}

	void Layers::initialize() {}

	void Layers::weights_initialization(Initializator::Weight_initializator* initializator) {}
	void Layers::bias_initialization(Initializator::Weight_initializator* initializator) {}

	double* Layers::predict(const double* input_data) { return 0; }





