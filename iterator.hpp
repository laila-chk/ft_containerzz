#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <vector>

/*
 *
 *
 *
 * make add private
 *
 *
 *
 *
 * */
namespace ft {
	template <class T> 
		class iterator 
	{
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef T value_type;
			typedef std::ptrdiff_t difference_type;
			typedef T* pointer;
			typedef T& reference;

			pointer add;

			/*-------------------------------------------{ construction	}----------------------------------------------*/
			iterator();
			iterator(pointer a) : add(a) {}
			iterator(const iterator &it);
			iterator &operator=(const iterator &it);
			~iterator();
			/*-------------------------------------------{ comparision }----------------------------------------------*/
			bool operator<(const iterator &it) const;
			bool operator>(const iterator &it) const;
			bool operator>=(const iterator &it) const;
			bool operator<=(const iterator &it) const;
			bool operator==(const iterator &it) const;
			bool operator!=(const iterator &it) const;
			/*-------------------------------------------{ accessors }----------------------------------------------*/
			value_type& operator*() const;
			pointer operator->() const;
			value_type& operator[](unsigned int i) const;
			/*-------------------------------------------{ increment & dec }----------------------------------------------*/
			iterator &operator++();
			iterator operator++(int);
			iterator &operator--();
			iterator operator--(int);
			/*-------------------------------------------{ operations }----------------------------------------------*/
			iterator operator+(int n);
			iterator operator+(const iterator &It);
			iterator operator-(int n);
			difference_type operator- (const iterator &it) const;
			/*-------------------------------------------{ assignements }----------------------------------------------*/
			iterator &operator+=(int n);
			iterator &operator-=(int n);

			/*
			operator iterator<const value_type>()
			 {
			   return iterator<const value_type>(add);
			 }
			 */
	};

	template <class T> iterator<T>::iterator() : add(NULL) {}

	template <class T> iterator<T>::~iterator() {}

	template <class T> iterator<T>::iterator(const iterator<T> &it) {
		this->add = it.add;
	}

	template <class T>
		typename iterator<T>::difference_type iterator<T>::operator- (const iterator &it) const
		{
			return (add - it.add);
		}

	template <class T> iterator<T> &iterator<T>::operator+=(int n) {
		this->add += n;
		return (*this);
	}

	template <class T> iterator<T> &iterator<T>::operator-=(int n) {
		this->add -= n;
		return (*this);
	}

	template <class T> iterator<T> iterator<T>::operator+(int n) {
		iterator<T> it = *this;
		it.add += n;
		return (it);
	}

	template <class T> iterator<T> operator+(int n, iterator<T> &it) {
		iterator<T> ret(it);
		return (ret + n);
	}

	template <class T> iterator<T> iterator<T>::operator-(int n) {
		iterator<T> it = *this;
		it.add -= n;
		return (it);
	}
	template <class T> iterator<T> operator-(int n, iterator<T> &it) {
		iterator<T> ret(it);
		return (ret - n);
	}

	template <class T>
		typename iterator<T>::value_type& iterator<T>::operator*() const {
			return (*add);
		}

	template <class T>
		typename iterator<T>::value_type& iterator<T>::operator[](unsigned int i) const {
			return *(add + i);
		}

	template <class T>
		typename iterator<T>::pointer iterator<T>::operator->()const {
			return (add);
		}

	template <class T> iterator<T> &iterator<T>::operator++() {
		this->add++;
		return (*this);
	}

	template <class T> iterator<T> iterator<T>::operator++(int) {
		iterator<T> tmp = *this;
		this->add++;
		return (tmp);
	}

	template <class T> iterator<T> &iterator<T>::operator--() {
		this->add--;
		return (*this);
	}

	template <class T> iterator<T> iterator<T>::operator--(int) {
		iterator<T> tmp = *this;
		this->add--;
		return (tmp);
	}

	template <class T> bool iterator<T>::operator<(const iterator &it) const {
		if (this->add < it.add)
			return true;
		return false;
	}

	template <class T> bool iterator<T>::operator>(const iterator &it) const {
		if (this->add > it.add)
			return true;
		return false;
	}

	template <class T> bool iterator<T>::operator<=(const iterator &it) const {
		if (this->add <= it.add)
			return true;
		return false;
	}

	template <class T> bool iterator<T>::operator>=(const iterator &it) const {
		if (this->add >= it.add)
			return true;
		return false;
	}

	template <class T> bool iterator<T>::operator==(const iterator &it) const {
		if (this->add == it.add)
			return true;
		return false;
	}

	template <class T> bool iterator<T>::operator!=(const iterator &it) const {
		if (this->add != it.add)
			return true;
		return false;
	}

		template <class T> iterator<T> &iterator<T>::operator=(const iterator<T> &it) {
		this->add = it.add;
		return (*this);
	}

	template <class iterator> struct iterator_traits {
		typedef typename iterator::difference_type difference_type;
		typedef typename iterator::value_type value_type;
		typedef typename iterator::pointer pointer;
		typedef typename iterator::reference reference;
		typedef typename iterator::iterator_category iterator_category;
	};

	template <class T> struct iterator_traits<T *> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class T> struct iterator_traits<const T *> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
	/*********************************************{ Template Specialization
	 * }********************************************************/
	template <class T> struct is_integral {
		static const bool value = false;
	};

	template <> struct is_integral<bool> {
		static const bool value = true;
	};
	template <> struct is_integral<char> {
		static const bool value = true;
	};

	template <> struct is_integral<char16_t> {
		static const bool value = true;
	};

	template <> struct is_integral<char32_t> {
		static const bool value = true;
	};

	template <> struct is_integral<wchar_t> {
		static const bool value = true;
	};

	template <> struct is_integral<signed char> {
		static const bool value = true;
	};

	template <> struct is_integral<short int> {
		static const bool value = true;
	};

	template <> struct is_integral<int> {
		static const bool value = true;
	};

	template <> struct is_integral<long int> {
		static const bool value = true;
	};
	template <> struct is_integral<long long int> {
		static const bool value = true;
	};

	template <> struct is_integral<unsigned char> {
		static const bool value = true;
	};

	template <> struct is_integral<unsigned short int> {
		static const bool value = true;
	};

	template <> struct is_integral<unsigned int> {
		static const bool value = true;
	};

	template <> struct is_integral<unsigned long int> {
		static const bool value = true;
	};

	template <> struct is_integral<unsigned long long int> {
		static const bool value = true;
	};

	/***************************************************{enable
	 * if}*******************************************************/
	template <bool B, class T = void> struct enable_if {};

	template <class T> struct enable_if<true, T> {
		typedef T type;
	};

} // namespace ft
#endif
