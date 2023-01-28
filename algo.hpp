#ifndef ALGO_HPP 
# define ALGO_HPP

#include <utility>

namespace ft
{
	template <class InputIterator1, class InputIterator2>
		bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
		{
			while (first1!=last1) {
				if (!(*first1 == *first2))
					return false;
				++first1; ++first2;
			}
			return true;
		}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
		bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
		{
			while (first1!=last1) {
				if (!pred(*first1,*first2))
					return false;
				++first1; ++first2;
			}
			return true;
		}


	template <class U, class V> 
		struct pair
		{
			typedef U first_type;
			typedef V second_type;
			U first;
			V second;

			pair() {}
			pair (const pair<U,V>& pr)
			{
				first = pr.first;
				second = pr.second;
			}
			pair (const first_type& a, const second_type& b)
			{
				first = a;
				second = b;
			}
			pair& operator= (const pair& pr)
			{
				first = pr.first;
				second = pr.second;
				return (*this);
			}
		};

	template <class T1,class T2>
		pair<T1,T2> make_pair (T1 x, T2 y)
		{
			return ( pair<T1,T2>(x,y) );
		}

	template <class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return (lhs.first==rhs.first && lhs.second==rhs.second);
		}

	template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return !(lhs==rhs);
		}

	template <class T1, class T2>
		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{
			return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
		}
	template <class T1, class T2>
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return !(rhs<lhs);
		}
	template <class T1, class T2>
		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return rhs<lhs;
		}
	template <class T1, class T2>
		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return !(lhs<rhs);
		}
}//ft ends here
#endif 
