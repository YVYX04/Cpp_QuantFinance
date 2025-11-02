/*
CallPayoff.cpp
Implementation file for CallPayoff derived class

Author: Yvan Richard
Date: Fall 2025
*/

#include "CallPayoff.hpp"
#include <algorithm>
#include <memory>

// --- Constructors ---
CallPayoff::CallPayoff(double strike_price) : Payoff(strike_price) { }

// --- Override Interface ---
double CallPayoff::operator()(double spot) const
{
    return std::max(0.0, (spot - strike_price_));
}
std::unique_ptr<Payoff> CallPayoff::clone() const
{
    // return a pointer to a Payoff object with the same properties
    std::unique_ptr<CallPayoff> out_ptr = std::make_unique<CallPayoff>(*this);
    return out_ptr;
}
