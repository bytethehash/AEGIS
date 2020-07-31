#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*Global variables*/
int iterator;
int big_num_vector_size;
std::vector <int> temp_vector;
int temp_vector_element;
std::vector <int> result;
int big_num_a_final_size;
int big_num_b_final_size;
int padding_zero = 0;

int main ()
{
    /*
          9 8 7
       +  5 4 3
    ------------
        1 5 3 0
    */

    /*The two bignum values the researcher wants to know the sum of.*/
    std::vector <int> big_num_a = {1,2,3,5};
    std::vector <int> big_num_b = {4,5,0,2,0,0,0,7};

    /*Get the intial size of the two vectors without the "padding". The researcher is going
    to see the differnce between the two vectors. If one vector is smaller than the 
    other it is going to be "padded" with leading zero(s) to make the calculation work.*/
    int big_num_a_size = big_num_a.size();
    int big_num_b_size = big_num_b.size();

    std::cout << "Now displaying the sum of the two big nums:" << std::endl; 

    for (iterator = 0; iterator < big_num_a_size; iterator++)
    {
        std::cout << big_num_a[iterator];
    }

    std::cout << " + ";

    for (iterator = 0; iterator < big_num_b_size; iterator++)
    {
        std::cout << big_num_b[iterator];
    }
    
    std::cout << " = ";

    /*Calculate the number of zero(s) needed to be added to either of the vectors to 
    meet any "padding" requirements. If vectors are the same length it does not need "padding".*/
    int padding_zero_count;
    if (big_num_a_size < big_num_b_size)
    {
        padding_zero_count = big_num_b_size - big_num_a_size ;
        for (iterator = 0; iterator < padding_zero_count; iterator++)
        {
            big_num_a.insert(big_num_a.begin(),padding_zero); 
        }

    }
    else if (big_num_a_size > big_num_b_size)
    {
        padding_zero_count = big_num_a_size - big_num_b_size;
        for (iterator = 0; iterator < padding_zero_count; iterator++)
        {
            big_num_b.insert(big_num_b.begin(),padding_zero); 
        }
    }
    else
    {
        std::cout << "no padding required"  << std::endl;
    }
    
    /*Once the vectors have been "padded" out, get the final size of the newly "padded" vectors.*/
    big_num_a_final_size = big_num_a.size();
    big_num_b_final_size = big_num_b.size();

    /*Specify that size of the "reversed vectors" to avoid an error.*/
    std::vector <int>big_num_a_reversed(big_num_a_final_size);
    std::vector <int> big_num_b_reversed(big_num_b_final_size);

    /*Reverse the vectors so it is easier to work with.*/
    std::reverse_copy(begin(big_num_a), std::end(big_num_a), std::begin(big_num_a_reversed));
    std::reverse_copy(begin(big_num_b), std::end(big_num_b), std::begin(big_num_b_reversed));

    /*Vector has to be the same size for the researcher's implementation*/
    big_num_vector_size = big_num_a_reversed.size();

    /*Sum the two elements from each vector and store the WHOLE NUMBER in the 
    a temporary vector. For example [789 + 123] "8 + 2 = 10". 
    The number "10" is stored in the temporary vector.*/
    for (iterator = 0; iterator < big_num_vector_size; iterator++)
    {
        temp_vector_element =  big_num_a_reversed[iterator] + big_num_b_reversed[iterator]; 
        temp_vector.push_back(temp_vector_element);
    }

    /*Using [789 + 123] example. The researcher adds '9+3' or the two units from each
    number first and store it in the results vector. Using the modulus the researchers
    get the end unit in this "9 + 3 = 12" from the "12" the researcher stores the "2".*/
    result.push_back((big_num_a_reversed[0] + big_num_b_reversed[0])%10);

    /*Iterate through the "temporary vector". If the sum of two numbers is greater than
    "9" then add "1" to the next sum. The highest carrier value of two single numbers is 
    found by the sum of "9 + 9 = 18". It is always "1", it cannot be 20 or higher. If sum of two integers
    is not higher than "9" do not add "1".*/
    for (iterator = 0; iterator < temp_vector.size(); iterator++)
    {
        if (temp_vector[iterator] > 9)
        {
           result.push_back((temp_vector[iterator+1]+1)%10);
        }
        else{
            result.push_back((temp_vector[iterator+1])%10);
        }
    }

    /*Reverse the result vector so it can display the correct value.*/
    std::reverse(result.begin(),result.end());
    
    /*Sometimes the result contains a "leading 0" so this if statements "erases" the leading zero from
    the vector.*/
    if (result[0] == 0)
    {
        result.erase(result.begin()-1);
    }

    /*Display the calculation result from the "result vector".*/
    for (iterator = 0; iterator < result.size(); iterator++)
    {
        std::cout << result[iterator];
    }
    std:: cout << std::endl;
}
