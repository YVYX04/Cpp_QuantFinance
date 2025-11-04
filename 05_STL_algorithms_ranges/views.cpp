/*
views.cpp
This program demonstrates different views in C++20 ranges.

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include <vector>
#include <ranges>

int main()
{
    // Define a vector of int
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Create a chained view that filters even numbers and then squares them
    auto square_view = v1 | std::views::filter([](int n) { return n % 2 == 0; })
                          | std::views::transform([](int n) { return n * n; });

    // Output the results
    std::cout << "Squared even numbers: ";
    for (const auto& val : square_view)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    /*
    Important note:
    Views in C++20 ranges allow for lazy evaluation and efficient data processing.
    They enable the creation of pipelines that can filter, transform, and manipulate data
    without the need for intermediate containers, leading to cleaner and more efficient code.
    It is essential to understand that views are not containers themselves but rather
    provide a way to access and manipulate data in existing containers.
    They are lightweight and do not own the data they operate on, thus avoiding unnecessary copies.

    Of course, if we need to store the results, we can always copy them into a new container.
    */

    return 0;
}