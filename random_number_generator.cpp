#include <iostream>
#include <vector>
#include <random>
#include <string>



int main() 
{
    /*Character list the random generator will use.*/
	std::vector<char> character_list {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H',
	'I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e',
	'f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


	/*Random Number Generator function.*/
	for (int i =0; i < 1000; i++)
	{   
        /*This is a special class which produces uniformly-distributed unsigned integers with 32 bits of length.
        Generally, random_device is used to seed other generators*/
		std::random_device rd; 
        /*Popular general purpose "pseudorandom number generator (PRNG)". Using the Mersenne twister algorithm. */
	    std::mt19937 gen(rd());
        /*Generates values that is equally probable to be selected within a specified range. In this select from the "character_list".*/
	    std::uniform_int_distribution<> dis(0, character_list.size() - 1);
        /*Display the newly "randomly generated characters".*/
	    std::cout << character_list[dis(gen)];
	}
}