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

// KalRayleighCascaded.hpp
#ifndef KALRAYLEIGHCASCADED_HPP
#define KALRAYLEIGHCASCADED_HPP

#include "KalOdeSys.hpp"

namespace kalmia {
	namespace odesys {
		template <class State = std::array<double, 4>, class Time = double>
		class KalRayleighCascaded : public KalOdeSys<State, Time> {
		public:
			using StateType = State;

			KalRayleighCascaded (double omega, double epsilon, double G);
			KalRayleighCascaded (double omega, double epsilon, double G1, double G2);
			KalRayleighCascaded (double omega, double epsilon1, double epsilon2, double G1, double G2);
			KalRayleighCascaded (double omega1, double omega2, double epsilon1, double epsilon2, double G1, double G2);

			virtual void ComputeDerivative (const State& x, State& dxdt, Time t) override;
			void SetExternalForce (double f) { f_ = f; }

		private:
			double omega1_, omega2_;
			double epsilon1_, epsilon2_;
			double G1_, G2_;
			double f_;
		};
	}
}

#include "KalRayleighCascaded.cpp"
#endif