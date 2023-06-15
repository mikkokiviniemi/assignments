#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>

/*
Addition, subtraction, multiplication and division. + encrypt and decrypt caesar
*/

int add (int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(double a, double b);
std::string caesar_decrypt(std::string message);
std::string caesar_encrypt(std::string message);
void calculator_input();


#endif  