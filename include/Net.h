#pragma once
#include <vector>
#include <iostream>
#include "Layer.h"


class Net {
	public:
		explicit Net(int w = 1, int h = 1, int z = 1, int batch = 1);

		int* get_size();
		void add_layer(Layer* layer);
		std::vector<Layer*> topology();
		void initialize();

	private:
		int size[4];
		std::vector<Layer*> network_topology;
		


};