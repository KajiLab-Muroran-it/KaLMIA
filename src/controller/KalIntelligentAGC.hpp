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

		private:
			void Update_impl (double t, double pv) override;
			double Output_impl () override;
		
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