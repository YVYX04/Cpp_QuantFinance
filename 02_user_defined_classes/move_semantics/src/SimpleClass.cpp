/*
SimpleClass.cpp
This file implements the declarations of the SimpleClass class.

Author: Yvan Richard
Date: Fall 2025
*/

#include "../include/SimpleClass.hpp"
#include <stdexcept>
#include <iostream>

// --- Constructors ---
SimpleClass::SimpleClass() : ptr_{nullptr} { }
SimpleClass::SimpleClass(int k) : ptr_{new int{k}} { }
SimpleClass::SimpleClass(const SimpleClass& source) : ptr_{new int{*(source.ptr_)}} { }
SimpleClass::SimpleClass(SimpleClass&& other) :
ptr_(other.ptr_) // "steal the pointer"
{
    // nullify the moved-from object pointer
    other.ptr_ = nullptr;
}

// --- Getter & Setter ---
int SimpleClass::get_val() const
{
    if (ptr_ != nullptr) return *(ptr_);
    else throw std::runtime_error("Attempted to de-reference nullptr in get_val().\n");
}
void SimpleClass::set_val(int k)
{
    if (ptr_ != nullptr) *(ptr_) = k;
    else
    {
        // allocate resources
        ptr_ = new int{k};
        
        // warn user
        std::cerr << "SimpleClass::set_val() dynamically allocated resources for an int.\n";
    }
}

