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

// KalRayleighCascaded.cpp
#include "KalRayleighCascaded.hpp"

namespace kalmia {
	namespace odesys {
		template <class State, class Time>
		KalRayleighCascaded<State, Time>::KalRayleighCascaded (double omega, double epsilon, double G)
			: KalRayleighCascaded<State, Time>::KalRayleighCascaded (omega, epsilon, G, G)
		{}
		template <class State, class Time>
		KalRayleighCascaded<State, Time>::KalRayleighCascaded (double omega, double epsilon, double G1, double G2)
			: KalRayleighCascaded<State, Time>::KalRayleighCascaded (omega, epsilon, epsilon, G1, G2)
		{}
		template <class State, class Time>
		KalRayleighCascaded<State, Time>::KalRayleighCascaded (double omega, double epsilon1, double epsilon2, double G1, double G2)
			: KalRayleighCascaded<State, Time>::KalRayleighCascaded (omega, omega, epsilon1, epsilon2, G1, G2)
		{}
		template <class State, class Time>
		KalRayleighCascaded<State, Time>::KalRayleighCascaded (double omega1, double omega2, double epsilon1, double epsilon2, double G1, double G2)
			: KalOdeSys<State, Time> ()
			, omega1_ (omega1)
			, omega2_ (omega2)
			, epsilon1_ (epsilon1)
			, epsilon2_ (epsilon2)
			, G1_ (G1)
			, G2_ (G2)
			, f_ ()
		{}

		template <class State, class Time>
		void KalRayleighCascaded<State, Time>::ComputeDerivative (const State& x, State& dxdt, Time t){
			dxdt[0] = x[1];
			dxdt[1] = G1_*f_ + epsilon1_*(1 - x[1] * x[1])*x[1] - omega1_*omega1_*x[0];
			dxdt[2] = x[3];
			dxdt[3] = G2_*x[1] + epsilon2_*(1 - x[3] * x[3])*x[3] - omega2_*omega2_*x[2];
		}
	}
}
