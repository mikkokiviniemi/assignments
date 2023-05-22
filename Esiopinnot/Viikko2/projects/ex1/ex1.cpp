#include <iostream>

int main(){

    std::cout << "Enter first integer: ";

    std::string first;
    std::getline(std::cin, first);

    std::cout << "Enter second integer: ";

    std::string second;
    std::getline(std::cin, second);

    int int1 = std::stoi(first);

    int int2 = std::stoi(second);

    std::cout << "Sum: "<< int1+int2 << std::endl;
    std::cout << "Diff: "<< int1-int2 << std::endl;



    return 0;
}