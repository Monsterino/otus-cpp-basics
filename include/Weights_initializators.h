#pragma once

#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

namespace Initializator {
	class Weight_initializator {
	public:
		Weight_initializator();

		virtual void initializate_weight(double* weights);
		void set_num_weights(const int& num_weight);
	protected:
		int _num_weights;
	};

	class Ones : public Weight_initializator {
	public:
		Ones();

		virtual void initializate_weight(double* weights) override;

	};

	class Zeros : public Weight_initializator {
	public:
		Zeros();

		virtual void initializate_weight(double* weights) override;

	};

	class FromFile : public Weight_initializator {
	public:
		FromFile(fs::path path);

		virtual void initializate_weight(double* weights) override;
	private:
		fs::path _path;
		std::vector<double> loaded_weights;

	};
}