#include <iostream>
#include <vector>
 
int main()
{
    std::vector<int> alice(4);
//    std::vector<int> bob{7, 8, 9, 10};
    std::vector<int> eve(5);
	/*
	alice.push_back(1);
	alice.push_back(2);
	alice.push_back(3);
 
	eve.push_back(1);
	eve.push_back(2);
	eve.push_back(3);
    */
	std::cout << std::boolalpha;
 
	std::cout << eve.empty() << std::endl;
    // Compare non equal containers
	/*
    std::cout << "alice == bob returns " << (alice == bob) << '\n';
    std::cout << "alice != bob returns " << (alice != bob) << '\n';
    std::cout << "alice <  bob returns " << (alice < bob) << '\n';
    std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
    std::cout << "alice >  bob returns " << (alice > bob) << '\n';
    std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
    std::cout << '\n';
 
    // Compare equal containers
    std::cout << "alice == eve returns " << (alice == eve) << '\n';
	std::cout << "alice != eve returns " << (alice != eve) << '\n';
    */ 
	std::cout << "alice <  eve returns " << (alice < eve) << '\n';
    /*
	std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
    std::cout << "alice >  eve returns " << (alice > eve) << '\n';
    std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
	*/
}
