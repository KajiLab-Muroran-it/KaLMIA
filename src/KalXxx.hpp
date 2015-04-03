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

// KalXxx.hpp
// Library header template

#ifndef KALXXX_HPP
#define KALXXX_HPP

namespace kalmia {
	class KalXxx{
	public:
		virtual ~KalXxx() = default;
		
	private:
		KalXxx(KalXxx&&) = delete;
		KalXxx& operator =(KalXxx const&) = delete;
		KalXxx& operator =(KalXxx&&) = delete;
	};
}

//#include "KalXxx.cpp"
#endif