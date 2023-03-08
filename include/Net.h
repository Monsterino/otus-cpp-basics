#pragma once
#include <vector>
#include <iostream>
#include "Dense.h"
#include "Layer.h"


class Net {
	public:
		explicit Net(int w = 1, int h = 1, int z = 1, int batch = 1);

		int* get_size();
		void add_layer(Layer* layer);
		std::vector<Layer*> topology();
		
		double* predict(double* input_data);


	private:
		int input_size[4];
		std::vector<Layer*> network_topology;

		


};