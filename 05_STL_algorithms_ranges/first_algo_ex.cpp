/*
first_algo_ex.cpp
This program demonstrates how to use algorithms as part of
the C++20 standard library.

Author: Yvan Richard
Date: Fall 2025
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


int main()
{

    // Define a lambda function
    auto is_even = [](int n) { return n % 2 == 0; };

    // Define a vector of int
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 8};

    // Count the frequency of odd numbers
    int counter = std::count_if(v1.begin(), v1.end(), is_even);

    // Result
    std::cout << "The frequency of even numbers is: " << counter << std::endl;

    /*
    Important note:
    We see that we are not applying the algorithm directly on the vector,
    but rather on the range defined by the iterators v1.begin() and v1.end().
    This is because algorithms in the C++ standard library operate on ranges
    defined by pairs of iterators, rather than directly on containers.
    */


    return 0;
}