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

// KalFilterFIR.cpp
#include "KalFilterFIR.hpp"

namespace kalmia {
namespace filter{

// public
template<size_t N, size_t Prescaler_Div>
template<class InputIterator>
KalFilterFIR<N, Prescaler_Div>::KalFilterFIR (InputIterator coefficients_begin, InputIterator coefficients_end)
: coefficients_ (InitializeFactors(coefficients_begin, coefficients_end))
{ }

template<size_t N, size_t Prescaler_Div>
double KalFilterFIR<N, Prescaler_Div	>::Output_impl (){
	return std::inner_product(buffer_.begin(), buffer_.end(), coefficients_.begin(), 0.);
}

template<size_t N, size_t Prescaler_Div>
template<class InputIterator>
static std::array<double, N> KalFilterFIR<N, Prescaler_Div>::InitializeFactors (InputIterator coefficients_begin, InputIterator coefficients_end){
	assert (std::distance(coefficients_begin, coefficients_end) == N);
	std::array<double, N> ar_;
	std::copy (coefficients_begin, coefficients_end, ar_.begin ());
	return ar_;
}

}
}
