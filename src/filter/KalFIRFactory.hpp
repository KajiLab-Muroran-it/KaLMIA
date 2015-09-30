/**************************************************************/
/*                                                            */
/*     ================[ KaLMIA Library ]================     */
/*                                                            */
/*           Kaji-Lab Moderate Instrumental Assets            */
/*                                                            */
/*     ============== " Be Ambitious For " ==============     */
/*                                                            */
/*              Muroran Institute of Technology               */
/*      Electronic System Control Engineering Laboratory      */
/*                                                            */
/**************************************************************/

// KalFIRFactory.hpp
// Set of pre-defined FIR filter generators.

// Sample
/*
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <vector>
#include "filter/KalFilterFIR.hpp"
#include "filter/KalFIRFactory.hpp"

int main(int argc, char* argv[])
{
	const int k_dim = 10;
	const int k_pts = 1000;
	const double k_step = 10e-3;

	std::vector<std::tuple<double, double, double>> data;

	auto filter = kalmia::filter::GenerateKalFilterSMA<k_dim> ();

	// Of cource, you can choose an another filter such as:
	// std::array<double,5> coef = {0.1, 0.2, 0.3, 0.4, 0.5};
	// auto filter = kalmia::filter::GenerateKalFilterLPC<10> (coef.begin(), coef.end());

	// Or, make a FIR filter directly:
	// std::array<double,10> coef = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
	// auto filter = kalmia::filter::KalFilterFIR<10> (coef.begin(), coef.end());

	for (int i = 0; i < k_pts; ++i){
		double t = k_step * i;
		double input = sin (t) + 0.1*sin(2*M_PI / (k_step*k_dim) *t);
		filter->Update (input);
		double output = filter->Output ();

		data.push_back (std::tuple<double, double, double> (t, input, output));
	}

	std::ofstream ofs ("out.csv");
	ofs << "t, input, output" << std::endl;

	for (auto elem : data){
		double t, input, output;
		std::tie (t, input, output) = elem;
		ofs << t << "," << input << "," << output << std::endl;
	}

	return 0;
}
*/



#ifndef KALFIRFACTORY_HPP
#define KALFIRFACTORY_HPP

#include <array>
#include <memory>
#include <algorithm>
#include <numeric>
#include "filter/KalFilterFIR.hpp"

namespace kalmia {
namespace filter {

// SMA: Simple Moving Average
template <size_t N>
std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterSMA ();

// LWMA: Linear Weighted Moving Average
template <size_t N>
std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterLWMA ();

// EMA: Exponential Moving Average
template <size_t N>
std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterEMA (double alpha);

// MMA: Modified Moving Average
template <size_t N>
inline std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterMMA (){ return GenerateKalFilterEMA (1. / N) };

// LPC: Linear Phase Characteristic filter
template <size_t N, class InputIterator>
std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterLPC (InputIterator coefficient_begin, InputIterator coefficient_end);

}
}

#include "KalFIRFactory.cpp"
#endif