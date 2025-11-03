/*
BankAccount.hpp
This header file defines the BankAccount class, which represents a simple bank account with
one basic functionality: continuous compounding.

Author: Yvan Richard
Date: Fall 2025
*/

#ifndef BankAccount_hpp
#define BankAccount_hpp

class BankAccount
{
private:
    // --- Member Variables ---
    double balance_; // Current balance of the bank account
    double r_; // Current interest rate (as a decimal)

public:
    // --- Constructors & Destructors ---
    BankAccount() = default; // both values init to 0.0
    BankAccount(double balance, double r);
    BankAccount(const BankAccount& other) = default;
    BankAccount(BankAccount&& other) = default;
    ~BankAccount() = default;

    // --- Assignment Operators ---
    BankAccount& operator=(const BankAccount& other) = default;
    BankAccount& operator=(BankAccount&& other) = default;

    // --- Getters & Setters ---
    inline double balance() const noexcept { return balance_; }
    inline double r() const noexcept { return r_; }
    inline void balance(double balance) noexcept { balance_ = balance; }
    inline void r(double r) noexcept { r_ = r; }

    // --- Member Functions ---
    double value_at_t(double time); // time in years




};

#endif // BankAccount_hpp