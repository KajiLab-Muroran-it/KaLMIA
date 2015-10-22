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

// KalFilterMedian.hpp
#ifndef KALFILTERMEDIAN_HPP
#define KALFILTERMEDIAN_HPP
#include <algorithm>
#include <array>
#include "kalmia/filter/KalFilterBaseFixedRange.hpp"

namespace kalmia {
namespace filter{

template <size_t N, size_t Prescaler_Div = 1>
class KalFilterMedian : public KalFilterBaseFixedRange<N, Prescaler_Div>{
public:
	virtual ~KalFilterMedian() = default;

private:
	virtual double Output_impl () override final { return GetMedian<N % 2> (); };

	template<bool Is_Odd> double GetMedian () {
		std::array<double, N> buf_copy;
		std::copy (buffer_.begin(), buffer_.end(), buf_copy.begin());
		return GetMedianFunctor<Is_Odd>::Get(move(buf_copy));
	};

	template<bool> struct GetMedianFunctor {};
	template<> struct GetMedianFunctor<false> {
		static double Get (std::array<double, N> && buf_copy){
			std::sort (buf_copy.begin (), buf_copy.end ());
			return (buf_copy[N / 2 - 1] + buf_copy[N / 2]) / 2.;
		};
	};
	template<> struct GetMedianFunctor<true> {
		static double Get (std::array<double, N> &&buf_copy){
			nth_element (buf_copy.begin (), buf_copy.begin () + N/2 , buf_copy.end ());
			return buf_copy[N/2];
		}
	};
};

} // namespace filter
} // namespace kalmia

#endif