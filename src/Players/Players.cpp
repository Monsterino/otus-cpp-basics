#include "Players.h"


Player::Player(){};
short Player::choose_move(TikTakToe_engine& game) { return 0; };


Human :: Human() : Player() {};
short Human::choose_move(TikTakToe_engine& game){
	short move;
	while (std::cout << std::endl << "Make your move" << std::endl && (!(std::cin >> move) || !(game.allowed_moves(move)))){
		std::cin.clear();
		std::cout << "Wrong move" << std::endl << "Allowed moves: ";
		game.allowed_moves();
		std::cout << "Try again" << std::endl;
	}
	return move;

	};
