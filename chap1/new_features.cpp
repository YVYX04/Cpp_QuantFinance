/*
    new_features.cpp
    Example code demonstrating some new features in C++11, C++17, and C++20.

    Author: Yvan Richard
    Date: Fall 2025
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
#include <format>

int main()
{
    // 1) auto
    // C++ 11 introduced the auto keyword that automatically deduce a variable
    // or any object type. Here are simple examples
    auto k = 1; // int
    auto x = 41.43; // double

    // warning: once x has been defined as a double, cannot be assigned to another type
    // or redefined in the same scope.

    // Best practice: In this case, we refrain from using auto to avoid ambiguity.
    // However, for very long return type or complex one, we favor auto

    // 2) Range-based for loop
    // Range-based for loop example
    std::vector<double> v1 = {2.3, 5.6, 8.9};
    for (const double& x : v1)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // 3) using
    // To generat aliases in a simple fashion, we now use the using keyword
    using dict = std::unordered_map<std::string, double>;
    dict d1 = {{"AAPL", 268.74},
               {"GOOG", 269.84},
               {"MSFT", 531.41}};

    // another example with auto
    for (const auto& [k, v] : d1) // (C++17 feature: struct decompostion)
    {
        std::cout << k << ": " << v << std::endl;
    }

    // 4) uniform initialization
    // C++11 introduced uniform initialization, also called braced initialization
    // currently, the following example compiles correctly (possibly with a warning)
    double y = 4.5;
    int i = y;
    std::cout << "i: " << i << std::endl;

    // However, to avoid the silent truncation, we can use
    /*
    int j{y};
    */
    // will return a compiler error: narrowing conversion of 'y' from 'double' to 'int'

    // 5) std::format
    // This functionality allow us to format a string
    // much like Python f"the value: {value}\n"
    double value = 1.8;
    std::string s = std::format("The value: {0}", value);
    std::cout << s << std::endl;

    // 6) Class Template Argument Deduction (CTAD)
    // C++17 introduced class template argument deduction (CTAD). Similar to auto, it will
    // deduce the type of a template parameter based on the data being initialized.
    // For instance, the following vector
    std::vector<int> nums1 = {1, 2, 3};

    // can be written
    std::vector nums2 = {1, 2, 3};

    // 7) Enumerated Constants and Scoped Enumerations
    // To avoid conflicts that existed in versions of C++ prior to C++11,
    // we now prefer class enum
    enum class Options
    {
        European, // = (int) 0
        American, // 1
        Asian     // 2
    };
    enum class Bonds
    {
        Tbills,    // 0
        Corporate, // 1
        Municipal  // 2
    };

    // this code does not compile anymore:
    // bool (Bonds::Tbills == Options::European);

    return 0;
}