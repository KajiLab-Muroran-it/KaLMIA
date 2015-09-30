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
template<size_t N>
template<class InputIterator>
KalFilterFIR<N>::KalFilterFIR (InputIterator factors_begin, InputIterator factors_end)
: factors_ (InitializeFactors(factors_begin, factors_end))
, buffer_ (N)
{ }
template<size_t N>
void KalFilterFIR<N>::Update (double pv){
	buffer_.push_front (pv);
	buffer_.pop_back();
}
template<size_t N>
double KalFilterFIR<N>::Output (){
	return std::inner_product(buffer_.begin(), buffer_.end(), factors_.begin(), 0.);
}

// private
template<size_t N>
template<class InputIterator>
static std::array<double, N> KalFilterFIR<N>::InitializeFactors (InputIterator factors_begin, InputIterator factors_end){
	assert (std::distance(factors_begin, factors_end) == N);
	std::array<double, N> ar_;
	std::copy (factors_begin, factors_end, ar_.begin ());
	return ar_;
}

}
}
