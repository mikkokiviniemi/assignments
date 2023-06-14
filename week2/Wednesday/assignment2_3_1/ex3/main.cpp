/*
Exercise 3:

Create a vector of floating-point numbers and sort it. Experiment with different sizes of vectors and number ranges.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<float> vec = {7.3f, 11.7f, 2.3f, 29.2f, 2.5f, 5.3f, 2.4f};
    std::sort(vec.begin(),vec.end());

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    return 0;
}
