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


#ifndef KALFILTERBASE_HPP
#define KALFILTERBASE_HPP

#include "util/KalNoncopyable.hpp"

namespace kalmia {
namespace filter {
class KalFilterBase : kalmia::util::KalNoncopyable{
public:
	KalFilterBase () = default;
	virtual ~KalFilterBase () = default;

	virtual void Update (double t, double pv) = 0;
	virtual double Output () = 0;
};
}
}

#endif