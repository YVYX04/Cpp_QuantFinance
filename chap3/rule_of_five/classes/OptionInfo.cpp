/*
OptionInfo.hpp
Implement OptionInfo.

Author: Yvan Richard
Date: Fall 2025
*/

#include "OptionInfo.hpp"
#include <utility>

// --- Constructors ---
// The structure of this constructor is really important. Here, we use std::move()
// to transfer the ownership of the unique_ptr from the argument to the member variable.
// This is necessary because unique_ptr cannot be copied, only moved.
OptionInfo::OptionInfo(std::unique_ptr<Payoff> payoff_ptr, double time_to_exp) :
    payoff_ptr_(std::move(payoff_ptr)), time_to_exp_(time_to_exp) { }


// --- Getter & Setter ---
double OptionInfo::time_to_exp() const { return time_to_exp_; }

// --- General Methods ---
double OptionInfo::option_payoff(double spot) const
{
    return (*payoff_ptr_)(spot); // dereference the unique_ptr to call the Payoff operator()
}