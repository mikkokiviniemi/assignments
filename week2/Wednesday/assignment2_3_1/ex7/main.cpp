/*
Exercise 7:

Use std::partial_sort to find the top 5 elements from a vector of integers. The vector should have at least 20 elements.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = {7, 61, 2, 71, 31, 13, 43, 59, 17, 67, 5, 37, 23, 19, 47, 29, 11, 3, 53, 41};

    std::partial_sort(vec.begin(), vec.begin() + 5, vec.end(), std::greater<int>());

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Top 5\n";
    for (int i = 0; i < 5; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
