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

// KalFilterCA.hpp
// CA: Cumulative moving Average (=overall average)

#ifndef KALFILTERCA_HPP
#define KALFILTERCA_HPP
#include <algorithm>
#include "filter/KalFilterBase.hpp"

namespace kalmia {
namespace filter {

template <size_t Prescaler_Div = 1>
class KalFilterCA : public KalFilterBase<Prescaler_Div> {
public:
	KalFilterCA ():n_(0), sum_(0.){};
	virtual ~KalFilterCA () = default;

	using KalFilterBase::Update;
	// Additional interface
	void Update (double process_value) { Update_impl (process_value); };

private:
	virtual void Update_impl (double t, double process_value) { Update_impl (process_value); }
	virtual void Update_impl (double process_value){
		sum_ += process_value;
		++n_;
	}

	virtual double Output_impl () override{
		if (n_){ return sum_ / n_; }
		else { return 0.; }
	}
	
	unsigned int n_;
	double sum_;
};

} // namespace filter
} // namespace kalmia

#endif