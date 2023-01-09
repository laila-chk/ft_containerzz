
#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
#include <stdexcept>


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
/*      template <class InputIterator>
      vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :_alloc(alloc), _begin(NULL), _end(NULL), _end_cap(NULL)
      {
      int n = last - first;

      _begin = _alloc.allocate(n);
      for (int i= 0; i < n; i++)
        _alloc.construct(_begin + i, *first + i);
      _end = _begin + n;
      _end_cap = _begin + n;
     }

     template< class InputIt >
      void assign( InputIt first, InputIt last );

*/
      void assign(size_type count, const value_type& value);
      size_type capacity() const;
      bool empty() const;
      size_type size() const;
      size_type max_size() const;
      void reserve( size_type new_cap);
      reference operator[]( size_type pos );


    /********************************************************************************/
  };

  template <class T, class Allocator >
  vector<T, Allocator >::vector(const Allocator& alloc ):_alloc(alloc), _begin(NULL), _end(NULL), _end_cap(NULL)
  {}

  template <class value_type, class allocator_type>
  vector<value_type, allocator_type >::vector (size_type n, const value_type& val ,const allocator_type& alloc) :_alloc(alloc)
  {
    _begin = _alloc.allocate(n);
    for (size_type i = 0; i < n; i++)
      _alloc.construct(_begin + i, val);
    _end = _begin + n;
    _end_cap = _begin + n;
  }
  
  template <class value_type, class allocator_type>
  void vector<value_type, allocator_type >::assign(size_type count, const value_type& value)
  {
    for (int i = 0; i < _end - _begin; i++)
        this->_alloc.destroy(_begin + i);
    if (count > _end_cap - _begin)
    {
      this->deallocate(_begin, _end_cap - _begin);
      _begin = _alloc.allocate(count);
    }
      for (size_type i = 0; i < count; i++)
        _alloc.construct(_begin + i, value);
      _end = _begin + count;
      _end_cap = _begin + count;
  }

  template <class value_type, class allocator_type>
  size_t vector<value_type, allocator_type>::size() const
  {
    return (_end - _begin);  
  }

  template <class value_type, class allocator_type>
  size_t vector<value_type, allocator_type>::max_size() const
  {
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
    if (_end - _begin == 0)
      return true;
    return false;
  }

  template <class value_type, class allocator_type>
  void vector<value_type, allocator_type>::reserve(size_type new_cap)
  {
     if (new_cap > this->max_size())
      throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");

    if (new_cap >= (unsigned long)(_end_cap - _begin))
    {
      size_type n = this->size();
      pointer new_beg = _alloc.allocate(new_cap);
      for (size_type i = 0; i < n; i++)
      {
        _alloc.construct(new_beg + i, *(_begin + i));
        this->_alloc.destroy(_begin + i);
      }
      this->_alloc.deallocate(_begin, _end_cap - _begin);
      _begin = new_beg;
      _end = new_beg + n;
      _end_cap = new_beg + new_cap;
    } 
  }

  template<class value_type, class allocator_type>
  typename vector<value_type, allocator_type>::reference  vector<value_type, allocator_type>::operator[](size_t pos)
  {
    //code code code ..
  }

} //end of namespace ft
// #include "vector.tpp"
#endif 
