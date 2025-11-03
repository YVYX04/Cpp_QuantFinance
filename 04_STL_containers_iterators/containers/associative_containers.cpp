/*
associative_containers.cpp
This file contains examples and tests for C++20 associative containers,
including std::set and std::map.

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include <set>
#include <map>
#include <string>

void test_set()
{
    std::set<int> my_set;

    // Inserting elements into the set is time complexity O(log n) because re-ordering may be required
    // If the data type has no defined ordering, a compilation error will occur
    my_set.insert(5);
    my_set.insert(2);
    my_set.insert(8);
    my_set.insert(5); // Duplicate, will not be added

    // Displaying elements
    std::cout << "Elements in the set: ";
    for (const auto& elem : my_set)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Checking existence with find()
    // find() returns an iterator to the element if found, or end() if not found
    // end() is an iterator that points one past the last element
    int value_to_find = 2;
    if (my_set.find(value_to_find) != my_set.end())
    {
        std::cout << value_to_find << " found in the set." << std::endl;
    }
    else
    {
        std::cout << value_to_find << " not found in the set." << std::endl;
    }
}

void test_map()
{
    std::map<std::string, int> my_map;

    // Inserting key-value pairs into the map (we can also use .insert() method)
    my_map["apple"] = 1;
    my_map["banana"] = 0;
    my_map["orange"] = 3;

    // .insert() example:
    my_map.insert({"grape", 4});

    // Displaying elements
    std::cout << "Elements in the map:" << std::endl;
    for (const auto& pair : my_map)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Accessing values using keys
    std::string key_to_find = "banana";
    if (my_map.find(key_to_find) != my_map.end())
    {
        std::cout << key_to_find << " found with value: " << my_map[key_to_find] << std::endl;
    }
    else
    {
        std::cout << key_to_find << " not found in the map." << std::endl;
    }
}

int main()
{
    std::cout << "Testing std::set:" << std::endl;
    test_set();

    std::cout << "\nTesting std::map:" << std::endl;
    test_map();

    return 0;
}