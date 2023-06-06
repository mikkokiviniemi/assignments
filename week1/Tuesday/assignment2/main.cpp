#include <iostream>
#include <string>
#include <cctype>

//Checks if contains at least eight characters
bool contains8Letters(std::string password) {
    if (password.size() >= 8) {
        return true;
    }
    return false;
}

//Checks if contains uppercase letter
bool containsUppercase(std::string password) {
    for (char c : password) {
        if (std::isupper(c)) {
            return true;
        }
    }
    return false;
}

//Checks if contains lowercase letter
bool containsLowercase(std::string password) {
    for (char c : password) {
        if (std::islower(c)) {
            return true;
        }
    }
    return false;
}

//Checks if contains digit.
bool containsDigit(std::string password) {
    for (char c : password) {
        if (std::isdigit(c)) {
            return true;
        }
    }
    return false;
}

//Checks if contains special character.
bool containsSpecial(std::string password) {
    for (char c : password) {
        if (!std::isalnum(c)) {
            return true;
        }
    }
    return false;
}

//Checks if password is weak or strong.
void passwordCheck (std::string password){
    if (contains8Letters(password) && containsUppercase(password) && containsLowercase(password) && containsDigit(password) && containsSpecial(password)){
        std::cout << "Strong password" << std::endl;
    }else{
        std::cout << "Weak password" << std::endl;
    }
}

int main() {
    std::string input;
    std::cout << "Enter password: ";
    std::getline(std::cin, input);
    
    passwordCheck(input);
    
    return 0;
}
