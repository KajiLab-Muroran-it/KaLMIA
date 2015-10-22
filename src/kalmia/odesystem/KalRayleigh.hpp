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

// KalRayleigh.hpp
#ifndef KALRAYLEIGH_HPP
#define KALRAYLEIGH_HPP

#include "KalOdeSys.hpp"

namespace kalmia {
	namespace odesys {
		template <class State = std::array<double, 2>, class Time = double>
		class KalRayleigh : public KalOdeSys<State, Time> {
		public:
			using StateType = State;

			KalRayleigh (double omega, double epsilon, double G);

			virtual void ComputeDerivative (const State& x, State& dxdt, Time t) override;
			void SetExternalForce (double f) { f_ = f; }

		private:
			double omega_;
			double epsilon_;
			double G_;
			double f_;
		};
	}
}

#include "KalRayleigh.cpp"
#endif