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
      // iterator& begin();
      // iterator& end();
  };

  template <class T>
  iterator<T>::iterator() : add(NULL)
  {}
  
  // template<class T>
  // iterator& iterator<T>::begin()
  // {}
}
#endif  
