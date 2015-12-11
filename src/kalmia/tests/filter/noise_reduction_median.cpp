#define _USE_MATH_DEFINES
#include <math.h>

#include <memory>
#include <tuple>
#include <vector>
#include <fstream>
#include <random>

#define KALMIA_HEADER_ONLY
#include "kalmia/filter/KalFilterMedian.hpp"

int main ()
{

	std::random_device rd;
	std::mt19937 mt (rd());

	std::normal_distribution<> noise_ampl(0.0, 0.2);
	std::bernoulli_distribution noise_flag (0.25);

	
	const int k_pts = 1000;
	const double k_step = 10e-3;

	const int k_dim = 10;
	auto filter = std::make_unique<kalmia::filter::KalFilterMedian<k_dim>> ();



	std::vector<std::tuple<double, double, double, double>> data;
	data.reserve (k_pts);
	for (int i = 0; i < k_pts; ++i){
		double t = k_step * i;
		double actual = sin (t);
		double input = actual + noise_flag(mt)*noise_ampl (mt);
		filter->Update (input);
		data.push_back (std::make_tuple (t, actual, input, filter->Output ()));
	}

	// Unpack the data and output to csv file.
	std::ofstream ofs ("output.csv");
	ofs << "t, actual, input, output" << std::endl;
	for (const auto&& elem : data){
		double t, actual, input, output;
		std::tie (t, actual, input, output) = elem;
		ofs << t << "," << actual << "," << input << "," << output << std::endl;
	}

	return 0;
}

