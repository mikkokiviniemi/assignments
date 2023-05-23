#include <iostream>

/*

Write a program that calculates the first 10 numbers of a Fibonacci sequenceLinks to an external site.

*/

void fibonacci(int number){

    int f1 = 1;
    int f2 = 0;

    std::cout << "0\n1" <<std::endl;

    for(int i = 0;i < number - 1; i++){
        
        int fibonacci = f2 + f1;

        f2 = f1;
        f1 = fibonacci;
    
        std::cout<< fibonacci <<std::endl;

    }

}

int main()
{

    fibonacci(10);

    return 0;
}
