/*
vector_iter.cpp
This file contains examples and tests for C++20 vector iterators,
including usage of begin(), end(), and range-based for loops on
std::vector and std::map.

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::vector<int> my_vector = {10, 20, 30, 40, 50};
    std::map<int, std::string> my_map = {{1, "one"}, {2, "two"}, {3, "three"}};

    // Using begin() and end() to iterate through the vector
    std::cout << "Elements in the vector using iterators: ";
    for (auto it = my_vector.begin(); it != my_vector.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using range-based for loop to iterate through the vector
    std::cout << "Elements in the vector using range-based for loop: ";
    for (const auto& elem : my_vector)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Example with std::map
    std::map<std::string, double> tickers = {
        {"AAPL", 150.25},
        {"GOOGL", 2750.50},
        {"MSFT", 299.99}
    };

    // Using begin() and end() to iterate through the map
    std::cout << "Elements in the map using iterators: ";
    for (auto it = tickers.begin(); it != tickers.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << " ";
    }
    std::cout << std::endl;

    // Using range-based for loop to iterate through the map
    std::cout << "Elements in the map using range-based for loop: " << std::endl;
    for (const auto& [key, value] : tickers)
    {
        std::cout << "(" << key << ": " << value << ")\n";
    }
    std::cout << std::endl;

    return 0;
}