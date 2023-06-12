/*
Create a vector with 10 random elements in it. 
Rotate elements to the right by 3 positions with std::rotate.
*/

#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<int> vec = {2,3,5,7,13,17,19};

    std::rotate(vec.rbegin(), vec.rbegin() + 3, vec.rend());

    for(auto i : vec){
        std::cout << i << " ";
    }
    
    return 0;
}
