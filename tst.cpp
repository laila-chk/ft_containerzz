
#include "vector.hpp"
#include <iostream>
#include <string>
int  main()
{
  try
{
  {
    std::cout << " std oputpuut \n";
    std::vector<double>b;
    b.push_back(1666);
    b.push_back(52);
    b.push_back(102);
    b.push_back(55);
    std::vector<double>::iterator it;
    std::vector<double> a(b.begin(), b.end());
    it = a.begin();
    for (it = a.begin(); it < a.end() ; it++)
      std::cout << *it << std::endl;
    }
  {
      
    std::cout << " ft oputpuut \n";
    ft::vector<double>b;
    b.push_back(1666);
    b.push_back(52);
    b.push_back(102);
    b.push_back(55);
    ft::vector<double>::iterator it;
    ft::vector<double> a(b.begin(), b.end());
    it = a.begin();
    for (it = a.begin(); it < a.end() ; it++)
      std::cout << *it << std::endl;
    }
  }
  catch (std::exception& e)
  {
    std::cout << "---\n";
    std::cout << e.what() << std::endl;
  }
    
}
