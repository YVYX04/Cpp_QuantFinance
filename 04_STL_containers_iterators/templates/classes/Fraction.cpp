/*
Fraction.hpp
Implements a Fraction class for representing and manipulating fractions.

Author: Yvan Richard
Date: Fall 2025
*/

#include "Fraction.hpp"
#include <numeric> // for std::gcd
#include <stdexcept> // for std::invalid_argument
#include <compare>

// --- Constructors ---
Fraction::Fraction() : n_(0), d_(1) {} // default fraction 0/1
Fraction::Fraction(unsigned int n, unsigned int d) : n_(n), d_(d)
{
    if (d == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    // Simplify the fraction
    unsigned int gcd = std::gcd(n_, d_);
    n_ /= gcd;
    d_ /= gcd;
}

// --- Spaceship operator ---
std::strong_ordering Fraction::operator<=>(const Fraction& other) const noexcept
{
    // compute the relevant metric
    unsigned int rhs = other.n_ * d_;
    unsigned int lhs = n_ * other.d_;

    if (lhs > rhs) return std::strong_ordering::greater;
    if (lhs < rhs) return std::strong_ordering::less;
    return std::strong_ordering::equal;
}

// --- Overloaded Operators ---
Fraction Fraction::operator*(const Fraction& other) const noexcept
{
    return {n_ * other.n_, d_ * other.d_};
}

// --- Non-member functions ---
std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
    // os charging
    os << "(" << f.n() << "/" << f.d() << ")";
    return os;
}