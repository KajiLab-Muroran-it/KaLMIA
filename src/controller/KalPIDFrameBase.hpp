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

// KalPIDFrameBase.hpp

#ifndef KALPIDFRAMEBASE_HPP
#define KALPIDFRAMEBASE_HPP

#include "controller/KalControllerBase.hpp"
#include "controller/KalPIDElementBase.hpp"

namespace kalmia {
namespace controller{

template <class ProportionalElement, class IntegralElement, class DifferentialElement>
class KalPIDFrameBase : public KalControllerBase{
	static_assert(std::is_base_of<KalProportionalElementBase, ProportionalElement>::value,
		"Proportional emement must be inherited form KalProportionalElementBase.");
	static_assert(std::is_base_of<KalIntegralElementBase, IntegralElement>::value,
		"Integral emement must be inherited form KalIntegralElementBase.");
	static_assert(std::is_base_of<KalDifferentialElementBase, DifferentialElement>::value,
		"Differential emement must be inherited form KalDifferentialElementBase.");

public:
	virtual ~KalPIDFrameBase() = default;

};

}
}

#endif