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

// KalProportionalElem.hpp

#ifndef KALPROPORTIONALELEM_HPP
#define KALPROPORTIONALELEM_HPP

#include "controller/KalPIDElementBase.hpp"

namespace kalmia {
namespace controller{

class KalProportionalElement : public KalProportionalElementBase{
public:
	KalProportionalElement (double Kp) : gain_ (Kp), error_(0.) {};
	virtual ~KalProportionalElement() = default;

	virtual void Update_impl (double dt, double process_value, double error) override { error_ = error; };
	virtual double Output_impl () override { return gain_ * error_; };

private:
	const double gain_;
	double error_;
};

}
}

#endif