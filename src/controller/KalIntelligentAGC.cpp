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
		KalIntelligentAGC::KalIntelligentAGC ()
			: previous_value_ (0.)
			, current_gain_ (0.)
			, next_gain_ (0.)
		{}

		void KalIntelligentAGC::Update (double t, double pv){
			if (abs(current_gain_*pv) > 1){
				current_gain_ = 1. / pv;
			} else if ((abs (pv) < abs (previous_value_)) && ((previous_value_*next_gain_) <= 0)){
				next_gain_ = 1. / previous_value_;
			} else if ((previous_value_*pv) <= 0){
				current_gain_ = next_gain_;
			}

			previous_value_ = pv;
		}

		double KalIntelligentAGC::Output (){
			return abs (current_gain_);
		}
	}
}
