/*
Write a C++ program that performs division of two numbers.
Implement a function called divide() that takes two integers as input and returns their division result.
Use an assert statement to check that the second number (denominator) is not zero.
If the assertion fails, display an error message indicating that division by zero is not allowed.
Compile the program both with and without the NDEBUG macro defined and observe the behavior when the assertion fails in each case
*/

#include <iostream>
#include <cassert>

float divide(float num1, float num2) {
    float ans;

    assert((num2 != 0) && "Fail");

    ans = num1/num2;

    return ans;
}

int main()
{

    std::cout << divide(7,3);
    //std::cout << divide(7,0);

    return 0;
}
