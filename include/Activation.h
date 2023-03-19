#pragma once
#include "Layer.h"

namespace Activation {
	class Relu : public Layers {
	public:
		Relu();
		~Relu();
		
		void initialize(const int* size) override;
		void initialize() override;

		double* predict(const double* input_data) override;

	};


	class Tanh : public Layers {
	public:
		Tanh();
		~Tanh();

		virtual void initialize(const int* size) override;
		virtual void initialize() override;

		virtual double* predict(const double* input_data) override;


	};
}