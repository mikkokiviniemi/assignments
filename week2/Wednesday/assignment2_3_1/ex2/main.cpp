/*
Exercise 2:

Use std::sort with std::greater<int>() to sort an array of integers in descending order.
*/

#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::array<int,7> arr = {7,11,2,29,3,5,23};
    std::sort(arr.begin(),arr.end(),std::greater<int>());

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
