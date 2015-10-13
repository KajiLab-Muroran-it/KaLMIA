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

// KalOdeSys.hpp
// Require boost.odeint

#ifndef KALODESYS_HPP
#define KALODESYS_HPP

#include <array>
#include <boost/numeric/odeint/stepper/base/explicit_error_stepper_base.hpp>
#include <boost/numeric/odeint/stepper/base/explicit_error_stepper_fsal_base.hpp>
#include <boost/numeric/odeint/stepper/base/explicit_stepper_base.hpp>
#include <boost/numeric/odeint/stepper/base/symplectic_rkn_stepper_base.hpp>


namespace kalmia {
	namespace odesys {
		template<class State, class Time = double>
		class KalOdeSys {
		public:
			using StateType = State;
			KalOdeSys ();
			virtual ~KalOdeSys () = default;

			void operator() (const State& x, State& dxdt, Time t){
				ComputeDerivative (x, dxdt, t);
			}

			virtual void Initialize (State x0, Time t0){ state_ = x0; time_ = t0; }
			virtual void ComputeDerivative (const State& x, State& dxdt, Time t) = 0;

			const State& GetState (){ return state_; }
			const typename State::value_type GetState (size_t index){ return state_[index]; }
			const State& GetState_dt (){ return state_dt_; }
			const typename State::value_type GetState_dt (size_t index){ return state_dt_[index]; }
			
			const Time& GetTime (){ return time_; }

			template<
				class Stepper,
					unsigned short Order,
					unsigned short StepperOrder,
					unsigned short ErrorOrder,
				class Value,
				class Deriv,
				class Algebra,
				class Operations,
				class Resizer
			>
			void DoStep (boost::numeric::odeint::explicit_error_stepper_base<Stepper, Order, StepperOrder, ErrorOrder, State, Value, Deriv, Time, Algebra, Operations, Resizer>& stepper, Time dt){
				stepper.do_step ([this](const State& x, State& dxdt, Time t) {this->ComputeDerivative (x, dxdt, t); }, state_, state_dt_, time_, dt);
			}

				template<
					class Stepper,
						unsigned short Order,
						unsigned short StepperOrder,
						unsigned short ErrorOrder,
					class Value,
					class Deriv,
					class Algebra,
					class Operations,
					class Resizer
				>
				void DoStep (boost::numeric::odeint::explicit_error_stepper_fsal_base<Stepper, Order, StepperOrder, ErrorOrder, State, Value, Deriv, Time, Algebra, Operations, Resizer>& stepper, Time dt){
					stepper.do_step ([this](const State& x, State& dxdt, Time t) {this->ComputeDerivative (x, dxdt, t); }, state_, state_dt_, time_, dt);
				}

					template<
						class Stepper
							, unsigned short Order
							, class Value
							, class Deriv
							, class Algebra
							, class Operations
							, class Resizer
					>
					void DoStep (boost::numeric::odeint::explicit_stepper_base<Stepper, Order, State, Value, Deriv, Time, Algebra, Operations, Resizer>& stepper, Time dt){
						stepper.do_step ([this](const State& x, State& dxdt, Time t) {this->ComputeDerivative (x, dxdt, t); }, state_, state_dt_, time_, dt);
					}

						template <
							size_t NumOfStages,
							unsigned short Order,
						class Coor,
						class Momentum,
						class Value,
						class CoorDeriv,
						class MomentumDeriv,
						class Algebra,
						class Operations,
						class Resizer
						>
						void DoStep (boost::numeric::odeint::symplectic_nystroem_stepper_base<NumOfStages, Order, Coor, Momentum, Value, CoorDeriv, MomentumDeriv, Time, Algebra, Operations, Resizer>& stepper, Time dt) const{
							stepper.do_step ([this](const State& x, State& dxdt, Time t) {this->ComputeDerivative (x, dxdt, t); }, state_, time_, dt);
						}

		private:
			State state_, state_dt_;
			Time time_;
		};
	}
}
//#ifdef KALMIA_HEADER_ONLY
#include "KalOdeSys.cpp"
//#endif
#endif