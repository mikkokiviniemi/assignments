/*
Exercise 1
Write a recursive function that takes a string as input and returns the string reversed.
*/

#include <iostream>

std::string reversed (std::string input) {


    if (input.empty()) {
        return "";
    }

    std::string output;
    output.push_back(*input.rbegin());
    input.pop_back();

    return output + reversed(input);
}

int main()
{
    std::cout << reversed("Moikka");
    return 0;
}
