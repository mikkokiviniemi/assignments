/*
Create a calculator program that can do basic operations: 
Addition, subtraction, multiplication and division. 
In your program, create a user interface that asks for basic calculation operations. 
All calculations should be executed in a utility library.

+ encrypt and decrypt caesar
*/

#include <iostream>
#include "utils.h"

int main(int argc, char const *argv[])
{
    if(argv[1] == NULL){
        calculator_input();
        return 0;
    }
    std::string operation = argv[1];

    if (operation == "add") {
        int a = std::stoi(argv[2]);
        int b = std::stoi(argv[3]);
        std::cout << add(a,b) << "\n";
    }
    else if (operation == "substract") {
        int a = std::stoi(argv[2]);
        int b = std::stoi(argv[3]);
        std::cout << subtract(a,b) << "\n";
    }
    else if (operation == "multiply") {
        int a = std::stoi(argv[2]);
        int b = std::stoi(argv[3]);
        std::cout << multiply(a,b) << "\n";
    }
    else if (operation == "divide") {
        int a = std::stod(argv[2]);
        int b = std::stod(argv[3]);
        std::cout << divide(a,b) << "\n";
    }
    else if (operation == "encrypt") {
        std::cout << caesar_encrypt(argv[2]) << "\n";
    }
    if (operation == "decrypt") {
        std::cout << caesar_decrypt(argv[2]) << "\n";
    }

    return 0;
}
