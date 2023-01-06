
#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

namespace ft
{
  template < class T, class Allocator = std::allocator<T> >
  class vector
  {
    /****************************Member functions***********************/
    vector();
    ~vector();
    vector& operator = (const vector& vec);
    void  assign(size_type count, const T& value);
    template < class InputIT >  
    void assign(InputIT first,InputIT last);
    allocator_type get_allocator() const;
    
    /*****************************Element access***********************/

  }
  

}

#endif 
