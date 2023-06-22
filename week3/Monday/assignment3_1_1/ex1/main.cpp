/*
1. Write a program that performs a division operation. 
The user should input two numbers. 
The program should catch and handle the possibility of a division by zero error. 
*/
#include <iostream>
#include <exception>

double divide(int a, int b) {
    if(b == 0) {
        throw std::runtime_error("Division by zero");
    }
    return a/b;
}

int main()
{
    try {
        std::cout << divide(4,0);
    } catch (std::runtime_error e) {
        std::cout << e.what();
    }
    return 0;
}
