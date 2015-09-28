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

// This class provides the auto gain controller (AGC)
// which isn't strict but without overranging or discontinuity.



// KalIntelligentAGC.hpp
// Library header template

#ifndef KALINTELLIGENTAGC_HPP
#define KALINTELLIGENTAGC_HPP

#include <cmath>
#include <controller/KalController.hpp>

namespace kalmia {
	namespace controller {
		class KalIntelligentAGC : public KalController {
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

			KalIntelligentAGC (KalIntelligentAGC&&) = delete;
			KalIntelligentAGC& operator =(KalIntelligentAGC const&) = delete;
			KalIntelligentAGC& operator =(KalIntelligentAGC&&) = delete;
		};
	}

}
#ifdef KALMIA_HEADER_ONLY
#include <controller/KalIntelligentAGC.cpp>
#endif
#endif