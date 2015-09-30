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

// KalFIRFactory.hpp
// Set of pre-defined FIR filter generators.

#ifndef KALFIRFACTORY_HPP
#define KALFIRFACTORY_HPP

#include <array>
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include "filter/KalFilterFIR.hpp"

namespace kalmia {
namespace filter {

// SMA: Simple Moving Average
template <size_t N>
std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterSMA ();

// LWMA: Linear Weighted Moving Average
template <size_t N>
std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterLWMA ();

// EMA: Exponential Moving Average
template <size_t N>
std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterEMA (double alpha);

// MMA: Modified Moving Average
template <size_t N>
inline std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterMMA (){ return GenerateKalFilterEMA (1. / N) };

}
}

#include "KalFIRFactory.cpp"
#endif