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

// KalNoncopyable.hpp

// Noncopyable base class, which is similar to boost.KalNoncopyable.
// In fact, I want to use boost.KalNoncopyable
// But I don't sure how to include it into my library in a reasonable way
// (It not stands by headerfile itself, but also requires another header files in boost... ;P)


#ifndef KALNONCOPYABLE_HPP
#define KALNONCOPYABLE_HPP

namespace kalmia {
namespace util {
class KalNoncopyable {
protected:
	KalNoncopyable () = default;
	virtual ~KalNoncopyable () = default;

	KalNoncopyable (const KalNoncopyable&) = delete;
	KalNoncopyable& operator=(const KalNoncopyable&) = delete;
};
}
}
#endif