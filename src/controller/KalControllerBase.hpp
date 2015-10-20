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

// KalController.hpp


#ifndef KALCONTROLLER_HPP
#define KALCONTROLLER_HPP

#include "filter/KalFilterBase.hpp"
namespace kalmia{
namespace controller{

template <size_t Prescaler_Div>
using KalControllerBase = ::kalmia::filter::KalFilterBase<Prescaler_Div>;

} // namespace controller
} // namespace kalmia
#endif