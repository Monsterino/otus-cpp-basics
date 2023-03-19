#include "Utils.h"

#include <filesystem>
#include <vector>


namespace fs = std::filesystem;


int return_winner_line(TikTakToe_engine& game) {
	std::vector<short> positions = game.return_winner_positions();
	int winner_elements;
	for (size_t i = 0; i < positions.size(); i++)
	{
		if ((positions[i] == 3) || (positions[i] == -3))
		{
			winner_elements = i;
			break;
		}

	}

	return winner_elements;
}
