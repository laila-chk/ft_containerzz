/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <lchokri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:05:56 by lchokri           #+#    #+#             */
/*   Updated: 2023/01/18 00:28:52 by lchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
#include <stdexcept>
#include "iterator.hpp"
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
      // typedef implementation-defined                  iterator;
      // typedef implementation-defined                     const_iterator;
      // typedef std::reverse_iterator<iterator>            reverse_iterator;
      // typedef std::reverse_iterator<const_iterator>      const_reverse_iterator;
      
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
       for (InputIt it = first; it != last; it++)
        this->push_back(*it);
      }
      vector(const vector& other);


      vector& operator=( const vector& other );
      ~vector();




      allocator_type get_allocator() const;
      void assign(size_type count, const value_type& value);
     template< class InputIt >
      void assign( InputIt first, InputIt last );

    /****************************{ Element accessors }*(done Writing..)********************************/
      reference operator[]( size_type pos );
      const_reference operator[]( size_type pos ) const;
      reference front();
      const_reference front() const;
      reference back();
      const_reference back() const;
      reference at( size_type pos );
      const_reference at( size_type pos ) const;
      T* data();
      const T* data() const;


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
      

    /****************************{ iterator class }***************************************/
      iterator begin();
      iterator end();

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
  vector<value_type, allocator_type>& vector<value_type, allocator_type>:: operator=(const vector& other)
  {
    if (other.size() > this->capacity())
      this->reserve(other.capacity());
    if (_begin)
      _alloc.deallocate(_begin, _end_cap - _begin);
    for (size_type i = 0; i < other.size(); i++)
      _alloc.construct(_begin + i, other[i]);
    return (*this);
  }

    /****************************Member functions***********************/
   template <class value_type, class allocator_type>
  void vector<value_type, allocator_type >::assign(size_type count, const value_type& value)
  {
    for (size_type i = 0; i < size(); i++)
        this->_alloc.destroy(_begin + i);
    if (count > capacity())
    {
      if (_begin)
        this->_alloc.deallocate(_begin, capacity());
      _begin = _alloc.allocate(count);
    }
      for (size_type i = 0; i < count; i++)
        _alloc.construct(_begin + i, value);
      _end = _begin + count;
      _end_cap = _begin + count;
  }


  template <class value_type, class allocator_type>
  typename vector<value_type, allocator_type>::allocator_type vector<value_type, allocator_type>::get_allocator() const
  {
    return (_alloc); 
  }

  /**************************************************{ Element accessors }*(done Writing..)****************************************/
  template<class value_type, class allocator_type>
  typename vector<value_type, allocator_type>::const_reference  vector<value_type, allocator_type>::operator[](size_t pos) const
  {
    return (*(_begin + pos));
  }

  template<class value_type, class allocator_type>
  typename vector<value_type, allocator_type>::reference  vector<value_type, allocator_type>::operator[](size_t pos)
  {
    return (*(_begin + pos));
  }

  template <class value_type, class allocator_type>
  typename vector<value_type, allocator_type>::reference  vector<value_type, allocator_type>::front()
  {
    return (*_begin);
  }
  
  template <class value_type, class allocator_type>
  typename vector<value_type, allocator_type>::const_reference  vector<value_type, allocator_type>::front() const
  {
    return (*_begin);
  }
  

  template <class value_type, class allocator_type>
   typename vector<value_type, allocator_type>::reference  vector<value_type, allocator_type>::back() 
  {
    return (*(_end - 1));
  }
 
  template <class value_type, class allocator_type>
   typename vector<value_type, allocator_type>::const_reference  vector<value_type, allocator_type>::back() const
  {
    return (*(_end - 1));
  }

   template <class value_type, class allocator_type>
   typename vector<value_type, allocator_type>::reference  vector<value_type, allocator_type>::at(size_type pos) 
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
  
  template <class T, class allocator_type>
  T* vector<T, allocator_type>::data()
  {
    return (_begin);
  }

  template <class T, class allocator_type>
  const T* vector<T, allocator_type>::data() const
  {
    return (_begin);
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
      if (count > capacity() * 2)
        reserve(count);
      else
        reserve(capacity() * 2);
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
      resize(size() + 1, value);
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
  typename vector<T, allocator_type>::iterator vector<T, allocator_type>::end(void)
  {
    iterator it;
    it.add = _end;
    return (it);
  }

} //end of namespace ft


#endif 
