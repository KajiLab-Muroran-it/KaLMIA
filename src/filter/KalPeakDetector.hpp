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

class KalPeakDetector : public KalFilterBase{
public:
	KalPeakDetector (bool detect_peak = true, bool detect_bottom = false) 
		: detect_peak_(detect_peak)
		, detect_bottom_(detect_bottom)
		, on_peak_ (false)
		, peak_amplitude_ (0.)
		, prev_peak_amplitude_ (0.)
		, prev_value_ (0.) {};
	virtual ~KalPeakDetector() = default;

	bool OnPeak () { return on_peak_; };

private:
	virtual void Update_impl (double t, double process_value) override;
	virtual double Output_impl () override;

	const bool detect_peak_;
	const bool detect_bottom_;
	bool on_peak_;
	double peak_amplitude_;
	double prev_peak_amplitude_;
	double prev_value_;
};


}
}

#ifdef KALMIA_HEADER_ONLY
#include "KalPeakDetector.cpp"
#endif
#endif