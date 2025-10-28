/*
PatternAnalytics.hpp
This file holds the declarations of the PatternAnalytics class.

Author: Yvan Richard
Date: Fall 2025
*/

#include "../include/PatternAnalytics.hpp"
#include <cmath>
#include <stdexcept>

// --- Constructors ---
PatternAnalytics::PatternAnalytics() : data_{} { }
PatternAnalytics::PatternAnalytics(double def_val, size_t s) : data_(s, def_val) { }
PatternAnalytics::PatternAnalytics(const std::vector<double>& data) : data_(data) { }
PatternAnalytics::PatternAnalytics(const PatternAnalytics& source) : data_(source.data_) { }
PatternAnalytics::PatternAnalytics(PatternAnalytics&& source) : data_(std::move(source.data_)) { }

// --- Copy/Move Assignment ---
PatternAnalytics& PatternAnalytics::operator=(const PatternAnalytics& source)
{
    if (this == &source) return *this; // self-assignment check
    data_ = source.data_;
    return *this;
}

PatternAnalytics& PatternAnalytics::operator=(PatternAnalytics&& source)
{
    if (this == &source) return *this; // self-assignment check
    data_ = std::move(source.data_); // vector already implements move semantics
    return *this;
}

// --- Summary Stats ---
double PatternAnalytics::mean() const
{
    if (data_.empty()) throw std::runtime_error("PatternAnalytics::mean() - No data available.");
    double sum = 0.0;
    for (const auto& val : data_) sum += val;
    return sum / data_.size();
}
double PatternAnalytics::var() const
{
    if (data_.empty()) throw std::runtime_error("PatternAnalytics::var() - No data available.");
    if (data_.size() < 2) return 0.0; // Variance undefined for size < 2
    double m = mean();
    double sum_sq_diff = 0.0;
    for (const auto& val : data_) sum_sq_diff += (val - m) * (val - m);
    return sum_sq_diff / (data_.size() - 1);
}
double PatternAnalytics::std() const
{
    return std::sqrt(var());
}
double PatternAnalytics::corr(const PatternAnalytics& other) const
{
    if (data_.size() != other.data_.size())
        throw std::invalid_argument("PatternAnalytics::corr() - Vectors must be of the same size.");
    if (data_.empty()) throw std::runtime_error("PatternAnalytics::corr() - No data available.");
    double mean1 = mean();
    double mean2 = other.mean();
    double num = 0.0;
    double denom1 = 0.0;
    double denom2 = 0.0;
    for (size_t i = 0; i < data_.size(); ++i)
    {
        double diff1 = data_[i] - mean1;
        double diff2 = other.data_[i] - mean2;
        num += diff1 * diff2;
        denom1 += diff1 * diff1;
        denom2 += diff2 * diff2;
    }
    double denom = std::sqrt(denom1 * denom2);
    return (denom == 0.0) ? 0.0 : num / denom;
}
double PatternAnalytics::max() const
{
    if (data_.empty()) throw std::runtime_error("PatternAnalytics::max() - No data available.");
    double max_val = data_[0];
    for (const auto& val : data_) if (val > max_val) max_val = val;
    return max_val;
}
double PatternAnalytics::min() const
{
    if (data_.empty()) throw std::runtime_error("PatternAnalytics::min() - No data available.");
    double min_val = data_[0];
    for (const auto& val : data_) if (val < min_val) min_val = val;
    return min_val;
}

