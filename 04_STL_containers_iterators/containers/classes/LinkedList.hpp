/*
LinkedList.hpp
This file contains the declaration of the LinkedList class. Am extremelly basic implementation
of a linked list to illustrate why it does not behave as an array (i.e. storing data contiguously
in memory) and why we should favor std::vector over std::list whenever possible. This class
if for illustrative purpose only, not an efficient implementation of a single linked list.

Author: Yvan Richard
Date: Fall 2025
*/


#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <memory>

namespace yvan
{
    template <typename T>
    struct Node
    {
        T value_;
        std::unique_ptr<Node<T>> ptr_next_;
    };

    template <typename T>
    class LinkedList
    {
    private:
        // --- Member Variables ---
        std::unique_ptr<Node<T>> front_; // unique_ptr to the first node of the list
        Node<T>* back_;                  // raw pointer to the last node of the list
        size_t size_;                    // number of elements in the linked list

    public:
        // --- Constructor & Destructors ---
        LinkedList();                   // empty list init.
        ~LinkedList() = default;        // our unique pointer handles the clean-up

        // --- Main Methods ---
        // size()
        inline size_t size() const noexcept { return size_; }
        // empty()
        inline bool empty() const noexcept { return !front_; }
        // push_back()
        void push_back(const T& value);
        // push_front()
        void push_front(const T& value);
        // pop_front(): delete first element in the linked list and return a copy of it
        T pop_front();
        // print()
        void print() const noexcept;

        /*
        WARNING: Why no pop_back() ?
        ---
        Inefficient to implement pop_back() for a SINGLE linked list
        since we do not track in the node the previous node. This means that
        we should traverse the entire single linked list (O(n)) for implementing
        this method!
        */
    };

} // namespace yvan



// include implementation
#ifndef LinkedList_cpp
#include "LinkedList.cpp"
#endif // LinkedList_cpp

#endif // LinkedList_hpp