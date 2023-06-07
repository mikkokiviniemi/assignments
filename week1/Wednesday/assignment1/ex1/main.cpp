#include <iostream>

void func (){
    int i = 7;
    std::cout << i << std::endl;
}


int main()
{
    func();
    //std::cout << i << std::endl;
    //identifier "i" is undefined
    return 0;
}
