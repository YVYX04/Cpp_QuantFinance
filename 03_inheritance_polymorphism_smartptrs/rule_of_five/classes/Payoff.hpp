/*
Payoff.hpp
Defines Payoff classes for option pricing.

Author: Yvan Richard
Date: Fall 2025
*/

#ifndef Payoff_hpp
#define Payoff_hpp

#include <memory>

class Payoff
{
protected:                  // we use "protected" to access data member inside derived class
    double strike_price_{}; // initialize to 0.0 by default

public:
    // --- Constructors ---
    Payoff() = default;
    explicit Payoff(double strike_price);
    Payoff(const Payoff&) = default;            // copy ctor
    Payoff(Payoff&&) noexcept = default;        // move ctor

    // --- Getters & Setters ---
    inline double strike_price() const noexcept { return strike_price_; }
    inline void strike_price(double strike_price) noexcept { strike_price_ = strike_price; }

    // --- Assignment operators ---
    Payoff& operator=(const Payoff&) = default;     // copy assignment
    Payoff& operator=(Payoff&&) noexcept = default; // move assignment

    // --- Virtual destructor for polymorphism ---
    virtual ~Payoff() = default;

    // --- Interface ---
    // compute the payoff with the spot price
    virtual double operator()(double spot) const = 0;
    // virtual clone interface
    virtual std::unique_ptr<Payoff> clone() const = 0; // returns a unique_ptr to a copy of the derived object
};






#endif // Payoff_hpp