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

void KalPeakDetector::Update_impl (double t, double process_value){
	on_peak_ = false;
	if ((abs (process_value) < abs (prev_value_)) && ((prev_value_ * peak_amplitude_) <= 0)){
		if ((process_value < prev_value_ && detect_peak_) || (process_value > prev_value_ && detect_bottom_)){
			on_peak_ = true;
		}
		prev_peak_amplitude_ = peak_amplitude_;
		peak_amplitude_ = prev_value_;
	}
	prev_value_ = process_value;
}

double KalPeakDetector::Output_impl () {
	if ((peak_amplitude_ >= 0 && detect_peak_) || (peak_amplitude_ < 0 && detect_bottom_)){
		return peak_amplitude_;
	} else{
		return prev_peak_amplitude_;
	}
};

}
}
