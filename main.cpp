#include <iostream>
#include <iterator>
#include <vector>
#include "vector.hpp" 

int main()
{
	std::vector<int> v;
	
	 v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);
	std::vector<int>::reverse_iterator it1 = v.rend();
	std::vector<int>::reverse_iterator it = v.rbegin();

	std::cout << "it pointing at: " << *it << std::endl;
std::cout << "it1 pointing at: " << *it1 << std::endl;
	std::vector<int>::reverse_iterator rit ;
	rit = it + 1;
	std::cout << "it pointing at: " << *it << " and rit on: "<< *rit<< std::endl;
	it++;
	std::cout << "it pointing at: " << *it << " and rit on: "<< *rit<< std::endl;
	rit++;
	std::cout << "it pointing at: " << *it << " and rit on: "<< *rit<< std::endl;
	
}
