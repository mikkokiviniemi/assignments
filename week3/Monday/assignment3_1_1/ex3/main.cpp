/*
Create a program that will print out a list of names. 
The user can choose a person in the list by inputting the user index and their name gets printed out. 
If the user tries to choose a user that is outside of the index, throw an appropriate exception. 
*/
#include <iostream>
#include <vector>
#include <exception>

std::string get_name (std::vector<std::string> names, int index) {
    if (index > (names.size() - 1)) {
        throw std::out_of_range("Index out of range");
    }
    return names[index];
}

int main()
{
    std::vector<std::string> names = {"Mikko","Aatu","Beetu","Ceetu","Deetu"};
    try {
        std::cout << get_name(names,5);
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    return 0;
}
