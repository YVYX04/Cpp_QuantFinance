/*
main.cpp
This file is part of the spaceship_operator sub-project.

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include "include/Fraction.hpp"

int main()
{
    // Create two Fraction objects
    Fraction f1(3, 4);
    Fraction f2(6, 8);

    // Compare the two fractions using the defined operators (especially the spaceship operator in the last case)
    f1 == f2 ? std::cout << "f1 is equal to f2\n" : std::cout << "f1 is not equal to f2\n";
    f1 < f2 ? std::cout << "f1 is less than f2\n" : std::cout << "f1 is greater or equal to f2\n"; // rely on operator<=> indirectly
    f1 <=> f2 == 0 ? std::cout << "f1 is equal to f2\n" : std::cout << "f1 is not equal to f2\n";

    return 0;
}