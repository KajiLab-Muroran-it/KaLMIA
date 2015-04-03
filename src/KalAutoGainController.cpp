/**************************************************************/
/*                                                            */
/*     ================[ KaLMIA Library ]================     */
/*                                                            */
/*            Kaji-Lab Magnifier Integrated Assets            */
/*                                                            */
/*     ============== " Be Ambitious For " ==============     */
/*                                                            */
/*              Muroran Institute of Technology               */
/*      Electronic System Control Engineering Laboratory      */
/*                                                            */
/**************************************************************/

// KalAutoGainController.cpp
#include "KalAutoGainController.hpp"
namespace kalmia {
	KalAutoGainController::KalAutoGainController ()
		: gain (0), prev (0)
	{}

	void KalAutoGainController::Update (double val){
		if ((abs (val) < abs (prev)) && ((prev*gain) <= 0)){
			gain = 1 / prev;
		}
		prev = val;
	}

	double KalAutoGainController::GetAutoGain (){
		return abs (gain);
	}
}
