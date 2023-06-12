#include <iostream>
#include <string>

//Takes a string as input and returns the reverse of that string.
std::string reverseString(std::string string){
    std::string reversedStr;
    for (int i = string.length() - 1; i >= 0; --i) {
        reversedStr.push_back(string[i]);
    }
    return reversedStr;
} 

int main()
{
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::cout << reverseString(input);

}
