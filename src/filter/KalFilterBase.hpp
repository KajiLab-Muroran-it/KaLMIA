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

#include <utility>
#include "util/KalNoncopyable.hpp"

namespace kalmia {
namespace filter {
class KalFilterBase : kalmia::util::KalNoncopyable{
public:
	KalFilterBase () = default;
	virtual ~KalFilterBase () = default;

	void Update (double t, double process_value) { Update_impl (t, process_value); }
	double Output ();

	void SetUpperLimit (double limit, bool enabled = true){ upper_limit_ = std::make_pair (enabled, limit); }
	void SetLowerLimit (double limit, bool enabled = true){ lower_limit_ = std::make_pair (enabled, limit); }

private:
	virtual void Update_impl (double t, double process_value) = 0;
	virtual double Output_impl () = 0;

	std::pair<bool, double> upper_limit_, lower_limit_;
};

} // namespace filter
} // namespace kalmia

#ifdef KALMIA_HEADER_ONLY
#include "KalFIlterBase.cpp"
#endif
#endif