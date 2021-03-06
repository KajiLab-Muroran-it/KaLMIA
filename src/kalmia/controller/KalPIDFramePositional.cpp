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

// KalPIDFramePositional.cpp
#include "KalPIDFramePositional.hpp"

namespace kalmia {
namespace controller {

template <size_t Prescaler_Div, class ProportionalElement, class IntegralElement, class DifferentialElement>
KalPIDFramePositional<Prescaler_Div, ProportionalElement, IntegralElement, DifferentialElement>::KalPIDFramePositional (double Kp, double Ki, double Kd)
	: t_prev_ (0.)
	, setpoint_ (0.)
	, proportional_ (Kp)
	, integral_ (Ki)
	, differential_ (Kd)
{}

template <size_t Prescaler_Div, class ProportionalElement, class IntegralElement, class DifferentialElement>
void KalPIDFramePositional<Prescaler_Div, ProportionalElement, IntegralElement, DifferentialElement>::Update_impl (double t, double process_value){
	double dt = t - t_prev_;
	if (dt > 0.){
		double error = setpoint_ - process_value;
		proportional_.Update (dt, process_value, error);
		integral_.Update (dt, process_value, error);
		differential_.Update (dt, process_value, error);
	}
	t_prev_ = t;
}


template <size_t Prescaler_Div, class ProportionalElement, class IntegralElement, class DifferentialElement>
double KalPIDFramePositional<Prescaler_Div, ProportionalElement, IntegralElement, DifferentialElement>::Output_impl (){
	return proportional_.Output () + integral_.Output () + differential_.Output ();
}

};
};
