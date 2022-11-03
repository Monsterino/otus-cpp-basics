#pragma once

#include "statistic.cpp"

#include <limits>

class Max : public IStatistics {
public:
	Max() : m_max{std::numeric_limits<double>::min()} { }

	void update(double next) override {
		if (next > m_max) {
			m_max = next;
		}
	}

	double eval() const override {
		return m_max;
	}

	std::string name() const override {
		return "max";
	}

private:
	double m_max;

};


