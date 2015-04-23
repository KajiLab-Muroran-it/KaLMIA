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

// KalController.hpp


#ifndef KALCONTROLLER_HPP
#define KALCONTROLLER_HPP

namespace kalmia {
	namespace controller {
		class KalController {
		public:
			KalController () = default;
			virtual ~KalController () = default;

			virtual void Update (double t, double pv) = 0;
			virtual double Output () = 0;

		private:
			KalController (KalController&&) = delete;
			KalController& operator =(KalController const&) = delete;
			KalController& operator =(KalController&&) = delete;
		};
	}
}

#ifdef KALMIA_HEADER_ONLY
#include <controller/KalController.cpp>
#endif
#endif