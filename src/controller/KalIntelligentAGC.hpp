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

// KalIntelligentAGC.hpp

// This class provides the auto gain controller (AGC)
// which isn't strict but without overranging or discontinuity.

// Sample:
/*
#define _USE_MATH_DEFINES
#include <math.h>

#include <memory>
#include <vector>
#include <iostream>
#include <fstream>

#define KALMIA_HEADER_ONLY
#include "controller/KalAutoGainController.hpp"
#include "controller/KalIntelligentAGC.hpp"

int main(int argc, char** argv[])
{
	const int pts = 1000;
	const double period = 10;
	const double omega1 = 2 * M_PI / (period / 2.);
	const double omega2 = 2 * M_PI / (period / 20.);

	std::vector<double> log_times;
	std::vector<double> log_inputs;
	std::vector<double> log_outputs;
	std::vector<double> log_gains;



	//kalmia::controller::KalIntelligentAGC agc;
	kalmia::controller::KalIntelligentAGC agc(true, 0.5);

	for (int i = 0; i<pts; ++i){
		double t = period/(double)pts * i;
		double input = (1.+0.5*sin (omega1*t)) * sin (omega2*t);
		agc.Update (t, input);
		
		log_times.push_back (t);
		log_inputs.push_back (input);
		log_outputs.push_back (agc.Output ()*input);
		log_gains.push_back (agc.Output ());
	}

	std::ofstream ofs ("./output.csv");
	{
		auto i_iter = log_inputs.begin ();
		auto o_iter = log_outputs.begin ();
		auto g_iter = log_gains.begin ();
		for (auto time : log_times){
			ofs << time << "," << (*i_iter) << "," << (*o_iter) << "," << (*g_iter) << std::endl;
			++i_iter;
			++o_iter;
			++g_iter;
		}
	}

	return 0;
}
*/


#ifndef KALINTELLIGENTAGC_HPP
#define KALINTELLIGENTAGC_HPP

#include <cmath>
#include <controller/KalControllerBase.hpp>

namespace kalmia {
	namespace controller {
		class KalIntelligentAGC : public KalControllerBase {
		public:
			KalIntelligentAGC ();
			KalIntelligentAGC (bool clip, double threshold = 1.);
			virtual ~KalIntelligentAGC () = default;

			void Update (double t, double pv) override;
			double Output () override;

		private:
			bool clipping_enabled_;
			double clipping_thr_;
			double previous_value_, current_gain_, next_gain_;
		};
	}

}
#ifdef KALMIA_HEADER_ONLY
#include <controller/KalIntelligentAGC.cpp>
#endif
#endif