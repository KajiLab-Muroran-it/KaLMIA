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

// KalAutoGainController.hpp
// Library header template

#ifndef KALAUTOGAINCONTROLLER_HPP
#define KALAUTOGAINCONTROLLER_HPP

#include <cmath>
#include <controller/KalControllerBase.hpp>

namespace kalmia {
	namespace controller {
		class KalAutoGainController : public KalControllerBase {
		public:
			KalAutoGainController ();
			virtual ~KalAutoGainController () = default;

			void Update (double t, double pv) override;
			double Output () override;

		private:
			double previous_value_, gain_;
		};
	}

}
#ifdef KALMIA_HEADER_ONLY
#include <controller/KalAutoGainController.cpp>
#endif
#endif