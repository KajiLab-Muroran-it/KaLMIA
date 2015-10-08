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

// KalKalPIDElementBase.hpp

#ifndef KALKALPIDEMEMENTBASE_HPP
#define KALKALPIDEMEMENTBASE_HPP

#include <math.h>
#include "util/KalNoncopyable.hpp"

namespace kalmia {
namespace controller {

class KalPIDElementBase : kalmia::util::KalNoncopyable {
public:
	virtual ~KalPIDElementBase () = default;

	void Update (double dt, double process_value, double error) { Update_impl (dt, process_value, error); };
	double Output () { return Output_impl (); };
	
private:
	virtual void Update_impl (double dt, double process_value, double error) = 0;
	virtual double Output_impl () = 0;
};

class KalProportionalElementBase : public KalPIDElementBase {
public:
	virtual ~KalProportionalElementBase () = default;
};

class KalIntegralElementBase : public KalPIDElementBase {
public:
	virtual ~KalIntegralElementBase () = default;
};

class KalDifferentialElementBase : public KalPIDElementBase {
public:
	virtual ~KalDifferentialElementBase () = default;
};

}
}

#endif