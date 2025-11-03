/*
Pair.cpp
Implements the Pair class for illustrating templated class implementation

Author: Yvan Richard
Date: Fall 2025
*/

// include the header file
#include "Pair.hpp"

namespace yvan
{
    // --- Constructors & Destructor ---
    template <typename T>
    Pair<T>::Pair() : first_{}, second_{} {} 
    // assumes that T has a default constructor

    template <typename T>
    Pair<T>::Pair(T first, T second) : first_{first}, second_{second} {}

    // --- Other Member Functions ---
    template <typename T>
    T Pair<T>::max() const noexcept
    {
        // assumes that the > operator is defined for type T
        return (first_ > second_) ? first_ : second_;
    }
} // namespace yvan
