/*
PutPayoff.hpp
Header file for PutPayoff derived class

Author: Yvan Richard
Date: Fall 2025
*/

#ifndef PUTPAYOFF_HPP
#define PUTPAYOFF_HPP

#include "Payoff.hpp"
#include <memory>
#include <algorithm>

class PutPayoff : public Payoff {
public:
    // --- Constructors ---
    PutPayoff(double strike_price);
    PutPayoff(const PutPayoff& other) = default;
    PutPayoff(PutPayoff&& other) noexcept = default;
    PutPayoff& operator=(const PutPayoff& other) = default;
    PutPayoff& operator=(PutPayoff&& other) noexcept = default;
    virtual ~PutPayoff() = default;

    // --- Override interface ---
    double operator()(double spot) const override;
    std::unique_ptr<Payoff> clone() const override;
};

#endif // PUTPAYOFF_HPP