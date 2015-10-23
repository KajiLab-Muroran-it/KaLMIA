// peak_detection.cpp

#define _USE_MATH_DEFINES
#include <math.h>

#include <tuple>
#include <array>
#include <vector>
#include <fstream>

#define KALMIA_HEADER_ONLY
#include "kalmia/filter/KalPeakDetector.hpp"

int main ()
{
	const int k_pts = 1000;
	const double k_period = 10;
	const double k_omega1 = 2 * M_PI / (k_period / 2.);
	const double k_omega2 = 2 * M_PI / (k_period / 20.);

	std::vector<std::tuple<double, double, double, int>> log;

	kalmia::filter::KalPeakDetector<> peak(false, true);

	for (int i = 0; i<k_pts; ++i){
		double t = k_period / (double)k_pts * i;
		double input = sin (k_omega1*t) + 0.2*sin (k_omega2*t);
		peak.Update (t, input);

		log.push_back (std::make_tuple(t, input, peak.Output(), (int)peak.OnPeak()) );
		
	}

	std::ofstream ofs ("./output.csv");
	{
		for (auto elem : log){
			double t, input, ampl;
			int flag;

			std::tie (t, input, ampl, flag) = elem;
			ofs
				<< t << ","
				<< input << ","
				<< ampl << ","
				<< flag << std::endl;
		}
	}
	return 0;
}

