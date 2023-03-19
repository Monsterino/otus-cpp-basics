#pragma once

#include "Dense.h"
#include "Layer.h"
#include "Players.h"

#include <vector>

class Net : public Player {
	public:
		explicit Net(int w = 1, int h = 1, int z = 1, int batch = 1);

		int* get_size();
		void add_layer(Layers* layer);
		std::vector<Layers*> topology();
		
		double* predict(double* input_data);

		virtual short choose_move(TikTakToe_engine& game) override;

		~Net();

	private:
		int input_size[4];
		std::vector<Layers*> network_topology;

		


};