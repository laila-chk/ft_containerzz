/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <lchokri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:05:56 by lchokri           #+#    #+#             */
/*   Updated: 2023/02/11 19:38:30 by lchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "algo.hpp"
#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <list>


namespace ft
{  
 
  template <class T, class Allocator = std::allocator<T> >
  class vector
  {
    public :
      /****************************{ namedefs }***********************/
      typedef T                                             value_type;
      typedef Allocator                                     allocator_type;
      typedef typename allocator_type::reference            reference;
      typedef typename allocator_type::const_reference      const_reference;
      typedef size_t                                        size_type;
      typedef typename allocator_type::difference_type      difference_type;
      typedef typename allocator_type::pointer              pointer;
      typedef typename allocator_type::const_pointer        const_pointer;

      typedef typename ft::iterator<T>                      iterator; 
      typedef typename ft::iterator<T>						const_iterator; 
	  typedef typename ft::reverse_iterator<iterator>       reverse_iterator;
	  typedef typename ft::reverse_iterator<iterator>       const_reverse_iterator;
      
    private:
      allocator_type _alloc;
      pointer  _begin;
      pointer  _end; 
      pointer  _end_cap;
      
    public:
      /****************************Member functions***********************/

      /****************************{ Constructors }***********************/
      explicit vector (const allocator_type& alloc = allocator_type());
      explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
      template< class InputIt>
      vector (InputIt first, InputIt last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!is_integral<InputIt>::value, InputIt>::type* = 0): _alloc(alloc), _begin(NULL), _end(NULL), _end_cap(NULL)
      {
		  vector tmp;
       for (InputIt it = first; it != last; it++)
        tmp.push_back(*it);
	   this->_begin = _alloc.allocate(tmp.size());
	   size_type i;
	   for (i = 0; i < tmp.size(); i++)
		   this->_alloc.construct(_begin + i, tmp[i]);
	   _end = _begin + i;
	   _end_cap = _begin + i;
      }
      vector(const vector& other);


      vector& operator=( const vector& other );
      ~vector();

      allocator_type get_allocator() const;
      void assign(size_type count, const value_type& value);

	template< class InputIt >
	void assign(InputIt first, InputIt last, typename ft::enable_if<!is_integral<InputIt>::value, InputIt>::type* = 0)
	{
		vector tmp(first, last);
		this->swap(tmp);
	}

    /****************************{ Element accessors }*(done Writing..)********************************/
      reference operator[]( size_type pos );
      const_reference operator[]( size_type pos ) const;
      reference front();
      const_reference front() const;
      reference back();
      const_reference back() const;
      reference at( size_type pos );
      const_reference at( size_type pos ) const;


    /****************************{ capacity }**(done writing)*************************************/
      bool empty() const;
      size_type size() const;
      size_type max_size() const;
      void reserve( size_type new_cap);
      size_type capacity() const;

    /****************************{ Modifiers }***************************************/
      void clear();
      void pop_back();
      void resize( size_type count, T value = T() );
      void push_back( const T& value );


	  iterator insert(iterator position, const T& x);
	  void insert(iterator pos, size_t n, const T& x);

	  template <class InputIt>
	  void insert(iterator pos, InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value, InputIt>::type* = 0)
	  {
		  if (pos == end())
		  {
			  for (InputIt it = first; it != last; it++)
				  push_back(*it);
			  return;
		  }
		  vector tmp;
		  tmp.reserve(capacity());
		  for (iterator it = begin(); it != end();)
		  {
			  if (it == pos)
			  {
				  for (InputIt cit = first; cit != last; cit++)
					  tmp.push_back(*cit);
			  }
			  tmp.push_back(*it++);
		  }
		  swap(tmp);
	  }

	  iterator erase (iterator pos)
	  {
		  int i = 0;
		  for (iterator it = begin(); it != pos; it++)
			 i++; 
		  for (iterator it = pos; it + 1 != end(); it++)
		  {
			_alloc.destroy(_begin + i);
			_alloc.construct(_begin + i, *(it + 1));
			i++;
		}
		  _alloc.destroy(_begin + i);
		  _end--;
		  return (pos); 
	  }

	  iterator erase (iterator first, iterator last)
	  {
		  vector tmp(begin(), first);
		  tmp.reserve(capacity());
		  iterator ret = tmp.end();
		  for (iterator it = last; it != end(); it++)
			tmp._alloc.construct(tmp._end++, *it);
		  swap(tmp);
		  return (ret);
	  }
	  void swap(vector& x);

    /****************************{ iterator }***************************************/
      iterator begin();
	  const_iterator begin() const;
      iterator end();
	  const_iterator end() const;
	  reverse_iterator rbegin();
	  const_reverse_iterator rbegin() const;
	  reverse_iterator rend();
	  const_reverse_iterator rend() const;

       /********************************************************************************/
};

  /***********************************************{ Constructors }*********************************************************/
  template <class T, class Allocator >
  vector<T, Allocator >::vector(const Allocator& alloc ):_alloc(alloc), _begin(NULL), _end(NULL), _end_cap(NULL)
  {}

  template <class value_type, class allocator_type>
  vector<value_type, allocator_type >::vector (size_type n, const value_type& val ,const allocator_type& alloc) :_alloc(alloc)
  {
    
    if (n > _alloc.max_size())
      throw std::length_error("vector");
    _begin = _alloc.allocate(n);
    for (size_type i = 0; i < n; i++)
      _alloc.construct(_begin + i, val);
    _end = _begin + n;
    _end_cap = _begin + n;
  }

  template<class T, class allocator_type>
  vector<T, allocator_type>::vector(const vector& other):_alloc(other._alloc), _begin(NULL), _end(NULL), _end_cap(NULL)
  {
	size_type n = other.size();
    this->reserve(other.capacity());
    for (size_type i = 0; i < n; i++)
      _alloc.construct(_begin + i, other[i]);
	_end = _begin + n;
  }

  template <class value_type, class allocator_type>
  vector<value_type, allocator_type>::~vector()
  {
    this->clear(); 
    if (_begin)
      this->_alloc.deallocate(_begin, _end_cap - _begin);
    _end = _begin;
  }

   template<class value_type, class allocator_type>
  vector<value_type, allocator_type>& vector<value_type, allocator_type>:: operator=(const vector& x)
  {
	  if (this->size() > 0)
		  this->clear();
	  if (_begin)
		  this->_alloc.deallocate(_begin, capacity());
	  _begin = this->_alloc.allocate(x.capacity());
	  for (size_t i = 0; i < x.size(); i++)
		  this->_alloc.construct(_begin + i, x[i]);
	  _end = _begin + x.size();
	  _end_cap = _begin + x.capacity();
	  return (*this);
  }

    /****************************Member functions***********************/
	template <class value_type, class allocator_type>
	void vector<value_type, allocator_type >::assign(size_type count, const value_type& value)
	{
		// in case u wanted to optimaze: there are two cases: cap <\> count, constructing a tmp depending on each case and swappin is less painful i guess
		for (size_type i = 0; i < size(); i++)
			this->_alloc.destroy(_begin + i);
		if (capacity() < count)
		{
			if (_begin)
				this->_alloc.deallocate(_begin, capacity());
			_begin = _alloc.allocate(count);
		_end_cap = _begin + count;
		}
		for (size_type i = 0; i < count; i++)
			_alloc.construct(_begin + i, value);
		_end = _begin + count;
	}

  template <class value_type, class allocator_type>
  typename vector<value_type, allocator_type>::allocator_type vector<value_type, allocator_type>::get_allocator() const
  {
    return (_alloc); 
  }

  /**************************************************{ Element accessors }*(done Writing..)****************************************/
  template<class value_type, class allocator_type>
  typename vector<value_type, allocator_type>::const_reference vector<value_type, allocator_type>::operator[](size_t pos) const
  {
    return (*(_begin + pos));
  }

  template<class value_type, class allocator_type>
  typename vector<value_type, allocator_type>::reference vector<value_type, allocator_type>::operator[](size_t pos)
  {
    return (*(_begin + pos));
  }

  template <class value_type, class allocator_type>
  typename vector<value_type, allocator_type>::reference vector<value_type, allocator_type>::front()
  {
    return (*_begin);
  }
  
  template <class value_type, class allocator_type>
  typename vector<value_type, allocator_type>::const_reference vector<value_type, allocator_type>::front() const
  {
    return (*_begin);
  }
  

  template <class value_type, class allocator_type>
   typename vector<value_type, allocator_type>::reference vector<value_type, allocator_type>::back() 
  {
    return (*(_end - 1));
  }
 
  template <class value_type, class allocator_type>
   typename vector<value_type, allocator_type>::const_reference vector<value_type, allocator_type>::back() const
  {
    return (*(_end - 1));
  }

   template <class value_type, class allocator_type>
   typename vector<value_type, allocator_type>::reference vector<value_type, allocator_type>::at(size_type pos) 
  {
    if (pos >= size())
      throw std::out_of_range("vector");
    return (*(_begin + pos));
  }
  
  template <class value_type, class allocator_type>
   typename vector<value_type, allocator_type>::const_reference  vector<value_type, allocator_type>::at(size_type pos) const
  {
    if (pos >= size())
      throw std::out_of_range("vector");
    return (*(_begin + pos));
  }
  

    /*******************************************{ capacity }*************************************************************/
   
  template <class value_type, class allocator_type>
  size_t vector<value_type, allocator_type>::size() const
  {
    return (_end - _begin);  
  }

  template <class value_type, class allocator_type>
  size_t vector<value_type, allocator_type>::max_size() const
  {
    if (sizeof(value_type) == 1)
      return (_alloc.max_size() / 2);
    return (_alloc.max_size());  
  }

  template <class value_type, class allocator_type>
  size_t vector<value_type, allocator_type>::capacity() const
  {
    return (_end_cap - _begin);  
  }

   template <class value_type, class allocator_type>
  bool vector<value_type, allocator_type>::empty() const
  {
    if (_end == _begin)
      return true;
    return false;
  }

 template <class value_type, class allocator_type>
  void vector<value_type, allocator_type>::reserve(size_type new_cap)
  {
    if (new_cap > capacity())
    {
      size_type n = this->size();
      pointer new_beg = _alloc.allocate(new_cap);
      for (size_type i = 0; i < n; i++)
      {
        _alloc.construct(new_beg + i, *(_begin + i));
        this->_alloc.destroy(_begin + i);
      }
      if (_begin)
        this->_alloc.deallocate(_begin, _end_cap - _begin);
      _begin = new_beg;
      _end = new_beg + n;
      _end_cap = new_beg + new_cap;
    } 
  }

    /**************************************************************{ Modifiers }********************************************************/

  template <class T, class allocator_type>
  void vector<T, allocator_type>::clear()
  {
    for (size_type i = 0; i < this->size(); i++)
      _alloc.destroy(_begin + i);
    _end = _begin; 
  }
  
  template <class value_type, class allocator_type>
  void vector<value_type, allocator_type>::pop_back()
  {
    _end--;
    _alloc.destroy(_end);
  }

  template <class T, class allocator_type>
  void vector<T, allocator_type>::resize( size_type count, T value)
  {
    if (count < this->size()) 
    {
     for (size_type i = size(); i > count; i--)
       this->pop_back();
      _end = _begin + count;
    }
    else if (count > size())
    {
      if (count > capacity())
        reserve(count);
      else
        reserve(capacity());
      for(pointer i = _end; i < _begin + count; i++)
        _alloc.construct(i, value);
      _end = _begin +  count;
    }
  }

  template <class T, class allocator_type>
  void vector<T, allocator_type>::push_back( const T& value ) 
  {
    if (size() < capacity())
	{
		_alloc.construct(_end, value);
		_end++;
	  }
    else
	{
		if (capacity() != 0)
			reserve(2*capacity());
		else
			reserve(1);
		_alloc.construct(_end, value);
		_end++;
	}
  }

  template <class T, class allocator_type>
  void vector<T, allocator_type>::swap (vector& x)
  {
 	std::swap(this->_begin, x._begin); 
	std::swap(this->_end, x._end);
	std::swap(this->_end_cap, x._end_cap);
	std::swap(this->_alloc, x._alloc);
  }

	template <typename T>
	void swap(T& a, T& b)
	{
	  T hold = a;
	  a = b;
	  b = hold;
	}

  template <class T, class allocator_type>
	 typename vector<T, allocator_type>::iterator vector<T, allocator_type>::insert(iterator pos, const T& x)
  {
	  if (pos == end())
	  {push_back(x); return (end() - 1);}
	   if (this->capacity() < this->size() + 1)
		{
		  difference_type distance = pos - this->begin();
		   this->reserve((this->capacity())* 2);
		  pos = this->begin() + distance;
	}
	   int i = 0;
	   _end++;
	   //the problem is in end, after resizing we write into smth we didnot allocate properrly Probably!!
	  for (iterator it = end(); it != begin() - 1 ; it--)
	  {
		  if (it == pos)
		  {
			  if (it != end() -1)
				  _alloc.destroy(_end - i); 
			_alloc.construct(_end - i++, x);
		  }
		  if (it > pos)
		  {
			  if (it != end()-1)
				  _alloc.destroy(_end - i); 
			_alloc.construct(_end - i, *(it -1));
		  }
		  i++;
	  }
	  return (pos);
  }


		template <class T, class allocator_type>
	void vector<T, allocator_type>::insert(iterator pos, size_t n, const T& x)
	{
		vector tmp;
		if (!capacity())
			tmp.reserve(n);
		if (this->capacity() < this->size() + n)
		{
			if (capacity())
				tmp.reserve((capacity())* 2);
			std::cout << capacity() << "****"<< std::endl;
			std::cout << tmp.capacity() << "****" <<std::endl;
		}
		size_t i = 0;
		for (iterator it = begin(); it != end() +1; it++)
		{
			if (it == pos)
			{
				for (size_t j = 0; j < n; j++)
				{
					tmp._alloc.construct(tmp._begin + i++, x);
				}
			}
			if (it < end())
				tmp._alloc.construct(tmp._begin + i, *it);
			i++;
		}
		tmp._end += n;
		swap(tmp);
		std::cout << size() << "~~XX~~"<< std::endl;
		std::cout << capacity() << "~~~~~"<< std::endl;
		std::cout << tmp.capacity() << "~~~~" <<std::endl;
	}




  /*********************************************{ iterator class }********************************************************/
  template <class T, class allocator_type>
  typename vector<T, allocator_type>::iterator vector<T, allocator_type>::begin(void)
  {
    iterator it;
    it.add = _begin;
    return (it);
  }

  template <class T, class allocator_type>
  typename vector<T, allocator_type>::const_iterator vector<T, allocator_type>::begin(void) const
  {
    const_iterator it;
    it.add = _begin;
    return (it);
  }

 template <class T, class allocator_type>
  typename vector<T, allocator_type>::iterator vector<T, allocator_type>::end(void)
  {
    iterator it;
    it.add = _end;
    return (it);
  }

  template <class T, class allocator_type>
  typename vector<T, allocator_type>::const_iterator vector<T, allocator_type>::end(void) const
  {
    const_iterator it;
    it.add = _end;
    return (it);
  }
   
  template <class T, class allocator_type>
  typename vector<T, allocator_type>::reverse_iterator vector<T, allocator_type>::rbegin()
  {
	iterator it = end();
	reverse_iterator rit(it);
	return rit;
  }

  template <class T, class allocator_type>
  typename vector<T, allocator_type>::const_reverse_iterator vector<T, allocator_type>::rbegin() const
  {
	iterator it = end();
	const_reverse_iterator rit(it);
	return rit;
  }

 template <class T, class allocator_type>
  typename vector<T, allocator_type>::const_reverse_iterator vector<T, allocator_type>::rend() const
{
	iterator it = begin();
	const_reverse_iterator rit(it);
	return rit;
  }


  template <class T, class allocator_type>
  typename vector<T, allocator_type>::reverse_iterator vector<T, allocator_type>::rend()
  {
	iterator it = begin();
	reverse_iterator rit(it);
	return rit;
  }

	template <class T, class allocator_type>
	  bool operator== (const vector<T, allocator_type>& lhs, const vector<T, allocator_type>& rhs)
	  {
		  if (lhs.size() == rhs.size())
		  {
			  for (size_t i = 0; i < rhs.size(); i++)
			  {
				  if (rhs[i] != lhs[i])
					  return false;
			  }
			  return true;
		  }
		return (false);
	  }

	template <class T, class allocator_type>
	  bool operator!= (const vector<T, allocator_type>& lhs, const vector<T, allocator_type>& rhs)
	  {
		  return !(rhs == lhs);
	  }

	template <class T, class allocator_type>
	  bool operator < (const vector<T, allocator_type>& lhs, const vector<T, allocator_type>& rhs)
	  {
		  for (size_t i = 0; i < lhs.size(); i++)
		  {
			  if (!lhs.empty() && !rhs.empty())
			  {
				  if (i == rhs.size())
					  break;
					 if (lhs[i] < rhs[i])
						  return true;
					 else if (lhs[i] > rhs[i])
						return false;
			  }
		  }
		  if (lhs.size() < rhs.size())
			  return true;
		  return false;
	  }

	template <class T, class allocator_type>
	  bool operator > (const vector<T, allocator_type>& lhs, const vector<T, allocator_type>& rhs)
	  {
		  return (rhs < lhs);
	  }

	template <class T, class allocator_type>
	  bool operator <= (const vector<T, allocator_type>& lhs, const vector<T, allocator_type>& rhs)
	  {
		  return !(rhs < lhs);
	  }

	template <class T, class allocator_type>
	  bool operator >= (const vector<T, allocator_type>& lhs, const vector<T, allocator_type>& rhs)
	  {
		  return !(lhs < rhs);
	  }

/*
	template <class U, class V>
	bool operator== (iterator<U> &u, iterator <V> &v)
	{
		return (u == v);
	}
	*/

} //end of namespace ft

namespace std
{
	template <class T, class Alloc>
	void swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
};

#endif 
