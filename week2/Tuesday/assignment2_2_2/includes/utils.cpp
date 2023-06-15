#include "utils.h"

//Add two ints
int add (int a, int b){
    return a + b;
}
//Substacts two ints
int subtract(int a, int b){
    return a - b;
}
//Multiplies two ints
int multiply(int a, int b){
    return a * b;
}
//Divides two doubles
double divide(double a, double b){
    return a / b;
}

//Caesar_encrypt (Really dont know how this works)
std::string caesar_encrypt(std::string message) {
    std::string encrypted = "";

    for (char c : message) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            encrypted += static_cast<char>((c - base + 3) % 26 + base);
        } else {
            encrypted += c;
        }
    }

    return encrypted;
}

//Caesar_decrypt (Really dont know how this works)
std::string caesar_decrypt(std::string message) {
    std::string decrypted = "";

    for (char c : message) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            decrypted += static_cast<char>((c - base + 26 - (3 % 26)) % 26 + base);
        } else {
            decrypted += c;
        }
    }

    return decrypted;
}
//"Menu" for calculator
void calculator_input (){

    std::string operation,param1,param2;
    std::cout << "add/substract/multiply/divide/encrypt/decrypt: ";
    std::getline(std::cin,operation);

    if (operation == "add") {
        std::cout << "params: ";
        std::cin >> param1, param2;
        int a = std::stoi(param1);
        int b = std::stoi(param2);
        std::cout << add(a,b) << "\n";
    }
    if (operation == "substract") {
        std::cout << "params: ";
        std::cin >> param1, param2;
        int a = std::stoi(param1);
        int b = std::stoi(param2);
        std::cout << subtract(a,b) << "\n";
    }
    if (operation == "multiply") {
        std::cout << "params: ";
        std::cin >> param1, param2;
        int a = std::stoi(param1);
        int b = std::stoi(param2);
        std::cout << multiply(a,b) << "\n";
    }
    if (operation == "divide") {
        std::cout << "params: ";
        std::cin >> param1, param2;
        int a = std::stoi(param1);
        int b = std::stoi(param2);
        std::cout << divide(a,b) << "\n";
    }
    if (operation == "encrypt") {
        std::cout << "params: ";
        std::getline(std::cin,param1);
        std::cout << caesar_encrypt(param1) << "\n";
    }
    if (operation == "decrypt") {
        std::cout << "params: ";
        std::getline(std::cin,param1);
        std::cout << caesar_decrypt(param1) << "\n";
    }
}