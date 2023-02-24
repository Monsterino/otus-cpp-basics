#pragma once
#include <vector>
#include <iostream>


class Layer {
	public:
		Layer(int num_neurons);

        int get_num_neurons();
		void initialize(const int size[4]);
		void initialize();

	
		Layer* prev_layer;
		Layer* next_layer;
    
	private:
		int _num_neurons;
		int* weights;



};