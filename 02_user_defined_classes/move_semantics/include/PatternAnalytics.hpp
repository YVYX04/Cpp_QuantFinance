/*
PatternAnalytics.hpp
This file holds the declarations of the PatternAnalytics class.

Author: Yvan Richard
Date: Fall 2025
*/

#ifndef PatternAnalytics_hpp
#define PatternAnalytics_hpp

#include <vector>
class PatternAnalytics
{
private:
    // --- Member Variables ---
    std::vector<double> data_;

public:
    // --- Constructors ---
    PatternAnalytics();
    PatternAnalytics(double def_val, size_t s);
    PatternAnalytics(const std::vector<double>& data);
    PatternAnalytics(const PatternAnalytics& source);
    PatternAnalytics(PatternAnalytics&& source);

    // --- Copy/Move Assignment ---
    PatternAnalytics& operator=(const PatternAnalytics& source);
    PatternAnalytics& operator=(PatternAnalytics&& source);

    // --- Summary Stats ---
    double mean() const;
    double var() const;
    double std() const;
    double corr(const PatternAnalytics& other) const;
    double max() const;
    double min() const;
};

#endif // PatternAnalytics_hpp