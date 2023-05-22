#include <iostream>

int main(){

    std::cout << "Enter first float: ";

    std::string first;
    std::getline(std::cin, first);

    std::cout << "Enter second float: ";

    std::string second;
    std::getline(std::cin, second);

    float int1 = std::stof(first);

    float int2 = std::stof(second);

    std::cout << "Sum: "<< int1+int2 << std::endl;
    std::cout << "Diff: "<< int1-int2 << std::endl;



    return 0;
}