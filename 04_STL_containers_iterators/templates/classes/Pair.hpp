/*
Pair.hpp
Defines a Pair class for illustrating templated class implementation

Author: Yvan Richard
*/

#ifndef Pair_hpp
#define Pair_hpp

namespace yvan // avoid any confusion with STL lib.
{
    template <typename T>
    class Pair
    {
    private:
        // --- Member Variables ---
        T first_;
        T second_;
    public:
        // --- Constructors & Destructor ---
        Pair();
        Pair(T first, T second);
        Pair(const Pair& other) = default;
        Pair(Pair&& other) = default;
        ~Pair() = default;

        // --- Overloaded Assignments ---
        Pair& operator=(const Pair& other) = default; 
        Pair& operator=(Pair&& other) = default;

        // --- Getters and Setters
        // Here, we return a const reference to avoid copying
        inline const T& first() const noexcept { return first_; };
        inline const T& second() const noexcept { return second_; };
        inline void set_first(const T& first) noexcept { first_ = first; };
        inline void set_second(const T& second) noexcept { second_ = second; };

        // --- Other Member Functions ---
        T max() const noexcept;

    };
}

// include the implementation in the header file
// since this is a templated class. We need to do
// this with templated classes and templated functions
// because the compiler needs to see the implementation
// when it instantiates the templated class or function.

#ifndef Pair_cpp
#include "Pair.cpp"
#endif

#endif // Pair_hpp
