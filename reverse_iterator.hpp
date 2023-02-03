#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR

#include "iterator.hpp"
#include <functional>

namespace ft 
{
	template <class Iterator>
		class reverse_iterator 	
		{
			protected:
				Iterator  It;
			public:
				typedef Iterator															iterator_type;
				typedef std::random_access_iterator_tag										iterator_category;
				typedef typename std::iterator_traits<Iterator>::difference_type			difference_type;
				typedef typename std::iterator_traits<Iterator>::value_type					value_type;
				typedef typename std::iterator_traits<Iterator>::reference					reference;
				typedef typename std::iterator_traits<Iterator>::pointer					pointer;
				typedef const reference														const_reference;
				typedef const pointer														const_pointer;
				
				/**************************    {construction }****************************/
				reverse_iterator() {}
				explicit reverse_iterator(Iterator x);
				template <class U> 
					reverse_iterator(const reverse_iterator<U>& u);
				/**************************    {operators }****************************/
				Iterator base() const
				{
					return (Iterator(It));
				}

				reference operator*() const
				{
					return (*It);
				}
				pointer operator->() const
				{
					return It.operator->() ;	
				}
				reverse_iterator& operator++() 
				{
					this->It--;
					return (*this);
				}
				reverse_iterator operator++(int)
				{
					reverse_iterator ret = *this;
					this->It--;
					return (ret);
				}

				reverse_iterator& operator--() 
				{
					this->It++;
					return (*this);
				}
				reverse_iterator operator--(int)
				{
					reverse_iterator ret = *this;
					this->It++;
					return (ret);
				}
				reverse_iterator operator+ (difference_type n) const{

				 return reverse_iterator (this->base() -n + 1);
				}

				reverse_iterator& operator+= (difference_type n) {
					It -= n;
					return (*this);
				}

				reverse_iterator operator- (difference_type n) const{
					 return reverse_iterator (this->base() + n +1);
				}

				reverse_iterator& operator-=(difference_type n) {
					It += n;
					return (*this);
				}

				reference operator[](difference_type n) const
				{
					reverse_iterator ret = *this;
					ret += n;
					return (*ret);
				}

		};

	template <class Iterator>
		reverse_iterator<Iterator>::reverse_iterator(Iterator x)
		{
			this->It = --x;	
		}

	template <class Iter> 
		template <class U> 
		reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<U>& u)
		{
			It = u.base();
		}

	template <class Iterator>
		bool operator==( const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			if(x.base() == y.base())
				return true;
			return false;
		}

	template <class U, class V>
		bool operator<( const reverse_iterator<V> &x, const reverse_iterator<U> &y){
			return (x.base() > y.base());
		}

	template <class U, class V>
		bool operator!=( const reverse_iterator<V> &x, const reverse_iterator<U> &y)
		{
			return (x.base() != y.base());
		}
	template <class U, class V>
		bool operator>( const reverse_iterator<V> &x, const reverse_iterator<U> &y)
		{
			return (x.base() < y.base());
		}
	template <class U, class V>
		bool operator>=( const reverse_iterator<V> &x, const reverse_iterator<U> &y){
			return (x.base() <= y.base());
		}

	template <class U, class V>
		bool operator<=( const reverse_iterator<V> &x, const reverse_iterator<U> &y)
		{
			return (x.base() >= y.base());
		}
	
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return (y.base() - x.base());
		}

	template <class Iterator>
		reverse_iterator<Iterator> operator+( typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x)
		{
			 return reverse_iterator <Iterator>(x.base() - n +1);
		}

	template <class U, class V>
		bool operator== (reverse_iterator<U> &u, reverse_iterator<V> &v)
		{
			return (u.base() == v.base());
		}

} //end of ft

#endif
