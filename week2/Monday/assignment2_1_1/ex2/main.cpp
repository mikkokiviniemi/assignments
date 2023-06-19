/*
Add a function that receives an std::array and a number, and checks whether the number is in the array. 
The function should return a boolean value.
*/
#include <iostream>
#include <array>

bool check(std::array<int,10> arr, int num) {

    for (auto i : arr) {
        if (i == num){
            return true;
        }
    }
    
    return false;
    
}

int main()
{
    std::array<int, 10> arr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
     
    for (auto& i : arr) {
        std::cout << i << std::endl;
    }

    if (check(arr, 13)){
        std::cout << "Found" << std::endl;
    }
    return 0;
}
