#pragma once
#include <vector>
#include <iostream>


class TikTakToe_engine {
	public:
		TikTakToe_engine();

		char get_player();    // Узнать, какой игрок сейчас ходит
		short get_winner();   // Узнать, есть ли победитель	
		short* get_state();   // Получить текущее состояние игрового поля
		short get_count_moves();  // Получить количество пустых ячеек
		char int_to_str(const short& player);
		void allowed_moves(); // Показать возможные ходы

		bool allowed_moves(const short& move);  // Проверить, возможно ли сделать данный ход
		short predict_winner(); // Предсказать победителя

		void change_player(); // Сменить игрока

		void make_move(const short& move);


		friend std::ostream& operator<<(std::ostream& os, TikTakToe_engine& game);
	private:
		short winner;
		char player;
		short moves_count;
		short state[9];


};