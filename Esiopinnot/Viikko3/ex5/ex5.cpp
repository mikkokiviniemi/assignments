#include <iostream>
#include <cctype>

int getLastNumber(std::string str) {
    int lastNumber = 0;

    for (int i = str.length() - 1; i >= 0; i--) {
        if (isdigit(str[i])) {

            lastNumber = str[i] - '0';
            
            return lastNumber;
        }
    }

    return lastNumber;
}

int main()
{
    std::string number;

    std::cout << "Enter person number: ";
    std::cin >> number;

    if (getLastNumber(number) % 2 == 0) {
        std::cout<<"You are a woman.";
    }
    else{
        std::cout<<"You are a man.";
    }

    return 0;
}
