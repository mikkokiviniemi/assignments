/*
Exercise 1a.

Create a function with an (typename/integer) template parameters, that prints out the first integer
value, and then calls the function with remaining values.  Break the recursion using
overload resolution.

Exercise 1b.

Create a function with an (typename/integer) template parameters, that prints out the first integer
value, and then calls the function with remaining values.  Break the recursion using
if constexpr

 

Exercise 2.

Create a function that takes arbitrary number of arguments and returns the sum of the
arguments.  How should you handle errors (such as argument not being a number) here?

 

Exercise 3.

In exercise 7.1.1. we created a function to check if two types are the same.  Expand on this
to check if any number of types given are all the same.

 

Exercise 4.

Create a function that takes arbitrary number of arguments and return the product of the
arguments times the number of arguments.

 

Exercise 5.

Create a function that takes arbitrary number of containers as arguments and creates a
concatenated container.  (e.g. concatenate(std::vector{1, 2}, std::list{5, 8}) -> std::vector{1, 2, 5, 8};
*/

#include <iostream>
#include <vector>
#include <list>
#include "utils.h"

int main()
{
    //Ex1
    exercise_one_a(1,2,3,4,5,6,7,8,9);
    std::cout << "\n";
    exercise_one_b(1,2,3);
    std::cout << "\n";
    std::cout << exercise_two(1,2,3);
    std::cout << "\n";
    std::cout << check_same_type(1,2,4,5);
    std::cout << "\n";
    std::cout << exercise_four(1,2,3,4,5);
    std::cout << "\n";
    std::vector<int> vec1 = {1, 2};
    std::list<int> list1 = {5, 8};
    std::vector<int> vec2 = {10, 20, 30};
    auto ex_5 = exercise_five(vec1, list1, vec2);
    for (const auto& elem : ex_5) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    return 0;
}
