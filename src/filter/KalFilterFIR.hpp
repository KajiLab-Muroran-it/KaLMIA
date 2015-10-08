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

// KalFilterFIR.hpp
// Finite impulse response filter
#ifndef KALFILTERFIR_HPP
#define KALFILTERFIR_HPP

#include <assert.h>
#include <algorithm>
#include <array>
#include <deque>
#include <numeric>
#include "filter/KalFilterBase.hpp"

namespace kalmia {
namespace filter{

template <size_t N>
class KalFilterFIR : public KalFilterBase{
public:
	template<class InputIterator>
	KalFilterFIR (InputIterator coefficients_begin, InputIterator coefficients_end);

	virtual ~KalFilterFIR() = default;
	
	// Additional interface
	void Update (double process_value) { Update_impl (process_value); };
	

private:
	virtual void Update_impl (double process_value);
	virtual inline void Update_impl (double t, double process_value) override { Update_impl (process_value); };

	virtual double Output_impl () override;

	const std::array<double, N> coefficients_;
	std::deque<double> buffer_;
	
	template<class InputIterator>
	static std::array<double, N> InitializeFactors (InputIterator coefficients_begin, InputIterator coefficients_end);
};

}
}

#include "KalFilterFIR.cpp"
#endif