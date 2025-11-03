#ifndef LinkedList_cpp
#define LinkedList_cpp

#include "LinkedList.hpp"
#include <memory>
#include <stdexcept>
#include <iostream>

namespace yvan
{
    // --- Constructor & Destructor ---
    template <typename T>
    LinkedList<T>::LinkedList() :
        front_(nullptr), back_(nullptr), size_(0) { }

    // --- Main Methods ---
    // push_back()
    template <typename T>
    void LinkedList<T>::push_back(const T& value)
    {
        // create a new node with input value
        auto new_node = std::make_unique<Node<T>>(value, nullptr);

        // empty list
        if(this->empty())
        {
            front_ = std::move(new_node); // front_ owns ownership
            back_ = front_.get(); // non-owning raw pointer
        }
        else // non-empty list
        {
            // link to previous node
            back_->ptr_next_ = std::move(new_node); // the previous node owns ownership of this one
            back_ = back_->ptr_next_.get(); // raw pointer without ownership (otherwise it would be release())
        }
        
        // update size count
        ++size_;
    }
    // push_front()
    template <typename T>
    void LinkedList<T>::push_front(const T& value)
    {
        auto new_node = std::make_unique<Node<T>>(value, nullptr);
        // empty list
        if(this->empty())
        {
            front_ = std::move(new_node);
            back_ = front_.get();
        }
        else // non-empty list
        {
            new_node->ptr_next_ = std::move(front_);
            front_ = std::move(new_node);
        }
        ++size_;
    }
    // pop_front()
    template <typename T>
    T LinkedList<T>::pop_front()
    {
        if(this->empty())
        {
            throw std::out_of_range("Cannot pop_front() on empty LinkedList");
        }
        
        // copy the object
        T out_value = front_->value_;

        // update linked list
        front_ = std::move(front_->ptr_next_);

        // check for list emptiness
        if(!front_) back_ = nullptr;

        --size_;

        return out_value;
    }
    // print()
    template <typename T>
    void LinkedList<T>::print() const noexcept
    {
        // iterate over the entire linked list
        // and print the value in each node.
        // we assume that << is properly overloaded for type T.
        if (this->empty())
        {
            std::cout << "[]" << std::endl;
            return;
        }
        if (size_ == 1)
        {
            std::cout << "[" << front_->value_ << "]" << std::endl;
            return;
        }
        auto current_node = front_.get(); // no ownership
        std::cout << "[";
        do
        {
            auto v = current_node->value_;
            std::cout << v << ", ";
            current_node = current_node->ptr_next_.get();

        } while (current_node != back_);

        // once we are the back, print back of the list
        std::cout << back_->value_ << "]" << std::endl;
        
    }
}

#endif // LinkedList_cpp
