#include "Weights_initializators.h"

#include <cmath>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Initializator {

	Weight_initializator::Weight_initializator() {};
	void Weight_initializator::initializate_weight(double* weights) {}
	void Weight_initializator::set_num_weights(const int& num_weight) {
		_num_weights = num_weight;
	}

	Ones::Ones() : Weight_initializator() {};
	void Ones::initializate_weight(double* weights) {
		for (int i = 0; i < _num_weights; i++)
		{
			*(weights + i) = 1;
		}
	}

	Zeros::Zeros() : Weight_initializator() {};
	void Zeros::initializate_weight(double* weights) {
		for (int i = 0; i < _num_weights; i++)
		{
			*(weights + i) = 0;
		}
	}

	FromFile::FromFile(fs::path path) : Weight_initializator(), _path{ path }
	{
		std::vector<fs::path> paths = { fs::current_path().parent_path() / "weights" / path,fs::current_path() / "weights" / path, path };

		for (size_t i = 0; i < 3; i++) {
			if (fs::exists(paths[i])) {
				_path = paths[i];
				break;
			}
			else if (i == 2) {
				std::cout << "Файлы весов не найдены" << std::endl;
			}
		}

		std::ifstream inputFile;
		inputFile.open(_path);

		if (!inputFile.is_open())
		{
			std::cout << "Failed to open file" << std::endl;
		}

		std::string line;
		std::istringstream is;
		double weight;

		while (!inputFile.eof())
		{
			std::getline(inputFile, line);
			if (inputFile.good()) {
				is.clear();
				is.str(line);
				while (is >> weight) {
					loaded_weights.push_back(weight);
				}
			}
		}
		inputFile.close();
	};

	void FromFile::initializate_weight(double* weights) {
		for (int i = 0; i < _num_weights; i++)
		{
			*(weights + i) = loaded_weights[i];
		}
	}

}