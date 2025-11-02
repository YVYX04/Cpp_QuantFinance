/*
BlackScholes.cpp
Implememtation of the BlackScholes class

author: Yvan Richard
date: Fall 2025
*/

#include "../include/BlackScholes.hpp"
#include "../include/utils.hpp"
#include <array> // for std::array
#include <cmath> // for exp, log, sqrt, M_PI
#include <algorithm> // for std::max
#include <numbers> // for std::numbers::sqrt2

// --- Constructors ---
// Note on order of initialization:
// the order in which member variables are initialized
// is the order in which they are declared in the class,
// not the order in which they appear in the initializer list.
// To avoid confusion, we must follow the order of declaration.
BlackScholes::BlackScholes() : strike_{100.00}, spot_{90.00}, time_to_exp_{1.0},
        payoff_type_{PayoffType::Call}, rate_{0.05}, div_{0.0} { }

BlackScholes::BlackScholes(double strike, double spot, double time_to_exp,
                           PayoffType payoff_type, double rate, double div)
    : strike_{strike}, spot_{spot}, time_to_exp_{time_to_exp},
        payoff_type_{payoff_type}, rate_{rate}, div_{div} { }

// --- Private Methods ---
std::array<double, 2> BlackScholes::compute_norm_args_(double vol) const
{
    using std::log;
    using std::sqrt;
    using std::exp;
    const double vol_sqrt_t = vol * sqrt(time_to_exp_);
    const double d1 = (log(spot_ / strike_) + (rate_ - div_) * time_to_exp_ + 0.5 * vol * vol * time_to_exp_) / vol_sqrt_t;
    const double d2 = d1 - vol_sqrt_t;
    return {d1, d2};
}

// --- Overloaded Operators ---
double BlackScholes::operator()(double vol) const
{
    // the exponential function from the cmath library
    using std::exp;

    // retrieve phi
    const int phi = static_cast<int>(payoff_type_);

    // T > 0
    if (time_to_exp_ <= 0.0)
    {
        // option has expired, return intrinsic value
        return std::max(phi * (spot_ - strike_), 0.0);
    }
    else
    {
        // compute d1 and d2 (destructured binding from C++17)
        const auto [d1, d2] = compute_norm_args_(vol);

        // define a lambda for the standard normal cumulative distribution function
        auto N = [](double x)
        {
            return (1.0 + std::erf(x / std::numbers::sqrt2)) / 2.0;
        };

        // compute N(d1) and N(d2)
        const double Nd1 = N(phi * d1);
        const double Nd2 = N(phi * d2);

        // discount factor
        const double disc_factor = exp(-rate_ * time_to_exp_);

        // return the Black-Scholes price
        return phi * (spot_ * exp(-div_ * time_to_exp_) * Nd1 - strike_ * disc_factor * Nd2);
    }
}

// --- Free Functions ---
// Implied volatility with lambada functions: secant method (Hanson, 2025)
// Implied volatility with lambada functions: secant method (Hanson, 2025, p. 39)
double implied_vol_lambda(const BlackScholes& bs_option, double market_price,
                          double x0, double x1, double tol,
                          unsigned int max_iter)
{
    // simple difference function for defining the root function
    auto diff = [&bs_option, market_price](double vol)
    {
        return bs_option(vol) - market_price;
    };

    // f(x0) and f(x1)
    double y0 = diff(x0);
    double y1 = diff(x1);

    // init implied vol.
    double impl_vol = 0.0;

    // track num. iteration
    unsigned int i;
    for (i = 0; i <= max_iter; ++i)
    {
        if(std::abs(x1 - x0) <= tol) // convergence criteria
        {
            return x1;
        }
        else
        {
            impl_vol = x1 - (x1 - x0) * y1 / (y1 - y0);

            // update x1 and x0
            x0 = x1;
            x1 = impl_vol;
            y0 = y1;
            y1 = diff(x1);
        }

        
    }

    // no convergence
    return std::nan("");

}