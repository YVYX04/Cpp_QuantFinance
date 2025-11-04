/*
numeric_algos.cpp
This program explores numeric algorithms available in modern C++ versions.

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for numeric algorithms
#include <cmath>
#include <deque>


int main()
{
    // Define a vector of int
    std::vector<int> v1 = {1, 2, 3, 4, 5};

    // 1) accumulate()
    // The accumulate algorithm computes the sum of the elements in a range.
    int sum = std::accumulate(v1.begin(), v1.end(), 0); // third argument is the initial value
    std::cout << "The sum of the elements is: " << sum << std::endl;

    // 2) inner_product()
    // The inner_product algorithm computes the inner product of two ranges.
    std::vector<int> v2 = {10, 20, 30, 40, 50};
    int inner_prod = std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);
    std::cout << "The inner product of v1 and v2 is: " << inner_prod << std::endl;

    // 3) partial_sum()
    // The partial_sum algorithm computes the partial sums of a range.
    std::vector<int> partial_sums(v1.size());
    std::partial_sum(v1.begin(), v1.end(), partial_sums.begin());
    std::cout << "The partial sums are: ";
    for (const auto& val : partial_sums)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 4) adjacent_difference()
    // The adjacent_difference algorithm computes the differences between adjacent elements.
    std::vector<int> adj_diff(v1.size());
    std::adjacent_difference(v1.begin(), v1.end(), adj_diff.begin());
    std::cout << "The adjacent differences are: ";
    for (const auto& val : adj_diff)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 5) iota()
    // The iota algorithm fills a range with sequentially increasing values.
    std::vector<int> v3(5);
    std::iota(v3.begin(), v3.end(), 1); // start from 1
    std::cout << "The elements of v3 after iota are: ";
    for (const auto& val : v3)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 6) An example for log-returns
    std::vector<double> prices
    {
        25.5, 28.0, 30.5, 31.0, 27.5, 31.0, 29.5, 28.5, 37.5,
        33.5, 25.5, 31.5, 26.5, 29.5, 32.5, 34.5, 28.5, 35.5,
        28.5, 29.0, 32.0, 23.5, 27.5, 33.5, 28.0, 28.0, 32.5,
        31.5, 29.0, 33.0, 32.5, 29.5, 34.5
    };

    // log returns
    std::deque<double> log_r(prices.size());
    std::ranges::transform(prices, prices.begin(), [](double x){ return std::log(x); });
    std::adjacent_difference(prices.begin(), prices.end(), log_r.begin());

    // pop front since no meaning
    log_r.pop_front(); 

    // print
    for (const auto& val : log_r)
    {
        std::cout << val << " \n";
    }
    std::cout << std::endl;

    return 0;
}