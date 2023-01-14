#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
#include <stdexcept>


namespace ft
{
  template <class T>
  class iterator
  {
    public:
      typedef typename std::random_access_iterator_tag    iterator_category ;
      typedef T                                           value_type;
      typedef typename std::ptrdiff_t                     difference_type;
      typedef T*                                          pointer;
      typedef T&                                          refrence;

      pointer add;
      refrence ref;
      value_type val;

      iterator();
      ~iterator();
      iterator (const iterator& it);
      iterator& operator = (const iterator& it);
      bool operator < (const iterator& it);
      value_type operator * ()const ;
      value_type operator ++ (); 
      value_type operator ++ (int); 
  };

  template <class T>
  iterator<T>::iterator() : add(NULL), ref(*add)
  {
  }
  
  template <class T>
  iterator<T>::~iterator()
  {}

   template<class T>
  typename iterator<T>::value_type iterator<T>::operator * () const
  {
    return (this->val);
  }

  template<class T>
  typename iterator<T>::value_type iterator<T>::operator++ ()
  {
    this->add++; 
    this->val = (*add);
    return (*this);
  }


  template<class T>
  typename iterator<T>::value_type iterator<T>::operator++ (int)
  {
    iterator cp(*this);
    ++(*this);
    return (cp);
  }

  template<class T>
  bool iterator<T>::operator < (const iterator& it)
  {
    if (this->val < it.val)
      return true;
    return false;
  }
  
  template<class T>
  iterator<T>& iterator<T>::operator = (const iterator<T>& it)
  {
    this->add = it.add;
    this->add = it.val;
  }

  template<class T>
  iterator<T>::iterator (const iterator<T>& it)
  {
    this->add = it.add;
    this->add = it.val;
  }

}// end of namespace scope;
#endif  
