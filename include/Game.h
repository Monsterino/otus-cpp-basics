#pragma once
#include <vector>
#include <iostream>


class TikTakToe_engine {
	public:
		TikTakToe_engine();

		char get_player(); 
		short get_winner();
		short* get_state();  
		short get_count_moves(); 
		char int_to_str(const short& player);
		void allowed_moves(); 

		bool allowed_moves(const short& move); 

		std::vector<std::pair<int,short*>> get_all_states();
		short predict_winner(); 

		void change_player(); 

		void make_move(const short& move);


		friend std::ostream& operator<<(std::ostream& os, TikTakToe_engine& game);
	private:
		short winner;
		char player;
		short moves_count;
		short state[9];


};