/*
Fraction.cpp
This file defines the Fraction class for representing and manipulating fractions.

Author: Yvan Richard
Date: Fall 2025
*/

#include <cassert>
#include <numeric>
#include <compare>

#include "../include/Fraction.hpp"

// --- Constructors ---
Fraction::Fraction(int num, int denom) : num_(num), den_(denom)
{
    // num > 0 and denom != 0 assumed
    assert((denom != 0) && (num > 0));

    // simplify the fraction
    int gcd = std::gcd(num_, den_);
    num_ /= gcd;
    den_ /= gcd;
}

// --- Comparison Operators ---
bool Fraction::operator==(const Fraction& other) const
{
    return (num_ == other.num_) && (den_ == other.den_);
}
std::strong_ordering Fraction::operator<=>(const Fraction& other) const
{
    int lhs = num_ * other.den_;
    int rhs = other.num_ * den_;
    if (lhs < rhs)
        return std::strong_ordering::less;
    else if (lhs > rhs)
        return std::strong_ordering::greater;
    else
        return std::strong_ordering::equal;
}