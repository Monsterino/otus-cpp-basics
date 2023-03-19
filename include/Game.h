#pragma once
#include <vector>
#include <iostream>
#include <map>



class TikTakToe_engine {
	public:
		TikTakToe_engine();

		char get_player(); 
		short get_winner();
		int* get_state();  
		short get_count_moves(); 
		char int_to_str(const short& player);
		void allowed_moves(); 

		bool allowed_moves(const short& move); 

		std::map<int, int*>* get_all_states();
		short predict_winner(); 

		void change_player(); 

		void make_move(const short& move);

		std::vector<short> return_winner_positions();


		friend std::ostream& operator<<(std::ostream& os, TikTakToe_engine& game);

	private:
		short winner;
		char player;
		short moves_count;
		int state[9];


};