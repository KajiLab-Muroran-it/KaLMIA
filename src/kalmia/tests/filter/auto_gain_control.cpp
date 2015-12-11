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

// auto_gain_controll.cpp

#define _USE_MATH_DEFINES
#include <math.h>

#include <tuple> 
#include <memory>
#include <vector>
#include <fstream>

#define KALMIA_HEADER_ONLY
#include "kalmia/controller/KalIntelligentAGC.hpp"

int main ()
{
	const int k_pts = 1000;
	const double k_period = 10;
	const double k_omega1 = 2 * M_PI / (k_period / 2.);
	const double k_omega2 = 2 * M_PI / (k_period / 20.);

	std::vector<std::tuple<double, double, double, double>> log;


	kalmia::controller::KalIntelligentAGC<> agc (true, 0.5);

	for (int i = 0; i<k_pts; ++i){
		double t = k_period / (double)k_pts * i;
		double input = (1. + 0.5*sin (k_omega1*t)) * sin (k_omega2*t);
		agc.Update (t, input);

		log.push_back (std::make_tuple(t, input, agc.Output()*input, agc.Output()));
	}

	std::ofstream ofs ("./output.csv");
	ofs << "time, input, output, gain" << std::endl;

	for (const auto& elem : log){
		double t, input, output, gain;
		std::tie (t, input, output, gain) = elem;
		ofs << t << "," << input << "," << output << "," << gain << std::endl;
	}

	return 0;
}
