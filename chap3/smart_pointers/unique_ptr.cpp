/*
unique_ptr.cpp
Demonstration of std::unique_ptr usage.

Author: Yvan Richard
Date: Fall 2025
*/

/*
+–––––––––––––––––––––––––––––+
| NOTES ON std::unique_ptr<T> |
+–––––––––––––––––––––––––––––+

+   "A unique pointer has sole (unique) ownership of a pointed-to object. It cannot be
    copied, but possession can be transferred with move semantics. The Core Guidelines
    recommend using a unique pointer as a general rule when a raw pointer would be
    otherwise needed."
    (Hanson, 2025, p. 86)

+   A


*/

#include <iostream>
#include <memory> // For std::unique_ptr
#include <string>
#include <utility> // std::move()
#include <stdexcept>

using std::string;

int main()
{
    // 1) Two lines declaration and definition
    std::unique_ptr<string> ptr_01;
    ptr_01 = std::make_unique<string>("test1");

    // 2) One line (better alternative)
    std::unique_ptr<string> ptr_02 = std::make_unique<string>("test2");

    // 3) De-referencing
    // De-referencing works as with raw pointers
    using std::cout; using std::endl;
    cout << "String stored in ptr_01: " << *ptr_01 << endl;
    cout << "String stored in ptr_02: " << *ptr_02 << endl;

    // 4) Transferring ownership with std::move()
    // This means that we do not need ptr_02 anymore but we still need its resources
    auto ptr_03 = std::move(ptr_02); 

    // if we try to de-ref ptr_02
    cout << *ptr_03 << endl;
    if (ptr_02)
        cout << *ptr_02 << endl;
    else
        cout << "ptr_02 is null after std::move()." << endl;

    // 5) Freeing memory
    // The whole point about using smart pointer (like std::unique_ptr<T>) is
    // that they get out of scope by themselves. This means that we do not need
    // to call "delete ptr_01" (in fact we should absolutely not do that!). 
    // Once our ptr goes out of scope, its resource is automatically freed.
    // However, if we want to manually delete it before it goes out of scope,
    // we can do this:

    // 5a) we do nothing
    // create a scope
    using ups = std::unique_ptr<string>; 
    {
        ups ptr_04 = std::make_unique<string>("test3");
        cout << "Can access ptr_04: " << *ptr_04 << endl;
    } // ptr_03 is freed here

    // 5b) manually freeing while still in scope
    {
        ups ptr_05 = std::make_unique<string>("test5");
        ptr_05.reset();
        if (ptr_05)
        {
            cout << "Can access ptr_05: " << *ptr_05 << endl;
        } 
        else
        {
            cout << "ptr_05 has been freed." << endl;
        }
    } // what happens here?
    // When leaving this scope, the destructor of ptr_05 is called.
    // However, ptr_05 no longer owns anything (it’s null),
    // so the destructor does nothing: no double delete, no crash.

    // BONUS: .release()
    // This set the std::unique_ptr<T> to a nullptr and return the raw pointer
    // --> useful function if we are working with old school APIs.
    // create a unique_ptr
    ups ptr_06 = std::make_unique<string>("test6");
    string *raw_ptr = ptr_06.release();

    // check that ptr_06 is indeed empty
    if(ptr_06)
    {
        cout << "ptr_06 still points to a value." << endl;
    }
    else
    {
        cout << "ptr_06 was freed." << endl;
    }

    // de-ref the raw pointer
    cout << *raw_ptr << endl;
    delete raw_ptr; // we now need to do this ourselves!!

    return 0;
}