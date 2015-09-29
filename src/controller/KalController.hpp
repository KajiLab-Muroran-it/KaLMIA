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

// KalController.hpp


#ifndef KALCONTROLLER_HPP
#define KALCONTROLLER_HPP

#include "util/KalNoncopyable.hpp"

namespace kalmia {
namespace controller {
class KalController : kalmia::util::KalNoncopyable{
public:
	KalController () = default;
	virtual ~KalController () = default;

	virtual void Update (double t, double pv) = 0;
	virtual double Output () = 0;
};
}
}

#ifdef KALMIA_HEADER_ONLY
#include <controller/KalController.cpp>
#endif
#endif