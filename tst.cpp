
#include "vector.hpp"
#include <iostream>
#include <string>
int main()
{
  try
{
    std::vector<std::string>a;
    ft::vector<int>b;
    b.push_back(12);
    b.push_back(52);
    b.push_back(102);
    ft::vector<int>::iterator it;
  for (it = b.begin(); it < b.end() ; it++)
      std::cout << *it << std::endl;
  // b.reserve(b.max_size() + 1);
  // std::cout << b.capacity() << "is the init cap" << std::endl;
  // b.push_back(5);
  // std::cout << b.capacity() << "is the init cap" << std::endl;
  // b.push_back(6); + 1
  // std::cout << b.capacity() << "is the init cap" << std::endl;
  // // b.push_back(7);
  // std::cout << b.capacity() << "is the init cap" << std::endl;

  // ft::vector<int>a(4,7);
  }
  catch (std::exception& e)
  {
    std::cout << "---\n";
    std::cout << e.what() << std::endl;
  }
    
}
