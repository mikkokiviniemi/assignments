/*
Create a vector<int> with 10 numbers in it. 
Use std::partition to separate the even and odd numbers. 
Print out the vector after partitioning.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

int main()
{
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    auto it = std::partition(vec.begin(), vec.end(), [](int i) {return i % 2 == 0;});

    std::copy(vec.begin(), it, std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::copy(it, vec.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
