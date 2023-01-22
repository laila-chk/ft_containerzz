
#include <vector>
#include <iostream>
#include "vector.hpp"


int main()
{
	{
		std::vector<std::string> v;
		v.push_back("hi");
		v.push_back("aa");
		v.push_back("bb");
		v.push_back("cc");
		std::vector<std::string>::iterator it;

//		it = v.end();
		it = v.insert ( v.end(), "WOW" );
		   v.insert (it,2,"300");

/*		// "it" no longer valid, get a new one:
		it = v.begin();

		std::vector<int> anothervector (2,400);
		v.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		v.insert (myvector.begin(), myarray, myarray+3);
		*/
		std::cout << "iterator pointing at:";
			std::cout << ' ' << *it << std::endl;
		std::cout << "the whole thing is: ";
		for (it=v.begin(); it<v.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		ft::vector<std::string> v;
		v.push_back("hi");
		v.push_back("aa");
		v.push_back("bb");
		v.push_back("cc");
		ft::vector<std::string>::iterator it;

	//	it = v.end();
		it = v.insert ( v.end(), "WOW" );

		   v.insert (it,2,"300");

/*		// "it" no longer valid, get a new one:
		it = v.begin();

		std::vector<int> anothervector (2,400);
		v.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		v.insert (myvector.begin(), myarray, myarray+3);
		*/
		std::cout << "iterator pointing at:";
			std::cout << ' ' << *it<< std::endl;
		std::cout << "the whole thing is: ";
		for (it=v.begin(); it<v.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
  return 0;
}
