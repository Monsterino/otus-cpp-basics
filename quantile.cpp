#pragma once

#include "statistic.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

class Pct : public IStatistics {
public:
	Pct(double percentile) : percentile{ percentile } {}
	
	void update(double next) override {
		elements.push_back(next);
		std::sort(elements.begin(), elements.end());
		if (elements.size() == 1) { pct = next; }
		else{
			low_element_id = std::floor((elements.size() - 1) * percentile / 100);
			high_element_id = std::ceil((elements.size() - 1) * percentile / 100);

			if (low_element_id == high_element_id) { pct = elements[low_element_id]; }
			else {
				pct = (elements[high_element_id] - elements[low_element_id])*(((elements.size() - 1) * percentile / 100) - low_element_id) + elements[low_element_id];
			}
			
		}
		
	}
	
	double eval() const override {
		return pct;
	}

	std::string name() const override {
		std::string str = "Pct" + std::to_string(int(percentile));
		return str;
	}

private:
	double percentile;
	int low_element_id;
	int high_element_id;
	std::vector<double> elements;
	double pct;

};