#include <iostream>
#include "Game.h"
#include "Game_interface.h"
#include "Net.h"
   

int main() {

	//Interface inter;
	//inter.play_game();

	Net net = Net(2,3,4,5);
	net.add_layer(new Layer(5));
	net.add_layer(new Layer(8));
	
	std::cout << net.topology()[0]->get_num_neurons() << " " << net.topology()[1]->get_num_neurons() << std::endl;

	
	net.initialize();



	system("pause");
	return 0;
}