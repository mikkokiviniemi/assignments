/*
Write a C++ program that calculates the sum of two integers. 
Implement a function called sum() that takes two integers as input and returns their sum.
Use an assert statement to check that the sum is positive.
If the assertion fails, display an error message indicating that the sum is not positive.
Compile the program with the NDEBUG macro defined and observe the behaviour when the assertion fails.
*/

#include <iostream>
#include <cassert>


int sum (int i1, int i2){
    return i1 + i2;
}

int main()
{
    assert((sum(2,2)>=0) && "Fail");

    assert((sum(-3,2)>=0) && "Fail"); //Will not pass

    return 0;
}
