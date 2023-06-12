/*
Write a C++ program that capitalizes the first letter of the string and sets the rest as lowercase letters.
Use the following main function and write a function that passes the assertions.
*/

#include <iostream>
#include <cassert>


std::string capitalize_string(std::string input) {
    std::string result;
    bool upper = true;
    
    for (int i = 0; i < input.length(); i++) {
        char current = input[i];

        if (std::isalpha(current)) {
            if (upper) {
                result.push_back(std::toupper(current));
                upper = false;
            } else {
                result.push_back(std::tolower(current));
            }
        } else {
            result.push_back(current);
            upper = true;
        }
    }
    
    return result;
}

int main() {
    assert("The String Challenge" ==
    capitalize_string("the string challenge"));
    std::cout << "Test 1 passed" << std::endl;
    assert("This Is An Example, Should Work!" ==
    capitalize_string("THIS IS an ExamplE, should wORk!"));
    std::cout << "Test 2 passed" << std::endl;
}
