/*
Overload a function called process_data(). 
One version should accept an integer and the other a string. 
If the integer is negative or the string contains any non-alphabet characters, throw an exception.
*/
#include <iostream>
#include <exception>

int process_data(int data){
    if (data < 0) {
        throw std::invalid_argument("Wrong type integer");
    }
    return 1;
}

int process_data(std::string data) {
    for(auto& c : data) {
        if (!isalpha(c)){
            throw std::invalid_argument("Wrong type string");
        }
    }
    return 1;
}


int main()
{
    try {
        std::cout << process_data(2);
        std::cout << process_data("Moii");
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() ;
    }
    return 0;
}
