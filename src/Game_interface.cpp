#include "Game_interface.h"

Interface::Interface(){}


void Interface::play_game() {
	
	TikTakToe_engine game;
	short move;


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