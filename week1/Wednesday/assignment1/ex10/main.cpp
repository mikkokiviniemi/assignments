#include <iostream>

namespace thingy {
    int variable = 3;
}

int func () {

    int variable = 7;
    return variable;

}

int main()
{
    //Prints 7
    std::cout << func() << std::endl;
    //Prints 3
    std::cout << thingy::variable << std::endl;
    return 0;
}