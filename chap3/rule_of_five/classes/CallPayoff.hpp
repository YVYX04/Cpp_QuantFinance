/*
CallPayoff.hpp
Defines CallPayoff class derived from Payoff.

Author: Yvan Richard
Date: Fall 2025
*/

#ifndef CallPayoff_hpp
#define CallPayoff_hpp

#include "Payoff.hpp"
#include <memory>

class CallPayoff final : public Payoff
{
public:
    // --- Constructors ---
    CallPayoff() = default;
    explicit CallPayoff(double strike_price);
    CallPayoff(const CallPayoff& other) = default;            // copy ctor
    CallPayoff(CallPayoff&& other) noexcept = default;        // move ctor

    // --- Assignment operators ---
    CallPayoff& operator=(const CallPayoff& other) = default;     // copy assignment
    CallPayoff& operator=(CallPayoff&& other) noexcept = default; // move assignment

    // --- Override destructor ---
    ~CallPayoff() override = default;

    // --- Override interface ---
    double operator()(double spot) const override;
    std::unique_ptr<Payoff> clone() const override;

};

#endif // CallPayoff_hpp