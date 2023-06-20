/*
Exercise 2

Write a recursive function that finds the Greatest Common Divisor of two numbers. Hint:  you can use the Euclidean algorithm.
*/

#include <iostream>

int greatest_common_division (int a, int b) {
    if (b == 0){
        return a;
    } else {
        return greatest_common_division(b,a%b);
    }

}

int main()
{
    std::cout << greatest_common_division(56,42);
    return 0;
}
