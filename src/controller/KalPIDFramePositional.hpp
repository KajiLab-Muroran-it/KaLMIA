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

#include "controller/KalControllerBase.hpp"
#include "controller/KalProportionalElement.hpp"
#include "controller/KalIntegralElement.hpp"
#include "controller/KalDifferentialElement.hpp"

namespace kalmia {
namespace controller{

template <class ProportionalElement = KalProportionalElement, class IntegralElement = KalIntegralElement, class DifferentialElement = KalDifferentialElementForward>
class KalPIDFramePositional : public KalControllerBase{
	static_assert(std::is_base_of<KalProportionalElementBase, ProportionalElement>::value,
		"Proportional emement must be inherited form KalProportionalElementBase.");
	static_assert(std::is_base_of<KalIntegralElementBase, IntegralElement>::value,
		"Integral emement must be inherited form KalIntegralElementBase.");
	static_assert(std::is_base_of<KalDifferentialElementBase, DifferentialElement>::value,
		"Differential emement must be inherited form KalDifferentialElementBase.");

public:
	KalPIDFramePositional (double Kp, double Ki, double Kd);
	virtual ~KalPIDFramePositional() = default;

	virtual void Update (double t, double process_value);
	virtual double Output () override;

	void SetTargetValue (double target_value) { setpoint_ = target_value; };

private:
	double t_prev_;
	double setpoint_;
	ProportionalElement proportional_;
	IntegralElement integral_;
	KalDifferentialElement differential_;
};

}
}

#include "KalPIDFramePositional.cpp"
#endif