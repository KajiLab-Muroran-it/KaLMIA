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

// KalFilterBase.cpp
#include "KalFilterBase.hpp"

namespace kalmia {
namespace filter {

template <>
void KalFilterBase<1>::Update (double t, double process_value){
	Update_impl (t, process_value);
}

template <size_t Prescaler_Div>
void KalFilterBase<Prescaler_Div>::Update (double t, double process_value){
	++prescaler_count_;
	prescaler_count_ %= Prescaler_Div;
	if (!prescaler_count_){
		Update_impl (t, process_value);
	}
}

template <size_t Prescaler_Div>
double KalFilterBase<Prescaler_Div>::Output (){
	double output = Output_impl ();
	if (upper_limit_.first && output >  upper_limit_.second){
		output = upper_limit_.second;
	} else if (lower_limit_.first && output < lower_limit_.second){
		output = lower_limit_.second;
	}
	return output;
}

} // namespace filter
} // namespace kalmia
