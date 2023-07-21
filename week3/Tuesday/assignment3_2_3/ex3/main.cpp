/*
Exercise 3

Write a recursive function to calculate the power of a number. Your recursive function should be able to handle any size of x to the power of n.
*/

#include <iostream>

int power (int x, int n) {
    if(n == 1){
        return x;
    }
    else {
        return x * power(x,n-1);
    }
}

int main()
{
    
    std::cout << power(3,3);
    
    return 0;
}
