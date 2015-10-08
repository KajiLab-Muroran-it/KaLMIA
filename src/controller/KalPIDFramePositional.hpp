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

#include "controller/KalPIDFrameBase.hpp"
#include "controller/KalProportionalElement.hpp"
#include "controller/KalIntegralElement.hpp"
#include "controller/KalDifferentialElement.hpp"

namespace kalmia {
namespace controller{

template <class ProportionalElement = KalProportionalElement, class IntegralElement = KalIntegralElement, class DifferentialElement = KalDifferentialElementForward>

class KalPIDFramePositional : public KalPIDFrameBase<ProportionalElement, IntegralElement, DifferentialElement>{

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

using KalPIDFramePositionalPID = KalPIDFramePositional<KalProportionalElement, KalIntegralElement, KalDifferentialElement>;
using KalPIDFramePositionalPI_D = KalPIDFramePositional<KalProportionalElement, KalIntegralElement, KalDifferentialElementForward>;
using KalPIDFramePositionalI_PD = KalPIDFramePositional<KalProportionalElementForward, KalIntegralElement, KalDifferentialElementForward>;
}
}

#include "KalPIDFramePositional.cpp"
#endif