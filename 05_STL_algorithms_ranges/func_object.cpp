/*
func_object.cpp
This program demonstrates the use of function objects (functors) in C++.

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

class Poly2 // polynomial of degree 2
{
private:
    // --- Coefficients ---
    double a_, b_, c_;

public:
    // --- Constructors & Destructor ---
    Poly2() = default;
    Poly2(double a, double b, double c) :
        a_(a), b_(b), c_(c) { }
    ~Poly2() = default;

    // Getters & Setters (Overloaded)
    double a() const { return a_; }
    double b() const { return b_; }
    double c() const { return c_; }

    void a(double a) { a_ = a; }
    void b(double b) { b_ = b; }
    void c(double c) { c_ = c; }

    // Overloaded operator ()
    double operator()(double x) const noexcept
    {
        return a_ * x * x + b_ * x + c_;
    }

    // Same but not overloaded operator
    double value(double x) const noexcept
    {
        return a_ * x * x + b_ * x + c_;
    }


};

int main()
{

    // We create a vector x
    std::vector<double> x = {-2, -1, 0, 1, 2, 3};
    std::vector<double> y;

    // We use transform()
    // not the most efficient with "back_inserter" but good if we don't know
    // the size of y in the end. (otherwise, resize y and y.begin())
    Poly2 p1{2, 3, 1};
    std::transform(x.begin(), x.end(), std::back_inserter(y), p1); // works since () is overloaded

    // print y
    std::ranges::for_each(y, [](const auto& _){ std::cout << _ << " "; });
    std::cout << "\n";

    // Another approach
    y.clear();
    y.resize(6);
    
    std::transform(x.begin(), x.end(), y.begin(), [&p1](double x){ return p1.value(x); });
    std::ranges::for_each(y, [](const auto& _){ std::cout << _ << " "; });
    std::cout << "\n";


    return 0;
}