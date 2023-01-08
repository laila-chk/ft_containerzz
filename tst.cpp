
#include "vector.hpp"

int main()
{
  std::vector<int>a(4,7);
  ft::vector<int> b(a.begin(), a.end());
  std::vector<int> c(a.begin(), a.end());
  for (std::vector<int>::iterator it = c.begin(); it != c.end(); ++it)
    std::cout << ' ' << *it;
  
}
