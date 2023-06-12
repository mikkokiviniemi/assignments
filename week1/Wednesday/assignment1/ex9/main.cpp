#include <iostream>

void func() {
    static int variable = 7;

    variable++;

    std::cout << "Variable: " << variable << std::endl;
}

void func2() {
    int variable = 7;

    variable++;

    std::cout << "Variable2: " << variable << std::endl;
}

int main() {
    
    //Prints 8,9,10
    for(int i = 0; i < 3;i++){
        func();
    }
    //Prints 8,8,8
    for(int i = 0; i < 3;i++){
        func2();
    }
    return 0;
}