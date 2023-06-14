/*
Exercise 1:
Write a program that sorts an array of integers in ascending order using std::sort
*/

#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::array<int,7> arr = {7,11,2,29,3,5,23};
    std::sort(arr.begin(),arr.end());

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
