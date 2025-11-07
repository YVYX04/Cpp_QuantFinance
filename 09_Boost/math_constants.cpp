/*
math_constants.cpp
This file shows how to use the Boost library to define and use mathematical constants in C++20.

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include <boost/math/constants/constants.hpp>

/*
Personal notes:
- The Boost library provides a wide range of mathematical constants that can be used in C++ programs.
- The constant one_div_root_two_pi represents the value of 1/sqrt(2π), which is commonly used in probability and statistics, particularly in the context of the normal distribution.
- The n_pdf function calculates the probability density function of the standard normal distribution at a given point x.

For using the Boost libraries, ensure that your include paths are correctly set up in your development environment.
My configurations for VSCode are shown in the .vscode/c_cpp_properties.json and .vscode/tasks.json files.
*/

double n_pdf(double x);

int main()
{
    // Example usage of the n_pdf function
    double x = 1.0;
    std::cout << "The value of the standard normal PDF at x = " << x << " is " << n_pdf(x) << std::endl;

    return 0;
}

double n_pdf(double x)
{
    static const double inv_sqrt_2pi = boost::math::constants::one_div_root_two_pi<double>();
    return inv_sqrt_2pi * std::exp(-0.5 * x * x);
}