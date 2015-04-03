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

// KalOdeSys.hpp
#ifndef KALODESYS_HPP
#define KALODESYS_HPP

#include <array>

namespace kalmia {
	class KalOdeSys{
	public:
		virtual ~KalOdeSys () = default;

	private:
		KalOdeSys(KalOdeSys&&) = delete;
		KalOdeSys& operator =(KalOdeSys const&) = delete;
		KalOdeSys& operator =(KalOdeSys&&) = delete;
	};
}

//#include "KalOdeSys.cpp"
#endif