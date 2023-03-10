#include <iostream>
#include <vector>
#include "vector.hpp"

int main ()
{         
	std::string str, ft_str;
	/*
	 * var to store the size and the capacity
	 */
	ft::vector<std::string>::size_type s, ft_s;
	ft::vector<std::string>::size_type c, ft_c;
	ft::vector<std::string>::iterator ft_it;
	std::vector<std::string>::iterator it;
	/*
	 * bool to store the comparison
	 */
	bool cond;


	std::vector<std::string> v(20, "string");
	ft::vector<std::string> ft_v(20, "string");
	ft::vector<std::string>::iterator valid_it;

	valid_it = ft_v.begin();
	it = v.insert(v.begin() + 10, "hello");
	ft_it = ft_v.insert(ft_v.begin() + 10, "hello");
	ft_it->length();

	str.clear();
	ft_str.clear();
	s = v.size();
	ft_s = ft_v.size();
	c = v.capacity();
	ft_c = ft_v.capacity();
	for (size_t i = 0; i < v.size(); ++i)
		str += v[i];
	for (size_t i = 0; i < ft_v.size(); ++i)
		ft_str += ft_v[i];
	std::cout << std::endl;
	std::cout << &(*it) << "  " << &(*ft_it) << std::endl;
	std::cout << &(*(v.begin()+10))<< "  " << &(*(ft_v.begin()+10) ) << std::endl;
	cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it) && (&(*valid_it) == &(*ft_v.begin())));


	return 0;
}
