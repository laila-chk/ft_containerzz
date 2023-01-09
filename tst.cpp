
#include "vector.hpp"
#include <iostream>
int main()
{
  // _allocater.MAX_SIZE()
  try
{
  std::vector<int>b(4,7);
  std::cout << b.capacity() << "is the init cap" << std::endl;
  b.push_back(5);
  std::cout << b.capacity() << "is the init cap" << std::endl;
  b.push_back(6);
  std::cout << b.capacity() << "is the init cap" << std::endl;
  b.push_back(7);
  std::cout << b.capacity() << "is the init cap" << std::endl;

  // ft::vector<int>a(4,7);
  }
  catch (std::exception& e)
  {
    std::cout << "---\n";
    std::cout << e.what() << std::endl;}
    
}
