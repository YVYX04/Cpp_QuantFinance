/*
unique_ptr.cpp
Demonstration of std::shared_ptr usage.

Author: Yvan Richard
Date: Fall 2025
*/

/*
+–––––––––––––––––––––––––––––+
| NOTES ON std::shared_ptr<T> |
+–––––––––––––––––––––––––––––+

In contrast to a unique pointer—which, as indicated by its name, is uniquely respon‐
sible for a pointed-to object in memory—a shared pointer can share this responsibility
with another shared pointer. Although similar to a raw pointer, a shared pointer is
a safer alternative because the pointed-to memory will not be released until the last
remaining shared pointer to a given shared pointee goes out of scope. This is made
possible behind the scenes by reference counting, which keeps count of the number
of active shared pointers to a common block of heap memory. The pointed-to object
will persist until the count reaches zero, and only at this point will the memory
be deallocated, thus preventing a memory leak and possible undefined behavior at
runtime.

(Hanson, 2025, p. 88)
*/

#include <iostream>
#include <memory> // For std::shared_ptr
#include <string>
#include <utility> // std::move()


using std::string;
using std::cout; using std::endl;

int main()
{
    // 1) An example of reference counting
    using sps = std::shared_ptr<string>;

    sps ptr_01 = std::make_shared<string>("string_01");

    cout << ptr_01.use_count() << endl; // 1
    {
        auto ptr_02 = ptr_01;
        auto ptr_03 = ptr_02;
        cout << ptr_03.use_count() << endl; // 3

        // .reset
        ptr_03.reset();

        cout << ptr_01.use_count() << endl; // 2
    }
    cout << ptr_01.use_count() << endl;
    /*
    expected output:
    1
    3
    2
    1
    */



    return 0;
}
