#pragma once

#include "statistic.cpp"

class Mean : public IStatistics {
public:
	Mean() : sum{0}, c_elements{0}, mean{0} {}
	
	void update(double next) override {
		c_elements++;
		sum += next;
		mean = sum / c_elements;
	}
	double eval() const override {
		return mean;
	}
	std::string name() const override {
		return "Mean";
	}

private:
	double sum;
	int c_elements;
	double mean;



};