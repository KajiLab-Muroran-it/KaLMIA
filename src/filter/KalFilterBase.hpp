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

// KalControllr.hpp
// TODO: Modify supported type from double to template should better.

#ifndef KALFILTERBASE_HPP
#define KALFILTERBASE_HPP

#include "util/KalNoncopyable.hpp"

namespace kalmia {
namespace filter {
class KalFilterBase : kalmia::util::KalNoncopyable{
public:
	KalFilterBase () = default;
	virtual ~KalFilterBase () = default;

	void Update (double t, double process_value) { Update_impl (t, process_value); };
	double Output () { return Output_impl (); };

private:
	virtual void Update_impl (double t, double process_value) = 0;
	virtual double Output_impl () = 0;
};
}
}

#endif