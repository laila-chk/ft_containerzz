
#include "vector.hpp"
#include <iostream>
#include <string>
int main()
{
  try
{
    std::vector<int>b;
    b.push_back(1666);
    b.push_back(52);
    b.push_back(102);
    b.push_back(55);
    std::vector<int>::iterator it;
    it = b.begin();
  // for (it = b.begin(); it < b.end() ; it++)
      // std::cout << *it << std::endl;
    // it+3;
      std::cout << it[2] << std::endl;
    it += 2;
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
