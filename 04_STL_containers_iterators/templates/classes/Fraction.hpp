/*
Fraction.hpp
Defines a Fraction class for representing and manipulating fractions.

Author: Yvan Richard
Date: Fall 2025
*/

#ifndef Fraction_hpp
#define Fraction_hpp

#include <compare>
#include <ostream>

class Fraction
{
private:
    // --- Member variables ---
    unsigned int n_, d_; // numerator and denominator

public:
    // --- Constructors ---
    Fraction();                                    // default
    Fraction(unsigned int n, unsigned int d);      // input values
    Fraction(const Fraction& other) = default;     // copy ctor
    Fraction(Fraction&& other) = default;          // move ctor
    ~Fraction() = default;                          // dtor

    // --- Overloaded Assignment Operators ---
    Fraction& operator=(const Fraction& other) = default;     // classic assignment
    Fraction& operator=(Fraction&& other) = default;          // rvalue reference assignment

    // --- Getters & Setters ---
    inline unsigned int n() const noexcept { return n_; }
    inline unsigned int d() const noexcept { return d_; }
    inline void n(unsigned int n) noexcept { n_ = n; }
    inline void d(unsigned int d) noexcept { d_ = d; }

    // --- Spaceship operator ---
    std::strong_ordering operator<=>(const Fraction& other) const noexcept;

    // --- Operator Overloads ---
    // *
    Fraction operator*(const Fraction& other) const noexcept;

};

// overload the << operator
std::ostream& operator<<(std::ostream& os, const Fraction& f);


#endif // Fraction_hpp
