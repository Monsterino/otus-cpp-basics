#include "Game.h"

#include <cstring>

TikTakToe_engine::TikTakToe_engine() 
	:winner{ -2 }
	,player{ 'X' }
	,moves_count{ 9 }
	,state{ 0,0,0,0,0,0,0,0,0} {};

char TikTakToe_engine::get_player(){
	return player;
}

short TikTakToe_engine::get_winner() {
	return winner;
}

int* TikTakToe_engine::get_state() {
	return state;
}

short TikTakToe_engine::get_count_moves() {
	return moves_count;
}

void TikTakToe_engine::change_player() {
	if (player == 'X') {
		player = 'O';
	}
	else
	{
		player = 'X';
	}
}

std::map<int, int*>*  TikTakToe_engine::get_all_states(){
	//std::vector<std::pair<int,short*>> cur_vector;
	int value_player;

	if (player == 'X') { value_player = 1; }
	else { value_player = -1; }

	std::map<int, int*>* states = new std::map<int, int*>;
	for (int i = 0; i < 9; ++i) {
	//	if (*(ptr + i) == 0) {
		if (state[i] == 0) {

			int* current_state = new int[9];
			memcpy(current_state,state,sizeof(state));

			*(current_state + i) = value_player;

			states->insert(std::pair<int, int*>(i, current_state));

		}
			
	
	}
	return states;
}

void TikTakToe_engine::allowed_moves() {
	for (size_t i = 0; i < 9; ++i) {
		int *ptr = get_state();
		if (*(ptr + i) == 0) {
			std::cout << i + 1 << " ";
		}

	}
	std::cout << std::endl;
}

bool TikTakToe_engine::allowed_moves(const short& move) {
	if (this->winner != -2 ) { return false; }
	for (size_t i = 0; i < 9; ++i) {
		int *ptr = get_state();
		if ((*(ptr + i) == 0) && (move == i+1)) {
			return true;
		}
	}
	return false;

}

std::vector<short> TikTakToe_engine::return_winner_positions() {
	std::vector<short> sum;

	for (size_t i = 0; i < 3; ++i) {

		sum.push_back(this->state[0 + 3 * i] + this->state[1 + 3 * i] + this->state[2 + 3 * i]);
		sum.push_back(this->state[0 + i] + this->state[3 + i] + this->state[6 + i]);
	}

	sum.push_back(this->state[0] + this->state[4] + this->state[8]);
	sum.push_back(this->state[2] + this->state[4] + this->state[6]);

	return sum;
}




short TikTakToe_engine::predict_winner() {
	std::vector<short> sum;

	sum = return_winner_positions();
	for (size_t i = 0; sum.size()>i;++i)
	{
		if ((sum[i] == 3) || (sum[i]==-3)){
			std::cout << "Winner is " << int_to_str(sum[i]/3) << std::endl;
			winner = sum[i] / 3;
			return (sum[i]/3);
		}
	}
	if (this->moves_count == 0)
	{
		std::cout << "It's a draw" << std::endl;
		winner = 0;
		return 0;
	}
	else
	{
		return -2;
	}

}

void TikTakToe_engine::make_move(const short& move) {
	if (player == 'X')
	{
		state[move-1] = 1;
	}
	else
	{
		state[move-1] = -1;
	}
	change_player();
	moves_count--;
	predict_winner();
	

}

char TikTakToe_engine::int_to_str(const short& player) {
	char player_char;
	switch (player)
	{
	case -1:
		player_char = 'O';
		break;
	case 0:
		player_char = '-';
		break;
	case 1:
		player_char = 'X';
		break;
	}
	return player_char;
}
std::ostream& operator<<(std::ostream& os, TikTakToe_engine& game) {
	for (size_t i = 0; i < 9; ++i) {
		if (i % 3 == 0) {
			os << std::endl;
		}
		int *ptr = game.get_state();
		os << game.int_to_str(*(ptr + i)) << " ";
	}
	return os;
}

