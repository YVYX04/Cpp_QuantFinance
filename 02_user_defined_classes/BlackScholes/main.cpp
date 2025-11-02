/*
main.cpp
Main file to test the BlackScholes class

author: Yvan Richard
date: Fall 2025
*/

#include <iostream>
#include "include/BlackScholes.hpp"

int main()
{
    // data
    double strike = 95.0;
    double mkt_opt_price = 6.2; auto payoff_type = PayoffType::Call;
    double spot = 100.0;
    double rate = 0.05;
    double dividend = 0.07;
    double time_to_exp = 0.25;

    // bs object
    BlackScholes bsc_impl_vol{strike, spot, time_to_exp, payoff_type, rate, dividend};

    // initial guesses for the secant method
    double x0 = 0.10;
    double x1 = 0.30;

    // compute implied vol
    double imp_sig = implied_vol_lambda(bsc_impl_vol, mkt_opt_price,
                                         x0, x1);

    // print result
    std::cout << "The implied volatility is: " << imp_sig << std::endl;
    return 0;
}