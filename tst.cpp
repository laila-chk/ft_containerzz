
#include "vector.hpp"
#include <iostream>
#include <string>
#include <vector>
int  main()
{
  try
{
    double x[12] = {11.2 , 1 ,12 , 3232.3, 12.2, 1.1, 2.2, 3.3, 4.4};
  {

    std::cout << " std oputpuut" << std::endl;
    std::vector<char>b;
    // b.push_back('s');
    // b.push_back('x');
    // b.push_back('w');
    // b.push_back(55);
    std::vector<char>::iterator it;
    // std::vector<char> a(b.begin(), b.end());
    std::vector<char> a(x, x+4);
    // it = a.begin();
    for (it = a.begin(); it < a.end() ; it++)
      std::cout << *it << std::endl;
    }
  {
      
    std::cout << " std oputpuut" << std::endl;
    ft::vector<char>b;
    b.push_back('s');
    b.push_back('x');
    b.push_back('w');
    // b.push_back(55);
    // b.push_back(1666);
    // b.push_back(52);
    // b.push_back(102);
    // b.push_back(55);
    ft::vector<char>::iterator it;
    ft::vector<char> a(b.begin(), b.end());
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
