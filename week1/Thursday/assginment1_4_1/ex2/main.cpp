/*
Write a C++ program that calculates the factorial of a given number.
Implement a function called factorial() that takes an integer as input and returns its factorial.
Use an assert statement to check that the input number is non-negative.
If the assertion fails, display an error message indicating that the factorial is not defined for negative numbers.
Test your program with various input values, including both positive and negative numbers.
*/

#include <iostream>
#include <cassert>


int factorial (int number) {
    

    assert((number>=0) && "Fail");

    int ans = 1;

    if(number == 0 || number == 1) {
        return ans;
    } else {
        for (int i = 1;i < number + 1; i++){
            ans = ans * i;
        }
    }

    return ans;

}

int main()
{

    std::cout << factorial(3);
    std::cout << factorial (0);
    std::cout << factorial(-1);

    return 0;
}
