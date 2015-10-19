// noise_reduction_sma.cpp
// Removing periodical noises using SMA: Simple Moving Average.

#define _USE_MATH_DEFINES
#include <math.h>

#include <tuple>
#include <vector>
#include <fstream>

#define KALMIA_HEADER_ONLY
#include "filter/KalFIRFactory.hpp"

int main (int argc, char* argv[])
{
	const int k_pts = 1000;
	const double k_step = 10e-3;

	// Create SMA: Simple Moving Average filter. Where k_dim is length of SMA .
	// Note that k_dim must be a constant of integer (literal, define macro, or compile-time constant).
	// If you're willing to remove some noise and know its period, then following equation gives k_dim:
	//
	//    k_dim = (period of noise) / (period of filter input)
	//
	// The period of filter input should be timestep when you use this filter in simulation-loop.
	// ================================
	const int k_dim = 10;
	auto filter = kalmia::filter::GenerateKalFilterSMA<k_dim> ();

	// The vector to store data which records three doubles for time, input, and output.
	// The number of data points is known(k_points), so acquire enough space on memory first (to do things faster).
	std::vector<std::tuple<double, double, double>> data;
	data.reserve (k_pts);

	// Calculate and sotre records.
	for (int i = 0; i < k_pts; ++i){
		double t = k_step * i;
		double input = sin (t) + 0.1*sin (2 * M_PI / (k_step*k_dim) *t);
		filter->Update (input);
		data.push_back (std::make_tuple (t, input, filter->Output ()));
	}

	// Unpack the data and output to csv file.
	std::ofstream ofs ("output.csv");
	ofs << "t, input, output" << std::endl;
	for (auto elem : data){
		double t, input, output;
		std::tie (t, input, output) = elem;
		ofs << t << "," << input << "," << output << std::endl;
	}

	return 0;
}

