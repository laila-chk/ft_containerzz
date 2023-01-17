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
    std::vector<double>b;
    // b.push_back('s');
    // b.push_back('x');
    // b.push_back('w');
    // b.push_back(55);
    std::vector<double>::iterator it;
    // std::vector<double> a(b.begin(), b.end());
    std::vector<double> a(x, x+4);
    // it = a.begin();
    for (it = a.begin(); it < a.end() ; it++)
      std::cout << *it << std::endl;
    }

 	{

    std::cout << " std oputpuut" << std::endl;
    ft::vector<double>b;
    // b.push_back('s');
    // b.push_back('x');
    // b.push_back('w');
    // b.push_back(55);
    ft::vector<double>::iterator it;
    // std::vector<double> a(b.begin(), b.end());
    ft::vector<double> a(x, x+4);
    // it = a.begin();
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
