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
	KalFilterFIR (InputIterator factors_begin, InputIterator factors_end);

	virtual ~KalFilterFIR() = default;
	virtual inline void Update (double t, double pv) override { Update (pv); };
	virtual void Update (double pv);

	virtual double Output() override;

private:
	const std::array<double, N> factors_;
	std::deque<double> buffer_;
	
	template<class InputIterator>
	static std::array<double, N> InitializeFactors (InputIterator factors_begin, InputIterator factors_end);
};

}
}

#include "KalFilterFIR.cpp"
#endif