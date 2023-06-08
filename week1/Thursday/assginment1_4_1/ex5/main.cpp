/*
Write a C++ program that calculates the square root of a given number.
Implement a function called square_root() that takes a non-negative floating-point number as input and returns its square root.
Use an assert statement to check that the input number is non-negative.
If the assertion fails, display an error message indicating that the square root is not defined for negative numbers.
Compile the program both with and without the NDEBUG macro defined and observe the behaviour when the assertion fails in each case.
*/

#include <iostream>
#include <cmath>
#include <cassert>

float square_root (float number) {

    assert((number >= 0) && "Fail");
    return std::sqrt(number);
}

int main()
{
    std::cout << square_root(3);
    //std::cout << square_root(-3);
    return 0;
}
