#include "Game_interface.h"

#include <vector>
#include <iostream>


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
		Human first_player = Human();

		Net second_player = Net(1, 1, 1, 9);


		second_player.add_layer(new Layer::Dense(64, new  Initializator::FromFile("layer_1_9x64_w.txt"), new  Initializator::FromFile("layer_1_9x64_b.txt")));
		second_player.add_layer(new Activation::Relu());
		second_player.add_layer(new Layer::Dense(32, new  Initializator::FromFile("layer_2_64x32_w.txt"), new  Initializator::FromFile("layer_2_64x32_b.txt")));
		second_player.add_layer(new Activation::Relu());
		second_player.add_layer(new Layer::Dense(1, new  Initializator::FromFile("layer_3_32x1_w.txt"), new Initializator::FromFile("layer_3_32x1_b.txt")));
		second_player.add_layer(new Activation::Tanh());


		while (game.get_winner() == -2 && game.get_count_moves() != 0) {

			short move;

			std::cout << game << std::endl;
			std::cout << "Allow moves: ";
			game.allowed_moves();
			

			move = first_player.choose_move(game);
			game.make_move(move);

			if (game.get_winner() != -2 || game.get_count_moves() == 0)
			{
				std::cout << game << std::endl;
				break;
			}

			move = second_player.choose_move(game);
			game.make_move(move);

			if (game.get_winner() != -2 || game.get_count_moves() == 0)
			{
				std::cout << game << std::endl;
				break;
			}


		}


	}
		
	
}

