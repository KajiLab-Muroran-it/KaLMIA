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

// KalPeakDetector.cpp
#include "KalPeakDetector.hpp"

namespace kalmia {
namespace filter{

template <size_t Prescaler_Div>
void KalPeakDetector<Prescaler_Div>::Update_impl (double t, double process_value){
	on_peak_ = false;

	bool slope = (process_value - prev_value_) > 0.;

	if (slope != prev_slope_){
		if ((detect_peak_ && !slope) || (detect_bottom_ && slope)){
			on_peak_ = true;
			peak_amplitude_ = prev_value_;
		}
	}

	prev_slope_ = slope;
	prev_value_ = process_value;
}


}
}
