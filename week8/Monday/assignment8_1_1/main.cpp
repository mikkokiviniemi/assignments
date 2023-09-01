/*
Exercise 1

Create a stack variable of any fundamental type in main() function (so just an usual declaration).
Then print out its memory address.

Create a function in the same program and do the same.
Compute the difference between the addresses and print that out too.

Exercise 2

std::vector uses heap memory internally to store its contents.
Create an std::vector, throw in some elements and print out the address of the vector itself and all of its elements.  
Think about what you see.Is the vector's position in the memory same as its contents?  Why?

Exercise 3

Elements being contiguous in memory is an important concept.
This means they are located in the memory one after another.
Create a (template) function that takes a container as its input, and checks if the elements in the container are next to each other.
Create few container types (list, vector, array, deque) and check if this holds true.
Try it with different counts of elements (e.g. with 1000, 1000000, 100000000 elements)
 

Exercise 4

Check if std::vector of std::vectors is contiguous.
*/

#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <list>
#include "utils.h"

//EX1
int exercise1 () {
    int variable = 7;
    return variable;
}

//EX3
template <typename T>
bool exercise3(const std::list<T>& container) {
    if (container.empty()) {
        return true;
    }
    return &container.back() == &container.front() + container.size() - 1;
}

template <typename T>
bool exercise3(const T& container) {
    if (container.empty()) {
        return true;
    }
    return &container.at(container.size() - 1) == &container.at(0) + container.size() - 1;
}

int main()
{
    //EX 1
    int variable = 3;
    auto function_value = reinterpret_cast<int*>(&exercise1);
    std::cout << "EX 1: " << &variable << " " << function_value << "\n" << "Difference " << function_value - &variable << "\n";

    //EX 2
    std::vector<int> ex2;
    ex2.push_back(1);
    ex2.push_back(2);
    ex2.push_back(3);
    std::cout << "EX 2: " << &ex2 << "\n" << &ex2.at(0) << " " << &ex2.at(1) << " " << &ex2.at(2) << "\n";

    //EX 3
    std::vector<int> ex3_vector;
    for (int i = 0; i < 1000; i++) {
        ex3_vector.push_back(i);
    }
    std::cout << "EX3_vector: " << std::boolalpha << exercise3(ex3_vector) << "\n";

    std::deque<int> ex3_deque;
    for (int i = 0; i < 1000; i++) {
        ex3_deque.push_back(i);
    }
    std::cout << "EX3_deque: " << std::boolalpha << exercise3(ex3_deque) << "\n";

    std::array<int,1000> ex3_array;
    for (int i = 0; i < 1000; i++) {
        ex3_array[i] = i;
    }
    std::cout << "EX3_array: " << std::boolalpha << exercise3(ex3_array) << "\n";

    std::list<int> ex3_list;
    for (int i = 0; i < 1000; i++) {
        ex3_list.push_back(i);
    }
    std::cout << "EX3_list: " << std::boolalpha << exercise3(ex3_list) << "\n";

    //EX 4
    std::list<std::vector<int>> ex4_vec;
    for (int i = 0; i < 1000; i++) {
        std::vector<int> new_vec = {i};
        ex4_vec.push_back(new_vec);
    }
    std::cout << "EX4_vec: " << std::boolalpha << exercise3(ex4_vec) << "\n";

    return 0;
}
