/*
main.cpp
This program is used to demonstrate simple C++20 applications
of the classes we are building in this sub-project.

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include <utility> // std::move(.)
#include "include/SimpleClass.hpp"
using std::cout;
using std::endl;


int main()
{
    // Create an instance of the class
    SimpleClass sc1{1};

    // If we need the same instance, we can rely on the default copy-ctor
    SimpleClass sc2{sc1};
    // SimpleClass sc3 = sc1; -> also copy-ctor mechanics, not assignment

    // -> overhead of object copy: can lower performance for big objects.
    
    // MOVING THE OBJECT
    // Now, let us suppose that after sc2{sc1}, we do not need sc1 anymore.
    // We can then "move" its content into sc4, avoiding the copy overhead.
    SimpleClass sc4{std::move(sc1)};

    sc4.set_val(3);
    cout << sc4.get_val() << endl; // 3
    // cout << sc1.get_val() << endl; // trow a std::runtime_error "Attempted to de-reference nullptr in get_val()."

    return 0;
}