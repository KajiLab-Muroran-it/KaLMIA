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

// KalFilterBaseFixedRange.hpp
#ifndef KALFILTERBASEFIXEDRANGE_HPP
#define KALFILTERBASEFIXEDRANGE_HPP

#include <deque>
#include "filter/KalFilterBase.hpp"

namespace kalmia {
namespace filter{


template <size_t N, size_t Prescaler_Div>
class KalFilterBaseFixedRange : public KalFilterBase<Prescaler_Div>{
public:
	KalFilterBaseFixedRange () :buffer_ (N) {};
	virtual ~KalFilterBaseFixedRange() = default;

	using KalFilterBase::Update;
	// Additional interface
	void Update (double process_value) { Update (0., process_value); };

protected:
	std::deque<double> buffer_;

private:
	virtual void Update_impl (double process_value){
		buffer_.pop_back ();
		buffer_.push_front (process_value);
	};
	virtual inline void Update_impl (double t, double process_value) override final{ Update_impl (process_value); };
};

} // namespace filter
} // namespace kalmia

#endif