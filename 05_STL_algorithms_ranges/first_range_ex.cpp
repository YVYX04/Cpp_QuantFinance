/*
first_range_ex.cpp
This program demonstrates how to use ranges as part of
the C++20 standard library.

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>

int main()
{
    // Define a lambda function
    auto is_even = [](int n) { return n % 2 == 0; };

    // Define a vector of int
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 8};

    // Count the frequency of odd numbers
    int counter = std::ranges::count_if(v1, is_even); // with std::ranges we assume that we iterate over the whole vector.

    // Result
    std::cout << "The frequency of even numbers is: " << counter << std::endl;


    return 0;
}