#pragma once

#include "Game.h"
#include <vector>
#include <iostream>



class Interface {
	public:
		Interface(std::string mode);
		void play_game();
	private:
		std::string _mode;

};