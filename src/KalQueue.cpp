/**************************************************************/
/*                                                            */
/*     ================[ KaLMIA Library ]================     */
/*                                                            */
/*            Kaji-Lab Magnifier Integrated Assets            */
/*                                                            */
/*     ============== " Be Ambitious For " ==============     */
/*                                                            */
/*              Muroran Institute of Technology               */
/*      Electronic System Control Engineering Laboratory      */
/*                                                            */
/**************************************************************/

// KalQueue.cpp
#include "KalQueue.hpp"

namespace kalmia {
	template<class T, class Container>
	bool KalQueue<T, Container>::empty () const{
		return q.empty ();
	}

	template<class T, class Container>
	unsigned int KalQueue<T, Container>::size () const{
		return q.size ();
	}

	template<class T, class Container>
	T& KalQueue<T, Container>::front (){
		return q.front ();
	}
	template<class T, class Container>
	const T& KalQueue<T, Container>::front () const{
		return q.front ();
	}

	template<class T, class Container>
	T& KalQueue<T, Container>::back (){
		return q.back ();
	}
	template<class T, class Container>
	const T& KalQueue<T, Container>::back () const{
		return q.back ();
	}

	template<class T, class Container>
	void KalQueue<T, Container>::push (T const &val){
		q.push (val);
		sum += val;
	}

	template<class T, class Container>
	void KalQueue<T, Container>::pop (){
		sum -= q.front();
		q.pop ();
	}
	
	template<class T, class Container>
	T const& KalQueue<T, Container>::total (){
		return sum;
	}
	
}
