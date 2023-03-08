#include "Game_interface.h"
#include "Net.h"
#include "Layer.h"
#include "Activation.h"


Interface::Interface(std::string mode):_mode{mode}{}


void Interface::play_game() {
	
	TikTakToe_engine game;
	short move;

	if (_mode == "Vs-player"){
		while (game.get_winner() == -2 && game.get_count_moves() != 0) {

		std::cout << game << std::endl;
		std::cout << "Allow moves: ";
		game.allowed_moves();
		while (std::cout << std::endl << "Make your move" << std::endl && (!(std::cin >> move) || !(game.allowed_moves(move))))
		{
			std::cin.clear();
			std::cout << "Wrong move" << std::endl << "Allowed moves: ";
			game.allowed_moves();
			std::cout << "Try again" << std::endl;
		}

		game.make_move(move);
		if (game.get_winner() != -2) {
			std::cout << game << std::endl;
			break;
		}
		}
	}
	else
	{
		Net net = Net(2,1,1,9);

		net.add_layer(new Dense(64, new FromFile("layer_1_9x64_w.txt"), new FromFile("layer_1_9x64_b.txt")));
		net.add_layer(new Relu());
		net.add_layer(new Dense(32,new FromFile("layer_2_64x32_w.txt"),	new FromFile("layer_2_64x32_b.txt")));
		net.add_layer(new Relu());
		net.add_layer(new Dense(1, new FromFile("layer_3_32x1_w.txt"), new FromFile("layer_3_32x1_b.txt")));
		net.add_layer(new Tanh());
		
		while (game.get_winner() == -2 && game.get_count_moves() != 0) {

			std::cout << game << std::endl;
			std::cout << "Allow moves: ";
			game.allowed_moves();
			while (std::cout << std::endl << "Make your move" << std::endl && (!(std::cin >> move) || !(game.allowed_moves(move)))){
				std::cin.clear();
				std::cout << "Wrong move" << std::endl << "Allowed moves: ";
				game.allowed_moves();
				std::cout << "Try again" << std::endl;
			}

			game.make_move(move);
			if (game.get_winner() != -2) {
				std::cout << game << std::endl;
				break;
			}

			std::vector<std::pair<int,short*>> all_states = game.get_all_states();

			for (size_t i = 0; i < 8; i++)
			{
				for (size_t j = 0; j < 9; j++)
				{
					std::cout << *(all_states[i].second+j) << " ";
				}
				
				std::cout << std::endl;
			}
			




		}


	}
		
	
}