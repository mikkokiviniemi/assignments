/*
Create a program that has a function that returns the sum of all the elements in an array. 
The vector will be filled automatically with different numbers
*/
#include <iostream>
#include <array>


void sum (std::array<int,10> arr) {
    int sum = 0;

    for(auto i : arr){
        sum = sum + i;
    }
    std::cout << sum;
}

int main()
{
    std::array<int,10> arr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    sum(arr);
    return 0;
}
