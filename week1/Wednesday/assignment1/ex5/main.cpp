#include <iostream>

void func() {
    int variable = 7;
    
    //Prints 7
    std::cout << "Variable before if statement: " << variable << std::endl;


    if (true) {
        variable = 3;
    }
    
    //Prints 3
    std::cout << "Variable after if statement: " << variable << std::endl;

}


int main()
{
    
    func();


    return 0;
}
