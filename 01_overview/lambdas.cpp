/*
    lambdas.cpp
    Example code demonstrating how to use lambda expressions.

    Author: Yvan Richard
    Date: Fall 2025
*/

#include <iostream>
#include <vector>
using std::cout, std::endl;

int main()
{
    /*
    A lambda function is often referred to as an
    **anonymous function object**. A lambda function can
    be passed as an argument in another function.
    This last property is what makes them so powerful for use within
    standard algorithms, which again are covered in Chapter 5.
    */

    // Here is a very simple example
    auto f1 = []{ cout << "Hello world!\n"; };
    f1();

    // A lambda can also take in function arguments by using optional 
    // parentheses
    auto f2 = [](double x, double y){ return (x + y) / 2.0; };
    double z = f2(5.68, 5.5);
    cout << z << endl;

    // Three important comments:
    /*
        (i) by default, a lambda’s return type is deduced following the same rules as those
        used for auto variables; that is, their return type is the type of the expression used for
        the return statement. However, we can specify it with:
    */
    auto f3 = [](double x, double y)  -> double
    { return (x + y) / 2.0; };

    /*
        (ii) Second, be sure to place a semicolon at the end of the lambda block.
        (iii) Third, in cases of no function arguments, such as in the first example, the parentheses
        are generally optional (except, technically speaking, for special cases we need not
        be concerned with in this book)
    */

    // The capture of a lambda function: []
    // [] captures non-static external variables to use them inside the lambda body.
    std::vector v = {1.0, 2.0, 3.5, 4.1, 5.2}; // CTAD
    double shift_factor = 2.5;

    auto shift_scale = [&v, shift_factor](double alpha)
    {
        for (double& x : v)
        {
            x = alpha * (x + shift_factor);
        }
    };

    // use the lambda function
    shift_scale(-0.5);

    // print the vector
    for (const double vi : v)
    {
        cout << vi << " ";
    }
    cout << endl;



    return 0;
}