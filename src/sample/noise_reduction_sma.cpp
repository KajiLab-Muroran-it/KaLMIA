// noise_reduction_sma.cpp
// Removing periodical noises using SMA: Simple Moving Average.

#define _USE_MATH_DEFINES
#include <math.h>

#include <tuple>
#include <vector>
#include <fstream>

#include "filter/KalFIRFactory.hpp"

int main(int argc, char* argv[])
{
	const int k_dim = 10;
	const int k_pts = 1000;
	const double k_step = 10e-3;

	std::vector<std::tuple<double, double, double>> data(k_pts);
	data.clear ();

	auto filter = kalmia::filter::GenerateKalFilterSMA<k_dim> ();
	

	for (int i = 0; i < k_pts; ++i){
		double t = k_step * i;
		double input = sin (t) + 0.1*sin(2*M_PI / (k_step*k_dim) *t);
		filter->Update (input);

		data.push_back (std::make_tuple (t, input, filter->Output()));
		
	}

	std::ofstream ofs ("output.csv");
	ofs << "t, input, output" << std::endl;
	
	for (auto elem : data){
		double t, input, output;
		std::tie (t, input, output) = elem;
		ofs << t << "," << input << "," << output << std::endl;
	}

	return 0;
}

