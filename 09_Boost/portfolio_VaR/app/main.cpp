/*
The VaR Project

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include <boost/math/distributions/normal.hpp>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
#include <iterator>
#include <cmath>
#include <numeric>
#include <span>
#include <utility> // for std::pair

// prototypes
std::pair<double, double> mean_std(std::span<const double> v);

int main()
{
    // Import our data from CSV file in a matrix
    std::string import_path = "../data/stock_returns.csv";

    // Open the file
    std::ifstream file(import_path); // ifstream = input file stream
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << import_path << std::endl;
        return 1;
    }
    std::vector<std::vector<double>> data;
    
    // Skip the header line
    std::string line;
    std::getline(file, line); // the getline reads a line from the file, line is the variable where the line is stored.

    // Read the data line by line
    while (std::getline(file, line))
    {
        std::stringstream ss(line); // stringstream allows us to treat a string as a stream, a stream is a sequence of characters.
        std::string value;
        std::vector<double> row;
        while (std::getline(ss, value, ',')) // we read from the stringstream ss, until we find a comma
        {
            // Convert the string value to a double and add it to the row
            row.push_back(std::stod(value));
        }
        data.push_back(row);
    }
    file.close();

    // print the number of rows and columns read
    if (!data.empty())
    {
        std::cout << "Data imported successfully. Rows: " << data.size() << ", Columns: " << data[0].size() << std::endl;
    }
    else
    {
        std::cout << "No data found in the file." << std::endl;
    }

    // encode the weight vector w of the portfolio
    std::vector<double> w = {0.301, 0.27, 0.251, 0.178};

    // portfolio returns
    std::vector<double> p_returns(data.size());

    for (size_t t = 0; t < data.size(); ++t)
    {
        double r_P = 0.0;
        for (size_t i = 0; i < data[t].size(); ++i) r_P += data[t][i] * w[i];

        // assign the value
        p_returns[t] = r_P;
    }

    // compute the mean and empirical std
    auto [mean_p, std_p] = mean_std(p_returns);
    std::cout << "Portfolio Mean Daily Return: " << mean_p << std::endl;
    std::cout << "Portfolio Daily Standard Deviation: " << std_p << std::endl;

    // We compute the VaR at 99% confidence level
    double alpha = 0.01; // 1% significance level
    boost::math::normal_distribution<double> norm_dist(0.0, 1.0); // standard normal distribution
    double z_alpha = boost::math::quantile(norm_dist, alpha); // quantile at alpha level

    double VaR = mean_p + z_alpha * std_p;
    std::cout << "Value at Risk (VaR) at 99% confidence level: " << -VaR << std::endl;

    return 0;
}


std::pair<double,double> mean_std(std::span<const double> v)
{
    const size_t n = v.size();
    assert(n > 1);

    double mean = 0.0;
    double M2   = 0.0;   // sum of squared deviations

    size_t k = 0;

    // Welford's online algorithm
    // https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance
    for (double x : v)
    {
        ++k;
        double delta = x - mean;
        mean += delta / static_cast<double>(k);
        double delta2 = x - mean;
        M2 += delta * delta2;
    }

    double var = M2 / static_cast<double>(n - 1); // sample variance
    return {mean, std::sqrt(var)};
}