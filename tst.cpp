
#include "vector.hpp"
#include <iostream>
int main()
{
  // _allocater.MAX_SIZE()
  try
{
  std::vector<int>b(4,7);
    std::cout << b.at(12) << std::endl;

  ft::vector<int>a(4,7);
    std::cout << a[2] << std::endl;
    std::cout << "++++---\n";
  }
  catch (std::exception& e)
  {
    std::cout << "---\n";
    std::cout << e.what() << std::endl;}
    
}
