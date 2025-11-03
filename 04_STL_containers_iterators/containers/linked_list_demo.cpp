/*
linked_list_demo.cpp
This file demonstrate the very simple usage of our single linked list.
*/

#include "classes/LinkedList.hpp"
#include <iostream>

int main()
{

    // init. a linked list of integers
    yvan::LinkedList<int> l1;
    l1.push_back(1);
    l1.push_front(0);
    l1.push_back(2);
    l1.print(); // expected output: [0, 1, 2]

    // pop front
    int v = l1.pop_front();
    std::cout << "popped value: " << v << std::endl; // expected output: 0
    l1.print(); // expected output: [1, 2]

    // pop front again
    v = l1.pop_front();
    std::cout << "popped value: " << v << std::endl; // expected output: 1
    l1.print(); // expected output: [2]

    // pop front last time
    v = l1.pop_front();
    std::cout << "popped value: " << v << std::endl; // expected output: 2
    l1.print(); // expected output: []

    // try to pop from empty list (should throw an exception)
    try
    {
        v = l1.pop_front();
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

/*
+––––––––+
| Output |
+––––––––+
[0, 1, 2]
popped value: 0
[1, 2]
popped value: 1
[2]
popped value: 2
[]
Exception caught: Cannot pop_front() on empty LinkedList
*/