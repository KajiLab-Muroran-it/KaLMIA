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

// KalIntelligentAGC.cpp
#include <controller/KalIntelligentAGC.hpp>
namespace kalmia {
namespace controller {

template <size_t Prescaler_Div>
KalIntelligentAGC<Prescaler_Div>::KalIntelligentAGC ()
: KalIntelligentAGC<Prescaler_Div> (false, 1.)
{}

template <size_t Prescaler_Div>
KalIntelligentAGC<Prescaler_Div>::KalIntelligentAGC (bool clip, double threshold)
	: clipping_enabled_ (clip)
	, clipping_thr_ (threshold)
	, previous_value_ (0.)
	, current_gain_ (0.)
	, next_gain_ (0.)
{}

template <size_t Prescaler_Div>
void KalIntelligentAGC<Prescaler_Div>::Update_impl (double t, double pv){
	if (abs(current_gain_*pv) > clipping_thr_ && clipping_enabled_){
		current_gain_ = clipping_thr_ / pv;
	} else if ((abs (pv) < abs (previous_value_)) && ((previous_value_*next_gain_) <= 0)){
		next_gain_ = 1. / previous_value_;
	} else if ((previous_value_*pv) <= 0){
		current_gain_ = next_gain_;
	}

	previous_value_ = pv;
}

template <size_t Prescaler_Div>
double KalIntelligentAGC<Prescaler_Div>::Output_impl (){
	return abs (current_gain_);
}

} // namespace controller
} // namespace kalmia
