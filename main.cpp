#include <iostream>
#include <iterator>
#include <vector>
#include "reverse_iterator.hpp"
#include "vector.hpp" 

int main()
{
	/*
	{
		std::vector<int> a(5,5);
#define iter std::reverse_iterator<std::vector<const int>::iterator> 
		iter cit(a.end());
#define riter std::reverse_iterator<std::vector<int>::iterator>
		riter it(a.end());
		if (cit == it)
			std::cout << "equal" << std::endl;
	}
	*/
std::cout << "--------------------------------------" << std::endl;
	{
		std::vector<int> a(5,5);
#define iter ft::reverse_iterator<std::vector<const int>::iterator> 
		iter cit(a.end());
#define riter ft::reverse_iterator<std::vector<int>::iterator>
		riter it(a.end());
		if (cit == it)
			std::cout << "equal" << std::endl;
	}
}

