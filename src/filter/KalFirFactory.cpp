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

// KalFIRFactory.cpp
#include "KalFIRFactory.hpp"

namespace kalmia {
namespace filter {

template <size_t N>
std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterLWMA (){
	std::array<double, N> ar_;
	double w_ = 2. * N / (N*(N + 1));
	for (auto elem : ar_){
		elem = w_;
		w_ -= 2. / (N*(N + 1));
	}
	return std::make_unique <KalFilterFIR<N>> (ar_.begin (), ar_.end ());
}

template <size_t N>
std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterEMA (double alpha){
	assert (alpha >= 0. && alpha <= 1.);
	std::array<double, N> ar_;
	for (auto iter = ar_.begin (); iter != ar_.end (); ++iter){
		*iter = exp(-alpha * std::distance(ar_.begin(), iter));
	}
	const double sum_ar_ = std::accumulate (ar_.begin(), ar_.end(), 0.);
	std::transform (ar_.begin (), ar_.end (), ar_.begin (), [&sum_ar_](double w_) {return w_ / sum_ar_; });
	return std::make_unique <KalFilterFIR<N>> (ar_.begin (), ar_.end ());
}

template <size_t N, class InputIterator>
std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterLPC (InputIterator coefficient_begin, InputIterator coefficient_end){
	std::array<double, N> ar_;
	if(N%2) assert (std::distance(coefficient_begin, coefficient_end) == N/2+1);
	else assert (std::distance (coefficient_begin, coefficient_end) == N / 2);
	std::copy (coefficient_begin, coefficient_end, ar_.begin ());
	std::copy (coefficient_begin, coefficient_end, ar_.rbegin());
	return std::make_unique <KalFilterFIR<N>> (ar_.begin (), ar_.end ());
}

}
}
