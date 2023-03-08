#include "Game.h"
#include <algorithm>
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

short* TikTakToe_engine::get_state() {
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

std::vector<std::pair<int,short*>>  TikTakToe_engine::get_all_states(){
	std::vector<std::pair<int,short*>> cur_vector;
	for (int i = 0; i < 9; ++i) {
		short *ptr = get_state();
		if (*(ptr + i) == 0) {
			short cur_value[9];
			std::copy(std::begin(state), std::end(state), std::begin(cur_value));
			if (player == 'X') {cur_value[i] = 1;}
			else {cur_value[i] = -1;}
			std::pair<int,short*> pair;
			pair = std::make_pair(i+1,cur_value); 
			cur_vector.push_back(pair);
		}
			
	
	}
	return cur_vector;
}

void TikTakToe_engine::allowed_moves() {
	for (size_t i = 0; i < 9; ++i) {
		short *ptr = get_state();
		if (*(ptr + i) == 0) {
			std::cout << i + 1 << " ";
		}

	}
	std::cout << std::endl;
}

bool TikTakToe_engine::allowed_moves(const short& move) {
	for (size_t i = 0; i < 9; ++i) {
		short *ptr = get_state();
		if ((*(ptr + i) == 0) && (move == i+1)) {
			return true;
		}
	}
	return false;

}

short TikTakToe_engine::predict_winner() {
	std::vector<short> sum;

	for (size_t i = 0; i < 3; ++i) {
	
		sum.push_back(this->state[0+3*i] + this->state[1+3*i] + this->state[2+3*i]);
		sum.push_back(this->state[0 + i] + this->state[3+i]+ this->state[6+i]);
	}

	sum.push_back(this->state[0] + this->state[4] + this->state[8]);
	sum.push_back(this->state[2] + this->state[4] + this->state[6]);

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
		short *ptr = game.get_state();
		os << game.int_to_str(*(ptr + i)) << " ";
	}
	return os;
}

