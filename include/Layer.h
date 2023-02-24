#pragma once
#include <vector>
#include <iostream>


class Layer {
	public:
		Layer(int num_neurons);

        int get_num_neurons();
		
		void initialize(const int size[4]);
		void initialize();

		void get_weights();
		
		int get_num_output_elements();
		int get_num_input_elements();
		int get_batch_size();
		int get_num_weights();
		void weights_initialization(const int& num_weights);

	
		Layer* prev_layer;
		Layer* next_layer;
    
	private:
		int _num_neurons;
		int _num_input_elements;
		int _num_output_elements;
		int _num_weights;
		int _batch_size;

		double* weights;
		



};
