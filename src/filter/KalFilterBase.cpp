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

double KalFilterBase::Output (){
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
