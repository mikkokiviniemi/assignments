/*
Write a program that reads in a list of integers and finds the maximum value. Return an error code if the list is empty.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

int find_max (const std::vector<int>& int_vector) {

    if (int_vector.empty()){
        throw std::runtime_error("Empty vector");
    }
    auto i = max_element(std::begin(int_vector), std::end(int_vector));
    return *i;
}

int main()
{
    try {
        std::vector<int> some_vector = {};
        std::cout << find_max(some_vector);
    } catch (std::exception& e){
        std::cout <<"Error: "<< e.what() << "\n";
    }

    return 0;
}
