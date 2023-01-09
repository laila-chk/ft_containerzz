
#include "vector.hpp"
#include <iostream>
int main()
{
  // _allocater.MAX_SIZE()
  try
{
  std::vector<int>b(4,7);
    std::cout << b.max_size() << std::endl;

  ft::vector<int>a(4,7);
    std::cout << a.max_size() << std::endl;
  }
  catch (std::exception& e)
  {
    std::cout << "---\n";
    std::cout << e.what() << std::endl;}
    
}
