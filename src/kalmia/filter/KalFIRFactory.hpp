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
#include "kalmia/filter/KalFilterSMA.hpp"
#include "kalmia/filter/KalFilterFIR.hpp"
#include "kalmia/filter/KalFilterCA.hpp"

namespace kalmia {
namespace filter {

// SMA: Simple Moving Average
template <size_t N, size_t Prescaler_Dim = 1>
std::unique_ptr<KalFilterSMA<N, Prescaler_Dim>> GenerateKalFilterSMA () { return std::make_unique<KalFilterSMA<N, Prescaler_Dim>> (); }

// LWMA: Linear Weighted Moving Average
template <size_t N, size_t Prescaler_Dim = 1>
std::unique_ptr<KalFilterFIR<N, Prescaler_Dim>> GenerateKalFilterLWMA ();

// EMA: Exponential Moving Average
template <size_t N, size_t Prescaler_Dim = 1>
std::unique_ptr<KalFilterFIR<N, Prescaler_Dim>> GenerateKalFilterEMA (double alpha);

// MMA: Modified Moving Average
template <size_t N, size_t Prescaler_Dim = 1>
inline std::unique_ptr<KalFilterFIR<N, Prescaler_Dim>> GenerateKalFilterMMA (){ return GenerateKalFilterEMA<N, Prescaler_Dim> (1. / N); }

// LPC: Linear Phase Characteristic filter
template <size_t N, class InputIterator, size_t Prescaler_Dim = 1>
std::unique_ptr<KalFilterFIR<N, Prescaler_Dim>> GenerateKalFilterLPC (InputIterator coefficient_begin, InputIterator coefficient_end);

// CA: Cumulative moving Average (=overall average)
template <size_t Prescaler_Dim = 1>
std::unique_ptr<KalFilterCA<Prescaler_Dim>> GenerateKalFilterCA () { return std::make_unique<KalFilterCA<Prescaler_Dim>> (); }
} // namespace filter
} // namespace kalmia

#include "KalFIRFactory.cpp"
#endif
