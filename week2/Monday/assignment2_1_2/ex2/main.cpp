/*
Create two std::vector<int> and fill them with random amount of random numbers. 
Use std::set_intersection to find common elements between them.
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> vec1 = {2,3,5,7,9,12,6,7};
    std::vector<int> vec2 = {2,4,6,8,10,12,14};
    std::set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(),std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
