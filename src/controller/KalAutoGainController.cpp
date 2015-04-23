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

// KalAutoGainController.cpp
#include <controller/KalAutoGainController.hpp>
namespace kalmia {
	namespace controller {
		KalAutoGainController::KalAutoGainController ()
			: gain (0), previous_value (0)
		{}

		void KalAutoGainController::Update (double t, double pv){
			if ((abs (pv) < abs (previous_value)) && ((previous_value*gain) <= 0)){
				gain = 1 / previous_value;
			}
			previous_value = pv;
		}

		double KalAutoGainController::Output (){
			return abs (gain);
		}
	}
}
