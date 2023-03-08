#pragma once
#include <vector>
#include <iostream>
#include "Layer.h"
#include "Weights_initializators.h"



class Dense : public Layer {
	public:
		Dense(int num_neurons);
		Dense(int num_neurons, Weight_initializator* bias, Weight_initializator* kernel);


//		virtual int get_num_neurons();
		
		virtual void initialize(const int* size);
		virtual void initialize();

//		virtual void get_weights();
		
//		virtual int get_num_output_elements();
//		virtual int get_num_input_elements();
//		virtual int get_batch_size();
//		virtual int get_num_weights();
//		virtual int* get_dimension_input_size();
//		virtual int* get_dimension_output_size();

		virtual void weights_initialization(Weight_initializator* initializator) override;
		virtual void bias_initialization(Weight_initializator* initializator) override;

//		virtual double* get_output();

		virtual double* predict(const double* input_data) override;
	
	private:
		Weight_initializator* bias_init;
		Weight_initializator* kernel_init;

};
