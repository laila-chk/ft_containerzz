#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR

#include "iterator.hpp"

namespace ft 
{
	template <class Iterator>
		class reverse_iterator 
		{
			protected:
				Iterator  It;
			public:
				typedef Iterator												iterator_type;
				typedef typename iterator_traits<Iterator>::difference_type		difference_type;
				typedef typename iterator_traits<Iterator>::reference			reference;
				typedef typename iterator_traits<Iterator>::pointer				pointer;

				/**************************    {construction }****************************/
				reverse_iterator() {}
				explicit reverse_iterator(Iterator x);
				template <class U> 
					reverse_iterator(const reverse_iterator<U>& u);

				/**************************    {operators }****************************/
				Iterator base() const;
				reference operator*() const;
				pointer operator->() const;
				reverse_iterator& operator++() 
				{
					this->It--;
				}
				reverse_iterator operator++(int);
				reverse_iterator& operator--();
				reverse_iterator operator--(int);
				reverse_iterator operator+ (difference_type n) const;
				reverse_iterator& operator+=(difference_type n);
				reverse_iterator operator- (difference_type n) const;
				reverse_iterator& operator-=(difference_type n);
				reference operator[](difference_type n) const;

		};

	template <class Iterator>
		reverse_iterator<Iterator>::reverse_iterator(Iterator x)
		{
			this->It = x;	
		}

	template <class Iter> 
		template <class U> 
		reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<U>& u)
		{
			It = u.It;
		}

} //end of ft

#endif
