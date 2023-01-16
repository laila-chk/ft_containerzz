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
      typedef std::random_access_iterator_tag             iterator_category ;
      typedef T                                           value_type;
      typedef std::ptrdiff_t                              difference_type;
      typedef T*                                          pointer;
      typedef T&                                          refrence;

      pointer add;

    /*-------------------------------------------{ construction }----------------------------------------------*/
      iterator();
      iterator (const iterator& it);
      iterator& operator = (const iterator& it);
      ~iterator();
    /*-------------------------------------------{ comparision }----------------------------------------------*/
      bool operator < (const iterator& it) const;
      bool operator > (const iterator& it)const ;
      bool operator >= (const iterator& it)const ;
      bool operator <= (const iterator& it)const ;
      bool operator == (const iterator& it)const ;
      bool operator != (const iterator& it)const ;
    /*-------------------------------------------{ accessors }----------------------------------------------*/
      value_type operator * ()const ;
      value_type operator -> ()const ;
      value_type operator[] (unsigned int i)const ;
    /*-------------------------------------------{ increment & dec }----------------------------------------------*/
      iterator& operator ++ (); 
      iterator operator ++ (int); 
      iterator& operator-- (); 
      iterator operator-- (int); 
    /*-------------------------------------------{ operations }----------------------------------------------*/
      iterator operator + (int n);
      iterator operator - (int n);
    /*-------------------------------------------{ assignements }----------------------------------------------*/
      iterator& operator += (int n);
      iterator& operator -= (int n);

  };

  template<class T>
  iterator<T>& iterator<T>::operator += (int n)
  {
    this->add += n;
    return (*this);
  }

  template<class T>
  iterator<T>& iterator<T>::operator -= (int n)
  {
    this->add -= n;
    return (*this);
  }

  template<class T>
  iterator<T> iterator<T>::operator + (int n)
  {
    iterator<T> it = *this;
    it.add += n;
    return (it);
  }

  template <class T>
  iterator<T> operator + (int n, iterator<T>& it)
  {
    iterator<T> ret(it);
    return (ret + n);
  }

  template<class T>
  iterator<T> iterator<T>::operator - (int n)
  {
    iterator<T> it = *this;
    it.add -= n;
  return (it);
  }
  template <class T>
  iterator<T> operator - (int n, iterator<T>& it)
  {
    iterator<T> ret(it);
    return (ret - n);
  }

  template <class T>
  iterator<T>::iterator() : add(NULL)
  {
  }
  
  template <class T>
  iterator<T>::~iterator()
  {}

  
  template<class T>
  iterator<T>::iterator (const iterator<T>& it)
  {
    this->add = it.add;
    // this->add = it.val;
  }

  template<class T>
  typename iterator<T>::value_type iterator<T>::operator * () const
  {
    return (*add);
  }

  template<class T>
  typename iterator<T>::value_type iterator<T>::operator[] (unsigned int i)const 
  {
    return *(add + i);
  }

  template<class T>
  typename iterator<T>::value_type iterator<T>::operator -> () const
  {
    return (add);
  }


  template<class T>
  iterator<T>& iterator<T>::operator++ ()
  {
    this->add++; 
    return (*this);
  }


  template<class T>
  iterator<T> iterator<T>::operator++ (int)
  {
    iterator<T> tmp=*this;
    this->add++;
    return (tmp);
  }

  template<class T>
  iterator<T>& iterator<T>::operator-- ()
  {
    this->add--; 
    return (*this);
  }


  template<class T>
  iterator<T> iterator<T>::operator-- (int)
  {
    iterator<T> tmp=*this;
    this->add--;
    return (tmp);
  }

  template<class T>
  bool iterator<T>::operator < (const iterator& it) const
  {
    if (this->add < it.add)
      return true;
    return false;
  }

  template<class T>
  bool iterator<T>::operator > (const iterator& it) const
  {
    if (this->add > it.add)
      return true;
    return false;
  }
  
  template<class T>
  bool iterator<T>::operator <= (const iterator& it) const
  {
    if (this->add <= it.add)
      return true;
    return false;
  }

  template<class T>
  bool iterator<T>::operator >= (const iterator& it) const
  {
    if (this->add >= it.add)
      return true;
    return false;
  }
  
  template<class T>
  bool iterator<T>::operator == (const iterator& it) const
  {
    if (this->add == it.add)
      return true;
    return false;
  }

  template<class T>
  bool iterator<T>::operator != (const iterator& it) const
  {
    if (this->add != it.add)
      return true;
    return false;
  }
  
  template<class T>
  iterator<T>& iterator<T>::operator = (const iterator<T>& it)
  {
    this->add = it.add;
    return (*this);
  }

}// end of namespace scope;
#endif  
