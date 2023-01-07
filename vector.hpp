
#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <iterator>
#include <memory>
#include <vector>


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
      typedef typename allocator_type::size_type            size_type;
      typedef typename allocator_type::difference_type      difference_type;
      typedef typename allocator_type::pointer              pointer;
      typedef typename allocator_type::const_pointer        const_pointer;

      // typedef implementation-defined                  iterator;
      // typedef implementation-defined                     const_iterator;
      // typedef std::reverse_iterator<iterator>            reverse_iterator;
      // typedef std::reverse_iterator<const_iterator>      const_reverse_iterator;
      typedef typename std::iterator<std::input_iterator_tag, T> InputIterator;

    
    private:
      allocator_type _alloc;
      pointer  _begin;
      pointer  _end; 
      pointer  _end_cap;

    public:
      /****************************Member functions***********************/
      explicit vector (const allocator_type& alloc = allocator_type());
      explicit vector (size_type n, const value_type& val = value_type(),   
                          const allocator_type& alloc = allocator_type());
      template <class InputIterator>
           vector (InputIterator first, InputIterator last,
                   const allocator_type& alloc = allocator_type());
      // void  assign(size_t count, const T& value);
      // template < class InputIT >
      // void assign(InputIT first,InputIT last);

      // allocator_type get_allocator() const;

      // /*****************************{ Element access }***********************/
      // value_type& at( size_t pos );
      // const_reference at( size_t pos ) const;
  };
  template <class T, class Allocator >
  vector<T, Allocator >::vector(const Allocator& alloc ):_alloc(alloc), _begin(NULL), _end(NULL), _end_cap(NULL)
  {}

  template <class value_type, class allocator_type>
  vector<value_type, allocator_type >::vector (size_type n, const value_type& val ,const allocator_type& alloc) :_alloc(alloc), _begin(NULL), _end(NULL), _end_cap(NULL)
  {
    _begin = _alloc.allocate(n);
    for (size_type i; i < n; i++)
      _alloc.construct(_begin + i, val);
    _end = _begin + n;
    _end_cap = _begin + n;
  }

  template <class value_type, class allocator_type>
  template <class InputIterator>
  vector<value_type, allocator_type>::vector (InputIterator first, InputIterator last, const allocator_type& alloc) :_alloc(alloc), _begin(NULL), _end(NULL), _end_cap(NULL)
  {
    int n = last - first;

  _begin = _alloc.allocate(n);
  for (int i; i < n; i++)
      _alloc.construct(_begin + i, *first + i);
    _end = _begin + n;
    _end_cap = _begin + n;

    //initialize based on iterators  
  }

}
// #include "vector.tpp"
#endif 
