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

// KalPIDFramePositional.hpp

#ifndef KALPIDFRAMEPOSITIONAL_HPP
#define KALPIDFRAMEPOSITIONAL_HPP

#include "kalmia/controller/KalPIDFrameBase.hpp"
#include "kalmia/controller/KalProportionalElement.hpp"
#include "kalmia/controller/KalIntegralElement.hpp"
#include "kalmia/controller/KalDifferentialElement.hpp"

namespace kalmia {
namespace controller{

template <size_t Prescaler_Div = 1, class ProportionalElement = KalProportionalElement, class IntegralElement = KalIntegralElement, class DifferentialElement = KalDifferentialElementForward>

class KalPIDFramePositional : public KalPIDFrameBase<Prescaler_Div, ProportionalElement, IntegralElement, DifferentialElement> {

public:
	KalPIDFramePositional (double Kp, double Ki, double Kd);
	virtual ~KalPIDFramePositional() = default;

	void SetTargetValue (double target_value) { setpoint_ = target_value; };

private:
	virtual void Update_impl (double t, double process_value);
	virtual double Output_impl () override;

	double t_prev_;
	double setpoint_;
	ProportionalElement proportional_;
	IntegralElement integral_;
	KalDifferentialElement differential_;
};

template <size_t Prescaler_Div = 1>
using KalPIDFramePositionalPID = KalPIDFramePositional<Prescaler_Div, KalProportionalElement, KalIntegralElement, KalDifferentialElement>;
template <size_t Prescaler_Div = 1>
using KalPIDFramePositionalPI_D = KalPIDFramePositional<Prescaler_Div, KalProportionalElement, KalIntegralElement, KalDifferentialElementForward>;
template <size_t Prescaler_Div = 1>
using KalPIDFramePositionalI_PD = KalPIDFramePositional<Prescaler_Div, KalProportionalElementForward, KalIntegralElement, KalDifferentialElementForward>;
}
}

#include "KalPIDFramePositional.cpp"
#endif