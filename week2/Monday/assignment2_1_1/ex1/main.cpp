/*
Create an array with 10 random numbers in it. 
Your program should also be able to output the elements in the array.
*/

#include <iostream>
#include <array>

int main()
{
    std::array<int, 10> arr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    for (auto& i : arr) {
        std::cout << i << std::endl;
    }
    return 0;
}
