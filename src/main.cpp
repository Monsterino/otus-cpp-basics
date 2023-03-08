#include <iostream>
#include <string>
#include <algorithm>
#include <filesystem>
#include <vector>

#include "Game.h"
#include "Game_interface.h"
#include "Net.h"
#include "Activation.h"
#include "Layer.h"

namespace fs = std::filesystem;

int main() {



	double tmp[18] = { 0,1,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,1,0 };


	Interface inter("Vs-computer");
	inter.play_game();

//	Net net = Net(2,1,1,9);

/*	net.add_layer(new Dense(64,new Zeros(),new Ones()));
	net.add_layer(new Relu());
	net.add_layer(new Dense(32,new Zeros(),new Ones()));
	net.add_layer(new Relu());
	net.add_layer(new Dense(1,new Zeros(),new Ones()));
	net.add_layer(new Tanh());


	net.add_layer(new Dense(64,
							new FromFile("layer_1_9x64_w.txt"),
							new FromFile("layer_1_9x64_b.txt")));
	net.add_layer(new Relu());
	net.add_layer(new Dense(32,
							new FromFile("layer_2_64x32_w.txt"),
							new FromFile("layer_2_64x32_b.txt")));
	net.add_layer(new Relu());
	net.add_layer(new Dense(1,
							new FromFile("layer_3_32x1_w.txt"),
							new FromFile("layer_3_32x1_b.txt")));
	net.add_layer(new Tanh());


	double* tkm = net.predict(tmp);

	for (size_t i = 0; i < 2; i++)
	{
		std::cout << *(tkm + i) << std::endl;
	}
*/
	//net.topology()[0]->weights_initialization(new Zeros());

	//net.topology()[0]->get_weights();



//	net.add_layer(new Tanh());


	//double* tkm = net.predict(tmp);


	//for (size_t i = 0; i < 4; i++)
	//{
	//	std::cout << *(tkm + i) << std::endl;
	//}



	/*std::vector<fs::path> default_dirs;
	default_dirs.push_back(fs::current_path().parent_path() / "weights");
	
	fs::path cwd = fs::current_path().parent_path() / "weights";

	if (fs::exists(fs::current_path().parent_path() / "weights") || fs::exists(fs::current_path()/ "weights"))
	{
		for (const auto& entry : fs::directory_iterator(cwd))
		{
			std::cout << entry.path() << std::endl;

		}
	}
	else
	{
		std::cout << "Folder weights doesn't exist" << std::endl;

	}
	*/

	system("pause");
	return 0;
}