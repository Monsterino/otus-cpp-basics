#pragma once

#include "Weights_initializators.h"


class Layers {
	public:
		Layers();


		virtual int get_num_neurons();

		virtual ~Layers();


		virtual void initialize(const int* size);
		virtual void initialize();

		virtual void get_weights();


		virtual int get_num_output_elements();
		virtual int get_num_input_elements();
		virtual int get_batch_size();
		virtual int get_num_weights();

		virtual int* get_dimension_input_size();
		virtual int* get_dimension_output_size();

		virtual void weights_initialization(Initializator::Weight_initializator* initializator);
		virtual void bias_initialization(Initializator::Weight_initializator* initializator);

		virtual double* get_output();

		virtual double* predict(const double* input_data);

		void set_prev(Layers* prev_layer);

		void set_next(Layers* next_lr);

		void set_name(std::string name_lr);



	protected:
		Layers* prev_layer;
		Layers* next_layer;
		std::string name;

		int _num_neurons;
		int _num_input_elements;
		int _num_output_elements;
		int _num_weights;
		int _batch_size;
		int _dimension_input_size[3];
		int _dimension_output_size[3];


		double* weights;
		double* bias;
		double* output_data;
	};
