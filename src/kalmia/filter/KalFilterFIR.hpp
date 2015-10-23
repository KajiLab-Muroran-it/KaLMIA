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
#include <numeric>
#include "kalmia/filter/KalFilterBaseFixedRange.hpp"

namespace kalmia {
namespace filter{

template <size_t N, size_t Prescaler_Div = 1>
class KalFilterFIR : public KalFilterBaseFixedRange<N, Prescaler_Div>{
using KalFilterBaseFixedRange<N, Prescaler_Div>::buffer_;
public:
	template<class InputIterator>
	KalFilterFIR (InputIterator coefficients_begin, InputIterator coefficients_end);

	virtual ~KalFilterFIR() = default;

private:
	virtual double Output_impl () override;

	const std::array<double, N> coefficients_;
	
	template<class InputIterator>
	static std::array<double, N> InitializeFactors (InputIterator coefficients_begin, InputIterator coefficients_end);
};

}
}

#include "KalFilterFIR.cpp"
#endif