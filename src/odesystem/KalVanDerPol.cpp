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

// KalVanDerPol.cpp
#include "KalVANDERPOL.hpp"

namespace kalmia {
	template <class State, class Time>
	KalVanDerPol<State, Time>::KalVanDerPol (double omega, double epsilon, double G)
		: KalOdeSys<State, Time> ()
		, omega_ (omega)
		, epsilon_ (epsilon)
		, G_ (G)
		, f_ ()
	{}

	template <class State, class Time>
	void KalVanDerPol<State, Time>::ComputeDerivative (const State& x, State& dxdt, Time t){
		dxdt[0] = x[1];
		dxdt[1] = G_*f_ + epsilon_*(1 - x[1] * x[1])*x[1] - omega_*omega_*x[0];
	}
}
