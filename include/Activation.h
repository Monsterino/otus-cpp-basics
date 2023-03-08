#pragma once
#include <vector>
#include <iostream>
#include "Layer.h"



class Relu : public Layer {
	public:
		Relu();

		void initialize(const int* size) override;
		void initialize() override;
				
		double* predict(const double* input_data) override;

};


class Tanh : public Layer {
public:
	Tanh();

	virtual void initialize(const int* size) override;
	virtual void initialize() override;

//	virtual int get_num_output_elements();
//	virtual int get_num_input_elements();
//	virtual int get_batch_size();
//	virtual int* get_dimension_input_size();
//	virtual int* get_dimension_output_size();

	virtual double* predict(const double* input_data) override;


};
