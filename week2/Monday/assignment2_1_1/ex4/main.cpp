/*
Create a  program that that prints out the product of all elements in an array
*/
#include <iostream>
#include <array>

void product (std::array<int,10> arr) {
    int product = 1;

    for(auto i : arr){
        product = product * i;
    }
    std::cout << product;
}

int main()
{
    std::array<int,10> arr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    product(arr);
    return 0;
}
