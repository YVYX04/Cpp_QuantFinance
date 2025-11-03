/*
BankAccount.hpp
This header file implements the BankAccount class, which represents a simple bank account with basic
functionalities such as deposit, withdraw, and check balance. Continuous compounding interest is applied.

Author: Yvan Richard
Date: Fall 2025
*/

#include "BankAccount.hpp"
#include <cmath>


// --- Constructors ---
BankAccount::BankAccount(double balance, double r) :
    balance_(balance), r_(r) { }

// --- Member Functions ---
double BankAccount::value_at_t(double time)
{
    return balance_ * std::exp(r_ * time);
}

