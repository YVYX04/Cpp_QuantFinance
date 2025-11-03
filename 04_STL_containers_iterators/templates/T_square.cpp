/*
T_square.cpp
In this code, we illustrate the concept of templates
with a templated function that will take as input either PODs
or a user-defined class (classes/Fraction.hpp).
*/

#include "classes/Fraction.hpp"
#include <iostream>

// function prototype
template <typename T>
T squared(const T& t);

int main()
{
    // TEMPLATED FUNCTION USAGE
    // the three types
    int t1 = 2;
    double t2 = 4.5;
    Fraction t3 = {9, 4};

    // apply the function T_squared
    std::cout << squared(t1) << '\n';
    std::cout << squared(t2) << '\n';
    std::cout << squared(t3) << '\n'; // << has been overloaded for Fraction objects
    return 0;
}

// function 
template <typename T>
T squared(const T& t)
{
    /*
    This templated function ASSUMES THAT
    THE * OPERATOR IS FUNCTIONAL FOR THE DATA
    TYPE PASSED.

    Indeed, when we implement templated class
    or templated function we rely on a set of
    assumptions.
    */
    return t * t;
}

/*
+––––––––+
| OUTPUT |
+––––––––+
4
20.25
(81/16)
*/