/*
common_algos.cpp
This program explores some well known algorithms available in modern C++ versions.

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <thread>      
#include <chrono>      // for std::chrono::seconds

int main()
{
    // 1) for_each()
    // The for_each algorithm applies a unary function (that is, taking one argument)
    // to each element of a single container (Hanson, 2025, p. 149).
    auto print_it = [](const auto& x) { std::cout << x << " "; }; // assume << is overloaded

    // once we have our lambda function, we create two vectors and test it
    using string = std::string;
    std::vector<double> nums = {1, 2, 3, 4};
    std::vector<string> strings = {"up", "down", "left", "right"};

    // we then iterate over the two vectors with our lambda
    std::for_each(nums.begin(), nums.end(), print_it);
    std::cout << "\n";
    std::for_each(strings.begin(), strings.end(), print_it);
    std::cout << "\n";

    // 2) transform()
    // 2.1) We want to transform the nums vector (scale it by a factor of 1.5)
    std::transform(nums.begin(), nums.end(), nums.begin(), [](const auto& x, double delta = 1.5){ return delta * x; });
    std::ranges::for_each(nums, print_it); std::cout << "\n";

    // 2.2) copy transform
    std::vector<double> v_copy(nums.size()); 
    std::ranges::for_each(v_copy, print_it); std::cout << "\n";
    std::transform(nums.begin(), nums.end(), v_copy.begin(), [](const auto& x, double delta = 1.5){ return delta * x; });

    // (NOT NECESSARY; JUST FOR FUN)
    // ----------------------------------------------------------------------------
    // Define color codes
    const std::string green = "\033[32m";
    const std::string reset = "\033[0m";

    std::cout << "Copying data [";

    int barWidth = 20;
    std::cout << green; // start green color

    for (int i = 0; i <= barWidth; ++i)
    {
        std::cout << "=" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << reset; // reset color back to default
    std::cout << "] Done!\n";
    // ----------------------------------------------------------------------------

    // print new vector
    std::ranges::for_each(v_copy, print_it); std::cout << "\n";



    return 0;
}

