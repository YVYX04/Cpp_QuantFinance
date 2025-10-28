/*
SimpleClass.hpp
This file contains the declaration of the SimpleClass.
This class was created according to Hanson (2025, p. 45)
in an effort to illustrate move semantics.

Author: Yvan Richard
Date: Fall 2025
*/

#ifndef SimpleClass_hpp
#define SimpleClass_hpp

class SimpleClass
{
private:
    int* ptr_; // pointer to an int

public:
    // --- Constructors ---
    SimpleClass();
    SimpleClass(int k);

    // copy constructor
    SimpleClass(const SimpleClass& source);

    // move constructor
    SimpleClass(SimpleClass&& other);

    // --- Getter & Setter ---
    int get_val() const;
    void set_val(int k);

};

#endif