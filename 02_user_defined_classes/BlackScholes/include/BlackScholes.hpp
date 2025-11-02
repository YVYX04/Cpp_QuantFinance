/*
BlackScholes.hpp
Declaration of the BlackScholes class

author: Yvan Richard
date: Fall 2025
*/


#ifndef BlackScholes_hpp
#define BlackScholes_hpp

#include <array> // std::array from C++ 11
#include <cmath> // for mathematical functions
#include "utils.hpp" // for PayoffType

class BlackScholes
{
private:
    // --- Private Member Variables ---
    double strike_, spot_, time_to_exp_;
    PayoffType payoff_type_;
    double rate_, div_;

    // --- Private Member Functions ---
    // compute and return d1 and d2 in function of the volatility
    std::array<double, 2> compute_norm_args_(double vol) const;

public:
    // --- Constructors ---
    // (default divident is 0)
    BlackScholes();
    BlackScholes(double strike, double spot, double time_to_exp,
                 PayoffType payoff_type, double rate, double div = 0.0);

    // --- Overloaded Operators ---
    // ()
    // we take as input the volatility. Useful for computing implied vol. later
    double operator()(double vol) const;
};

// --- Free Functions ---
// Implied volatility with lambada functions: secant method (Hanson, 2025, p. 39)
double implied_vol_lambda(const BlackScholes& bs_option, double market_price,
                          double x0, double x1, double tol = 1e-6,
                          unsigned int max_iter = 1000);



#endif // BlackScholes_hpp