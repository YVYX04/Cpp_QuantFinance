/*
CallPayoff.cpp
Implementation file for CallPayoff derived class

Author: Yvan Richard
Date: Fall 2025
*/

#include "PutPayoff.hpp"
#include <algorithm>
#include <memory>

// --- Constructors ---
PutPayoff::PutPayoff(double strike_price) : Payoff(strike_price) { }

// --- Override Interface ---
double PutPayoff::operator()(double spot) const
{
    return std::max(0.0, (strike_price_ - spot));
}
std::unique_ptr<Payoff> PutPayoff::clone() const
{
    // return a pointer to a Payoff object with the same properties
    std::unique_ptr<PutPayoff> out_ptr = std::make_unique<PutPayoff>(*this);
    return out_ptr;
}
