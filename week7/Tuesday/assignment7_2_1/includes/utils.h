#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <type_traits>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

/*
function with an integer template parameters, that prints out the first integer
value, and then calls the function with remaining values.  Break the recursion using
overload resolution.
*/
template <typename T>
T exercise_one_a(T value) {
    std::cout << value;
    return value;
}

/*
function with an integer template parameters, that prints out the first integer
value, and then calls the function with remaining values.  Break the recursion using
overload resolution.
*/
template <typename T, typename... Ts>
T exercise_one_a(T value, Ts... args) {
    std::cout << value;
    return exercise_one_a(args...);
}

/*
function with an integer template parameters, that prints out the first integer
value, and then calls the function with remaining values.  Break the recursion using
if contexpr
*/
template <typename T, typename... Ts>
T exercise_one_b(T value, Ts... args) {
    if constexpr(sizeof...(args) > 0){
        std::cout << value;
        return exercise_one_b(args...); 
    }
    std::cout << value;
    return value;
}
/*
function that takes arbitrary number of arguments and returns the sum of the
arguments.  How should you handle errors (such as argument not being a number) here?
*/
template <typename T, typename... Ts>
T exercise_two(T value, Ts... args) {
    if (!std::is_arithmetic<T>::value) {
        throw std::runtime_error("Invalid type");
    }

    if constexpr (sizeof...(args) > 0) {
        return value + exercise_two(args...);
    }
    return value;
}

/*
In exercise 7.1.1. we created a function to check if two types are the same.  Expand on this
to check if any number of types given are all the same.
*/

// Base case
template<typename T>
bool check_same_type() {
    return true;
}
// Recursive case
template<typename T, typename U, typename... Ts>
bool check_same_type() {
    return std::is_same_v<T, U> && check_same_type<U, Ts...>();
}

template<typename... Ts>
bool check_same_type(const Ts&... args) {
    return check_same_type<Ts...>();
}

/*
function that takes arbitrary number of arguments and return the product of the
arguments times the number of arguments.
*/
template <typename... Ts>
auto exercise_four(Ts... args) {
    constexpr size_t args_count = sizeof...(Ts);
    return (args * ... * 1) * args_count;
}

/*
function that takes arbitrary number of containers as arguments and creates a
concatenated container.  (e.g. concatenate(std::vector{1, 2}, std::list{5, 8}) -> std::vector{1, 2, 5, 8};
*/

template <typename T, typename... Ts>
T exercise_five(const T& container, Ts&&... args) {
    T result = container;
    ((result.insert(result.end(), args.begin(), args.end())), ...);
    return result;
}


#endif  