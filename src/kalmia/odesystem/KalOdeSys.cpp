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

// KalOdeSys.cpp
#include "KalOdeSys.hpp"

namespace kalmia {
	namespace odesys {
		template<class State, class Time>
		KalOdeSys<State, Time>::KalOdeSys ()
			: state_ ()
			, state_dt_ ()
			, time_ ()
		{}
	}

}
