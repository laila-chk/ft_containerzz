
#include "vector.hpp"
#include <iostream>
int main()
{
  // _allocater.MAX_SIZE()
  try
{
  std::vector<int>a(4,7);
  a.reserve(a.max_size() * 2);
    std::cout<<"zaema donia hania" << std::endl;
  }
  catch (std::exception& e)
  {std::cout << e.what() << std::endl;}
    
}
