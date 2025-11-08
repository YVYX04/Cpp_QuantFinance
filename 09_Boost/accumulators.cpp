/*
accumulators.cpp
This file is part of a project that demonstrates the use of Boost.Accumulators for statistical computations.
The Boost.Accumulators library provides a framework for incremental calculation of statistical measures
such as mean, variance, and more. This example focuses on computing the mean and variance of a set of data points.

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include <vector>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/variance.hpp>
#include <boost/accumulators/statistics/rolling_mean.hpp>
#include <boost/accumulators/statistics/rolling_window.hpp>

using namespace boost::accumulators;

int main()
{
    // Define an accumulator set for variance
    accumulator_set<double, features<tag::variance>> acc;

    // Sample data points
    std::vector<double> data = {10.0, 20.0, 30.0, 40.0, 50.0};

    // Feed data points into the accumulator
    for (const auto& value : data)
    {
        acc(value); // Add each data point to the accumulator
        std::cout << "+ added value: " << value << "| current var: " << variance(acc) << std::endl;

        // This works well for online variance calculation!
    }

    // Example with a rolling accumulator set
    // Define an accumulator set with a rolling mean and a window size of 5
    accumulator_set<double, features<tag::rolling_mean>> fast_ma_acc(tag::rolling_window::window_size = 5);

    // Feed data points into the rolling accumulator
    for (const auto& value : data)
    {
        fast_ma_acc(value);
        std::cout << "+ added value: " << value
                << " | current rolling mean: " << rolling_mean(fast_ma_acc)
                << std::endl;
    }

    return 0;
}