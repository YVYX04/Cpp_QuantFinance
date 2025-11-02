/*
OptionInfo.hpp
Defines OptionInfo class to hold option parameters.

Author: Yvan Richard
Date: Fall 2025
*/

#ifndef OptionInfo_hpp
#define OptionInfo_hpp

#include <memory>
#include "Payoff.hpp"

class OptionInfo
{
private:
    // --- Member Variables ---
    std::unique_ptr<Payoff> payoff_ptr_; // smart pointer to the option payoff [1]
    double time_to_exp_;

public:
    // --- Constructors ---
    OptionInfo(std::unique_ptr<Payoff> payoff_ptr, double time_to_exp); // classic ctor
    OptionInfo(const OptionInfo& source) = default; // copy ctor
    OptionInfo(OptionInfo&& rhs) = default; // move ctor

    // --- Destructor ---
    ~OptionInfo() = default;

    // --- Assignment Operators ---
    OptionInfo& operator=(const OptionInfo& source) = default;      // classic assignment
    OptionInfo& operator=(OptionInfo&& rhs) = default;              // move semantic

    // --- Getter & Setter ---
    double time_to_exp() const;

    // --- General Methods ---
    double option_payoff(double spot) const;

};





# endif // OptionInfo_hpp


/*
+–––––––+
| NOTES |
+–––––––+

[1]. We use a unique pointer to the Payoff object to avoid copying the Payoff
     object for nothing (i.e. if we use it by value). Furthermore, the fact that
     it is declared as a unique pointer means that we will avoid some dangerous
     and unsafe behaviour (e.g. shallow copy).
*/