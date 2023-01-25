#include <iostream>
#include <vector>
#include "vector.hpp" 

int main()
{
	ft::vector<int> v;
	
	 v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);
	ft::vector<int>::iterator it = v.begin();
	std::cout << "it pointing at: " << *it << std::endl;
	ft::vector<int>::iterator rit = it;
	std::cout << "it pointing at: " << *it << " and rit on: "<< *rit<< std::endl;
	it++;
	std::cout << "it pointing at: " << *it << " and rit on: "<< *rit<< std::endl;
	rit++;
	std::cout << "it pointing at: " << *it << " and rit on: "<< *rit<< std::endl;
}
