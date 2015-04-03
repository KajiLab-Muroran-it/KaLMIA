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

// KalQueue.hpp
#ifndef KALQUEUE_HPP
#define KALQUEUE_HPP

#include<queue>

namespace kalmia {
	template <class T, class Container = std::deque<T>>
	class KalQueue{
	public:
		virtual ~KalQueue() = default;
	
		bool empty () const;
		unsigned int size () const;
		T& front ();
		const T& front () const;
		T& back ();
		const T& back () const;
		void push (T const &val);
		void pop ();
		T const& total ();

		// emplace and swap is not implemented yet...

	private:
		KalQueue(KalQueue&&) = delete;
		KalQueue& operator =(KalQueue const&) = delete;
		KalQueue& operator =(KalQueue&&) = delete;
		std::queue<T, Container> q;
		T sum;
	};
}

#include "KalQueue.cpp"
#endif