#pragma once


#include "Game.h"
#include "Net.h"
#include "Layer.h"
#include "Activation.h"
#include "Players.h"


class Interface {
	public:
		Interface(std::string mode);
		void play_game();
	private:
		std::string _mode;

};