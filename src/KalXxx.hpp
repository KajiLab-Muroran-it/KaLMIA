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

// KalXxx.hpp
// This is a class library header template.
// Rename "Xxx" and "XXX"(Upper case, use for #define directive) in this file to your class name.
// Also, Write description of file/class here.

// Include guard 
#ifndef KALXXX_HPP
#define KALXXX_HPP

namespace kalmia {
	class KalXxx : kalmia::util::KalNoncopyable{
	public:
		virtual ~KalXxx() = default;
		
	};
}

// If you used templates in your class/function,
// you'll need to include implementations of them in this file.
// In such case, comment-out or delete #ifdef and 1st #endif line.
// Don't delete #include line, and 2nd #endif line!
#ifdef KALMIA_HEADER_ONLY
#include "KalXxx.cpp"
#endif
#endif