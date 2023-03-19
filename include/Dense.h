#pragma once

#include "Layer.h"
#include "Weights_initializators.h"


namespace Layer {
	class Dense : public Layers {
	public:
		Dense(int num_neurons);
		Dense(int num_neurons, Initializator::Weight_initializator* bias, Initializator::Weight_initializator* kernel);

		virtual void initialize(const int* size);
		virtual void initialize();

		virtual void weights_initialization(Initializator::Weight_initializator* initializator) override;
		virtual void bias_initialization(Initializator::Weight_initializator* initializator) override;

		virtual double* predict(const double* input_data) override;

	private:
		Initializator::Weight_initializator* bias_init;
		Initializator::Weight_initializator* kernel_init;

	};
}