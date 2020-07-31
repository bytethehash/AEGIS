#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*Global variables*/
int iterator;


int main ()
{
    /*The two bignum values the researcher wants to do substraction with note
    that the researcher has NOT added the ability to calculate using minus number
    so make sure that "big_num_a" is of a larger value than "big_num_b" for the current version of
    program.*/
    std::vector<int> big_num_a = {3,3,0};
    std::vector<int> big_num_b = {3,3,0};

    /*Reverse the vectors so it is easier to work with. The size of the vector is specified to avoid any
    errors.*/
    std::vector <int>big_num_a_reversed(big_num_a.size());
    std::vector <int> big_num_b_reversed(big_num_b.size());

    std::reverse_copy(begin(big_num_a), std::end(big_num_a), std::begin(big_num_a_reversed));
    std::reverse_copy(begin(big_num_b), std::end(big_num_b), std::begin(big_num_b_reversed));

    std:: vector<int> temp_result;

    /*Iteratre through the two "big_num" vectors. If the "big_num_a" element is smaller than "big_num_b" 
    then add "10" to the "big_num_a element and deduct "1" from the next element. Add the calculation result
    to the temporary results vector.*/
    for (iterator = 0; iterator < big_num_a_reversed.size(); iterator++)
    {
        if(big_num_a_reversed[iterator] < big_num_b_reversed[iterator])
        {
            big_num_a_reversed[iterator] +=10;
            big_num_a_reversed[iterator+1] -=1;
        }
        temp_result.push_back(big_num_a_reversed[iterator] - big_num_b_reversed[iterator]);
    }

    /*Reverse the results vectors and prepare to display the output to the user.*/
    std::vector <int> final_result(temp_result);
    std::reverse_copy(begin(temp_result), std::end(temp_result), std::begin(final_result));

    for (iterator = 0; iterator < temp_result.size(); iterator++)
    {
        std::cout << final_result[iterator];
    }
    std:: cout << std::endl;
}
