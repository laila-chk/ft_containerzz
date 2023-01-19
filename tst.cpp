#include "vector.hpp"
#include <iostream>
#include <string>
#include <vector>
int  main()
{
	/**************
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
  *********************/
{
  std::vector<int> first;
  std::vector<int> second;
  std::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  std::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';

  std::cout << "cap of first: " << int (first.capacity()) << '\n';
  std::cout << "cap of second: " << int (second.capacity()) << '\n';
  std::cout << "cap of third: " << int (third.capacity()) << '\n';
  }
{
  ft::vector<int> first;
  ft::vector<int> second;
  ft::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  ft::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';

  std::cout << "cap of first: " << int (first.capacity()) << '\n';
  std::cout << "cap of second: " << int (second.capacity()) << '\n';
  std::cout << "cap of third: " << int (third.capacity()) << '\n';
}
  return 0;
}
