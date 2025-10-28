/*
Fraction.hpp
This file declares the Fraction class for representing and manipulating fractions.

Author: Yvan Richard
Date: Fall 2025
*/

#ifndef Fraction_hpp
#define Fraction_hpp

class Fraction
{
private:
    int num_;
    int den_;

public:
    // --- Constructors ---
    Fraction(int num = 0, int denom = 1);

    // --- Comparison Operators ---
    bool operator==(const Fraction& other) const;
    std::strong_ordering operator<=>(const Fraction& other) const;

};



#endif // Fraction_hpp