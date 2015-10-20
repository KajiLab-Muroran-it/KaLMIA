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

// KalPeakDetector.hpp

#ifndef KALPEAKDETECTOR_HPP
#define KALPEAKDETECTOR_HPP

#include "filter/KalFilterBase.hpp"

namespace kalmia {
namespace filter{

template <size_t Prescaler_Div = 1>
class KalPeakDetector : public KalFilterBase<Prescaler_Div>{
public:
	KalPeakDetector (bool detect_peak = true, bool detect_bottom = false)
		: detect_peak_ (detect_peak)
		, detect_bottom_ (detect_bottom)
		, on_peak_ (false)
		, prev_slope_ (true)
		, peak_amplitude_ (0.) {}

	virtual ~KalPeakDetector() = default;

	bool OnPeak () { return on_peak_; };

private:
	virtual void Update_impl (double t, double process_value) override;
	virtual double Output_impl () override { return peak_amplitude_; };

	const bool detect_peak_;
	const bool detect_bottom_;

	bool on_peak_;
	bool prev_slope_; // true for positive slope
	double peak_amplitude_;
	double prev_value_;
};

} // namespace filter
} // namespace kalmia

#ifdef KALMIA_HEADER_ONLY
#include "KalPeakDetector.cpp"
#endif
#endif