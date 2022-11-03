#pragma once

#include "statistic.cpp"
#include "mean.cpp"
#include <iostream>
#include <vector>
#include <cmath>

class Std : public IStatistics {
public:
	Std() : sum{ 0 }, counter{ 0 }, std{ 0 } {}
	void update(double next) override {
		counter++;
		numbers.push_back(next);
		mean.update(next);
		for (int i = 0; i < numbers.size(); i++)
		{
			sum += pow(numbers[i] - mean.eval(),2);
		}
		std = sqrt( sum / counter);
		sum = 0;
	}



	double eval() const override {
		return std;
	}

	std::string name() const override {
		return "Std";
	}

private:
	double sum;
	Mean mean;
	int counter;
	double std;
	std::vector<double> numbers;


	
};