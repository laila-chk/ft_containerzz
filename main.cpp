#include <iostream>
#include <iterator>
#include <vector>
#include "vector.hpp" 

int main()
{
	{
	std::vector<int> v;
	
	for (int i = 10; i < 30; i++)
		 v.push_back(i);
	std::vector<int>::reverse_iterator it1 = v.rend();
	std::vector<int>::reverse_iterator it = v.rbegin();

	std::cout << "it[1] pointing at: " << it[1] << std::endl;
	std::cout << "it[2] pointing at: " << it[2] << std::endl;
	std::cout << "it2[2] pointing at: " << it1[1] << std::endl;
	std::cout << "it1[2] pointing at: " << it1[2] << std::endl;
	
}
std::cout << "--------------------------------------" << std::endl;
	{

	ft::vector<int> v;

	for (int i = 10; i < 30; i++)
		 v.push_back(i);
	ft::vector<int>::reverse_iterator it1 = v.rend();
	ft::vector<int>::reverse_iterator it = v.rbegin();

	std::cout << "it[1] pointing at: " << it[1] << std::endl;
	std::cout << "it[2] pointing at: " << it[2] << std::endl;
	std::cout << "it2[2] pointing at: " << it1[1] << std::endl;
	std::cout << "it1[2] pointing at: " << it1[2] << std::endl;
	}
}

