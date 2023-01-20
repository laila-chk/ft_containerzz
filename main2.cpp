#include<iostream>  
#include "vector.hpp"

using namespace std;
int main()
{
	vector<string>  v{"C" ,"Tutorials"};
	v.insert(v.begin()+1,2,"C");
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	return 0;

}
