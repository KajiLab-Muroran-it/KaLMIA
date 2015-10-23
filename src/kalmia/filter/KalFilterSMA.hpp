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

// KalFilterSMA.hpp
// SMA: Simple Moving Average
#ifndef KALFILTERSMA_HPP
#define KALFILTERSMA_HPP
#include <algorithm>
#include <array>
#include "kalmia/filter/KalFilterBaseFixedRange.hpp"

namespace kalmia {
namespace filter {

template <size_t N, size_t Prescaler_Div = 1>
class KalFilterSMA : public KalFilterBaseFixedRange<N, Prescaler_Div> {
using KalFilterBaseFixedRange<N, Prescaler_Div>::buffer_;

public:
	KalFilterSMA ():sum_(0.){};
	virtual ~KalFilterSMA () = default;

private:
	virtual void Update_impl (double process_value){
		sum_ += process_value;
		sum_ -= buffer_.back ();
		buffer_.pop_back ();
		buffer_.push_front (process_value);
	}

	virtual double Output_impl () override final { return sum_/N; }

	double sum_;
};

} // namespace filter
} // namespace kalmia

#endif