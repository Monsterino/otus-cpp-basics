#pragma once
#include "Game.h"


class Player {
	public:
		Player();

		virtual ~Player() = default;
		virtual short choose_move(TikTakToe_engine& game);	

};

class Human : public Player {
	public:
		Human();
		virtual short choose_move(TikTakToe_engine& game) override;
};