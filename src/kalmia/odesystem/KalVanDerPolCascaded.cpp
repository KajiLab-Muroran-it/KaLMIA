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

// KalVanDerPolCascaded.cpp
#include "KalVanDerPolCascaded.hpp"

namespace kalmia {
	namespace odesys {
		template <class State, class Time>
		KalVanDerPolCascaded<State, Time>::KalVanDerPolCascaded (double omega, double epsilon, double G)
			: KalVanDerPolCascaded<State, Time>::KalVanDerPolCascaded (omega, epsilon, G, G)
		{}
		template <class State, class Time>
		KalVanDerPolCascaded<State, Time>::KalVanDerPolCascaded (double omega, double epsilon, double G1, double G2)
			: KalVanDerPolCascaded<State, Time>::KalVanDerPolCascaded (omega, epsilon, epsilon, G1, G2)
		{}
		template <class State, class Time>
		KalVanDerPolCascaded<State, Time>::KalVanDerPolCascaded (double omega, double epsilon1, double epsilon2, double G1, double G2)
			: KalVanDerPolCascaded<State, Time>::KalVanDerPolCascaded (omega, omega, epsilon1, epsilon2, G1, G2)
		{}
		template <class State, class Time>
		KalVanDerPolCascaded<State, Time>::KalVanDerPolCascaded (double omega1, double omega2, double epsilon1, double epsilon2, double G1, double G2)
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
		void KalVanDerPolCascaded<State, Time>::ComputeDerivative (const State& x, State& dxdt, Time t){
			dxdt[0] = x[1];
			dxdt[1] = G1_*f_ + epsilon1_*(1 - x[0] * x[0])*x[1] - omega1_*omega1_*x[0];
			dxdt[2] = x[3];
			dxdt[3] = G2_*x[1] + epsilon2_*(1 - x[2] * x[2])*x[3] - omega2_*omega2_*x[2];
		}
	}
}
