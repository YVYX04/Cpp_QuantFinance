/*
main.cpp
Main file to test Payoff classes and OptionInfo.

Author: Yvan Richard
Date: Fall 2025

+––––––––+
|  NOTE  |
+––––––––+

This main file includes manually implemented test units
for the Payoff derived classes and the OptionInfo class.
In a production environment, it is recommended to use
a dedicated testing framework such as Google Test or Catch2
for more comprehensive and maintainable test suites.
*/

#include <iostream>
#include <tuple>
#include <memory>
#include <cassert>
#include <utility>
#include <string>
#include "classes/Payoff.hpp"
#include "classes/CallPayoff.hpp"
#include "classes/PutPayoff.hpp"
#include "classes/OptionInfo.hpp"

// tests prototypes
std::tuple<bool, std::string> test_01();
std::tuple<bool, std::string> test_02();
std::tuple<bool, std::string> test_03();
std::tuple<bool, std::string> test_04();

int main()
{
    // test 1
    auto [c_01, m_01] = test_01();
    if (!c_01) std::cerr <<  "Test 1 failed:" << m_01 << std::endl;
    
    // test 2
    auto [c_02, m_02] = test_02();
    if (!c_02) std::cerr <<  "Test 2 failed:" << m_02 << std::endl;

    // test 3
    auto [c_03, m_03] = test_03();
    if (!c_03) std::cerr <<  "Test 3 failed:" << m_03 << std::endl;

    // test 4
    auto [c_04, m_04] = test_04();
    if (!c_04) std::cerr <<  "Test 4 failed:" << m_04 << std::endl;

    // All tests passed
    if (c_01 && c_02 && c_03 && c_04)
    {
        std::cout << "\033[32mAll tests passed successfully.\033[0m" << std::endl;
    }
}

// test 01
std::tuple<bool, std::string> test_01()
{
    /*
    test_1 is designed to test the constructors of CallPayoff
    class.
    */

    // init return values
    bool check = true;
    std::string message = "\033[32mTest 1 passed successfully.\033[0m";

    // 1) Basic Constructor & Getter
    CallPayoff cp_01{100};                      // strike price of 100
    if(cp_01.strike_price() != 100.00)
    {
        message = "\033[31mCallPayoff::CallPayoff(double strike_price) failed.\033[0m";
        check = false;
        return {check, message};
    }

    // 2) Setter check
    cp_01.strike_price(105.00); 
    if(cp_01.strike_price() != 105.00)
    {
        message = "\033[31mCallPayoff::strike_price(double strike_price) failed.\033[0m";
        check = false;
        return {check, message};
    }

    // 3) Copy ctor
    CallPayoff cp_02{cp_01};
    if(cp_02.strike_price() != 105.00)
    {
        message = "\033[31mCallPayoff::CallPayoff(const CallPayoff& other) failed.\033[0m";
        check = false;
        return {check, message};
    }

    // 4) Move ctor
    CallPayoff cp_03 = std::move(cp_02);
    if(cp_03.strike_price() != 105.00)
    {
        message = "\033[31mCallPayoff::CallPayoff(CallPayoff&& other) failed.\033[0m";
        check = false;
        return {check, message};
    }

    // output
    return {check, message};

}

// test 02
std::tuple<bool, std::string> test_02()
{
    /*
    test_2 is designed to test the assignment operators of 
    the CallPayoff class.
    */

    // init return values
    bool check = true;
    std::string message = "\033[32mTest 2 passed successfully.\033[0m";

    // 1) Assignment operator
    CallPayoff cp_01{100.00};
    CallPayoff cp_02;
    cp_02 = cp_01;
    if (cp_02.strike_price() != 100.00)
    {
        check = false;
        message = "\033[31mCallPayoff& operator=(const CallPayoff& other) failed.\033[0m";
        return {check, message};
    }

    // memory independence
    cp_01.strike_price(90.00);
    if (cp_02.strike_price() != 100.00)
    {
        check = false;
        message = "\033[31mCallPayoff& operator=(const CallPayoff& other) failed.\033[0m";
        return {check, message};
    }

    cp_02.strike_price(105.00);
    if (cp_02.strike_price() != 105.00 || cp_01.strike_price() != 90.00)
    {
        check = false;
        message = "\033[31mCallPayoff& operator=(const CallPayoff& other) failed.\033[0m";
        return {check, message};
    }

    // 2) Move Assignment Operator
    CallPayoff cp_03;
    cp_03 = std::move(cp_02);
    if (cp_03.strike_price() != 105.00)
    {
        check = false;
        message = "\033[31mCallPayoff& operator=(CallPayoff&& other) noexcept failed.\033[0m";
        return {check, message};       
    }


    // out
    return {check, message};
}

// test 03
std::tuple<bool, std::string> test_03()
{
    /*
    test_3 is designed to test the OptionInfo class.
    */

    // init return values
    bool check = true;
    std::string message = "\033[32mTest 3 passed successfully.\033[0m";

    // 1) Create CallPayoff and OptionInfo
    std::unique_ptr<Payoff> call_payoff_ptr = std::make_unique<CallPayoff>(100.00);
    OptionInfo option_info(std::move(call_payoff_ptr), 1.0); // 1 year to expiration

    // 2) Test time_to_exp getter
    if (option_info.time_to_exp() != 1.0)
    {
        check = false;
        message = "\033[31mOptionInfo::time_to_exp() failed.\033[0m";
        return {check, message};
    }

    // 3) Test option_payoff method
    double spot_price = 120.00;
    double expected_payoff = 20.00; // max(0, 120 - 100)
    if (option_info.option_payoff(spot_price) != expected_payoff)
    {
        check = false;
        message = "\033[31mOptionInfo::option_payoff(double spot) failed.\033[0m";
        return {check, message};
    }

    // out
    return {check, message};
}

// test 04
std::tuple<bool, std::string> test_04()
{
    /*
    test_4 is designed to test the PutPayoff class.
    */

    // init return values
    bool check = true;
    std::string message = "\033[32mTest 4 passed successfully.\033[0m";

    // 1) Create PutPayoff
    PutPayoff pp_01{100.00};

    // 2) Test operator() method (was not tested before)
    double spot_price = 80.00;
    double expected_payoff = 20.00; // max(0, 100 - 80)
    if (pp_01(spot_price) != expected_payoff)
    {
        check = false;
        message = "\033[31mPutPayoff::operator()(double spot) failed.\033[0m";
        return {check, message};
    }

    // out
    return {check, message};
}