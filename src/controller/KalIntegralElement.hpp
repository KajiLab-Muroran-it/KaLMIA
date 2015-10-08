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

// KalIntegralElem.hpp

#ifndef KALINTEGRALELEM_HPP
#define KALINTEGRALELEM_HPP

#include "controller/KalPIDElementBase.hpp"

namespace kalmia {
namespace controller{

class KalIntegralElement : public KalIntegralElementBase{
public:
	KalIntegralElement(double Ki) : gain_ (Ki), total_error_(0.) {};
	virtual ~KalIntegralElement() = default;

private:
	virtual void Update_impl (double dt, double process_value, double error) override { total_error_ += error*dt; };
	virtual double Output_impl () override { return gain_ * total_error_; };

	const double gain_;
	double total_error_;
};

}
}

#endif