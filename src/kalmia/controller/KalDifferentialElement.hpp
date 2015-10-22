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

// KalDifferentialElem.hpp

#ifndef KALDifferentialELEM_HPP
#define KALDifferentialELEM_HPP

#include "kalmia/controller/KalPIDElementBase.hpp"

namespace kalmia {
namespace controller{

class KalDifferentialElement : public KalDifferentialElementBase{
public:
	KalDifferentialElement (double Kd) :gain_ (Kd), error_dt_(0.), error_prev_(NAN) {};
	virtual ~KalDifferentialElement() = default;

private:
	virtual void Update_impl (double dt, double process_value, double error) override {
		if (!isnan (error_prev_)){
			error_dt_ = (error - error_prev_) / dt;
		}
		error_prev_ = error;
	};
	virtual double Output_impl () override { return gain_ * error_dt_; };

	const double gain_;
	double error_dt_;
	double error_prev_;
};

class KalDifferentialElementForward : public KalDifferentialElementBase {
public:
	KalDifferentialElementForward (double Kd) :gain_ (Kd), process_value_dt_ (0.), process_value_prev_ (NAN) {};
	virtual ~KalDifferentialElementForward () = default;


private:
	virtual void Update_impl (double dt, double process_value, double error) override {
		if (!isnan (process_value_prev_)){
			process_value_dt_ = (process_value - process_value_prev_) / dt;
		}
		process_value_prev_ = process_value;
	};
	virtual double Output_impl () override { return gain_ * process_value_dt_; };

	const double gain_;
	double process_value_dt_;
	double process_value_prev_;
};

}
}
#endif