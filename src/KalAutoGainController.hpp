/**************************************************************/
/*                                                            */
/*     ================[ KaLMIA Library ]================     */
/*                                                            */
/*            Kaji-Lab Magnifier Integrated Assets            */
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

namespace kalmia {
	class KalAutoGainController{
	public:
		KalAutoGainController ();
		virtual ~KalAutoGainController() = default;
		
		void Update (double val);
		double GetAutoGain ();

	private:
		double prev, gain;

		KalAutoGainController(KalAutoGainController&&) = delete;
		KalAutoGainController& operator =(KalAutoGainController const&) = delete;
		KalAutoGainController& operator =(KalAutoGainController&&) = delete;
	};

}

//#include "KalAutoGainController.cpp"
#endif