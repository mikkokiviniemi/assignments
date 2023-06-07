#include <iostream>

int main()
{
    
    int x = 7;
    //Prints 7
    std::cout << "Outside before block"<< x << std::endl;


    {
        int x = 3;
        //Prints 3
        std::cout << "Inside block " << x << std::endl;
    }

    //Prints 7
    std::cout << "Outside after block " << x << std::endl;
    


    return 0;
}
