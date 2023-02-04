#include <iostream>
#include <iterator>
#include <vector>
#include "reverse_iterator.hpp"
#include "vector.hpp"

int main()
{
	ft::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	ft::vector<int>::reverse_iterator it(v.end());
	std::cout << *it << std::endl;

}
