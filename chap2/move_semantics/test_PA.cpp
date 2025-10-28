/*
test_PA.cpp
This file is used to test the PatternAnalytics class.

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include "include/PatternAnalytics.hpp"
using std::cout;
using std::endl;

int main()
{
    // Create an instance of the PatternAnalytics class
    PatternAnalytics pa1{2.0, 5}; // vector of size 5, all values set to 2.0

    // Display mean, variance, and standard deviation
    cout << "Mean: " << pa1.mean() << endl; // 2.0
    cout << "Variance: " << pa1.var() << endl; // 0.0
    cout << "Standard Deviation: " << pa1.std() << endl; // 0.0

    // Create another instance with different data
    std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};
    PatternAnalytics pa2{data};

    // Display correlation between pa1 and pa2
    try {
        double correlation = pa1.corr(pa2);
        cout << "Correlation between pa1 and pa2: " << correlation << endl;
    } catch (const std::invalid_argument& e) {
        cout << e.what() << endl;
    }

    // use move semantics
    PatternAnalytics pa3{std::move(pa2)};
    cout << "Mean of pa3 (moved from pa2): " << pa3.mean() << endl; // 3.0

    // try to access pa2 after move
    try
    {
        cout << "Mean of pa2 after move: " << pa2.mean() << endl; // throw error
    } catch (const std::runtime_error& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}