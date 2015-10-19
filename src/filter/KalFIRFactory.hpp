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
#include <memory>
#include <algorithm>
#include <numeric>
#include "filter/KalFilterSMA.hpp"
#include "filter/KalFilterFIR.hpp"

namespace kalmia {
namespace filter {

// SMA: Simple Moving Average
template <size_t N>
std::unique_ptr<KalFilterSMA<N>> GenerateKalFilterSMA () { return std::make_unique<KalFilterSMA<N>> (); };

// LWMA: Linear Weighted Moving Average
template <size_t N>
std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterLWMA ();

// EMA: Exponential Moving Average
template <size_t N>
std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterEMA (double alpha);

// MMA: Modified Moving Average
template <size_t N>
inline std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterMMA (){ return GenerateKalFilterEMA (1. / N) };

// LPC: Linear Phase Characteristic filter
template <size_t N, class InputIterator>
std::unique_ptr<KalFilterFIR<N>> GenerateKalFilterLPC (InputIterator coefficient_begin, InputIterator coefficient_end);

} // namespace filter
} // namespace kalmia

#include "KalFIRFactory.cpp"
#endif