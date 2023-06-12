/*
Create a std::list<int> with 10 elements. 
Use std::adjacent_find to find the first two adjacent elements that are equal. 
If no such elements exist, print a suitable message.
*/

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> vec = {1,3,5,7,13,13,17};
 
    auto i = std::adjacent_find(vec.begin(), vec.end());

    if (i == vec.end()) {
        std::cout << "No such elements exist";
    } else {
        std::cout << *i;
    }

    

    return 0;
}
