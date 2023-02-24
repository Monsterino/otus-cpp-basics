#include <iostream>
#include "Game.h"
#include "Game_interface.h"
#include "Net.h"
   

int main() {

	//Interface inter;
	//inter.play_game();

	Net net = Net(2,1,1,9);
	net.add_layer(new Layer(5));
	net.add_layer(new Layer(7));
	
	std::cout << net.topology()[0]->get_num_neurons() << " " << net.topology()[1]->get_num_neurons() << std::endl;




	net.initialize();
	//net.topology()[0]->get_weights(); 
	//net.topology()[1]->get_weights();

	std::cout << net.topology()[0]->get_num_input_elements() << " " << net.topology()[0]->get_num_output_elements() << " " << net.topology()[0]->get_batch_size()<< " " << net.topology()[0]->get_num_weights() <<std::endl;

	std::cout << net.topology()[1]->get_num_input_elements() << " " << net.topology()[1]->get_num_output_elements() << " " << net.topology()[1]->get_batch_size()<< " " << net.topology()[1]->get_num_weights() <<std::endl;

	
	//std::cout << net.topology()[0]->get_num_input_elements() << " " << net.topology()[1]->get_num_output_elements() << std::endl;


	
	

	return 0;
}