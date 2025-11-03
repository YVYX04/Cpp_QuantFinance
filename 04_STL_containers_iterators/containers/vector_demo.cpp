/*
vector_demo.cpp
Demonstration of basic operations with std::vector and class BankAccount.

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include <vector>
#include "classes/BankAccount.hpp"

using std::cout, std::endl;

int main()
{
    // 1) Instantiate a vector of BankAccount objects
    std::vector<BankAccount> accounts;

    // At instantiation time, the vector is empty, as evidenced here:
    cout << "The size of the vector at instantiation: " << accounts.size() << endl;

    // We can also check emptiness
    if (accounts.empty()) cout << "The accounts vector is indeed empty." << endl;

    // Interestingly, we can also check its capacity
    cout << "The capacity of the vector at instantiation: " << accounts.capacity() << endl;

    // 2) .push_back() and .emplace_back()
    // .push_back
    BankAccount ba1(100.0, 0.02);
    accounts.push_back(ba1);
    cout << "The size of the vector after push_back: " << accounts.size() << endl;

    
    // .emplace_back()
    accounts.emplace_back(250.0, 0.01);
    cout << "The size of the vector after emplace_back: " << accounts.size() << endl;

    // capacity may have changed
    cout << "The capacity of the vector after adding elements: " << accounts.capacity() << endl;

    /*
    The difference between .push_back and .emplace_back()
    (Hanson, 2025, p. 114)
    ---
    
    "With push_back, an element in the
    vector will take in a BankAccount object with its copy constructor. This can be
    verified by setting the BankAccount copy constructor to delete and noticing the code
    will not compile. In a more realistic situation with a vector containing thousands of
    larger object elements, the performance hit could add up significantly.

    [...]

    If the calling code knows which arguments to pass in order to construct
    an object but does not have the object on hand, calling emplace_back(.) with the
    constructor arguments will let the container create the object for us, saving one
    construction (and one destruction) with every call.

    [...]

    emplace_back(.) is mostly useful
    if the object to add to the container has not been constructed yet. If you have
    a full object on hand, simply use push_back(obj), or alternatively you can use
    push_back(std::move(obj)) to avoid the costs of object copying, if obj is no longer
    needed outside the container.
    */

    // 3) resize() and reserve()
    // resize() to increase size and initialize new elements with default constructor
    accounts.resize(5);
    cout << "The size of the vector after resize(5): " << accounts.size() << endl;
    cout << "The capacity of the vector after resize(5): " << accounts.capacity() << endl;

    // reserve() to increase capacity without changing size
    accounts.reserve(10);
    cout << "The size of the vector after reserve(10): " << accounts.size() << endl;
    cout << "The capacity of the vector after reserve(10): " << accounts.capacity() << endl;

    // WARNING:
    // For efficiency reasons, we want to avoid frequent reallocations of the vector's internal array.
    // Meaning that if we know in advance approximately how many elements we will need,
    // we should call reserve() with that number before adding elements to the vector.
    // Otherwise, the vector may need to reallocate its internal array multiple times as it grows,
    // which can be costly in terms of performance.

    // 4) The clear() method
    // clear() removes all elements from the vector, setting its size to 0
    accounts.clear();
    cout << "The size of the vector after clear(): " << accounts.size() << endl;
    cout << "The capacity of the vector after clear(): " << accounts.capacity() << endl; // capacity remains unchanged

    // 5) front(), back(), and pop() methods
    std::vector<int> numbers;
    numbers.reserve(5);
    for (int i = 0; i < 5; ++i) numbers.push_back(i + 1); // add numbers 1 to 5

    cout << "First element (front): " << numbers.front() << endl;
    cout << "Last element (back): " << numbers.back() << endl;
    numbers.pop_back(); // remove last element
    cout << "Last element after pop_back: " << numbers.back() << endl;

    /*
    Why don't we have a pop_front() method for std::vector?
    ---
    The reason std::vector does not have a pop_front() method is due to the underlying
    data structure and performance considerations. std::vector is implemented as a dynamic
    array, which allows for efficient random access and appending elements at the end.
    However, removing an element from the front of the vector would require shifting all
    subsequent elements one position to the left to fill the gap, which is an O(n)
    operation. This can be inefficient, especially for large vectors.
    If we need to frequently remove elements from the front of a collection, we should
    consider using std::deque (double-ended queue) instead, which is designed to allow efficient
    insertion and deletion of elements at both the front and back.
    */

    // 6) Random access with operator[] and at()
    numbers.clear();
    for (int i = 0; i < 5; ++i) numbers.push_back((i + 1) * 10); // add numbers 10, 20, ..., 50
    cout << "Element at index 2 using operator[]: " << numbers[2] << endl;
    cout << "Element at index 2 using at(): " << numbers.at(2) << endl;

    // Note: at() performs bounds checking and will throw an exception if the index is out of range
    try
    {
        cout << "Element at index 10 using at(): " << numbers.at(10) << endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Error: " << e.what() << endl;
    }

    return 0;
}