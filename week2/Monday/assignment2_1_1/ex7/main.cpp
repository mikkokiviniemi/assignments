/*
Create a function that will remove all instances of a value from the vector and inform if the value was found and removed.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void remove_instances (std::vector<int>& vec, int value) {

    bool found = false;

    auto remove = [&](int n) {if(n==value){found = true;} return n == value; };
    vec.erase(std::remove_if(vec.begin(), vec.end(), remove), vec.end());

    if(found){
        std::cout << "Value was found and removed\n";
    }

}

int main()
{
    std::vector<int> vec = {2, 3, 5, 7, 1, 1, 1, 1, 23, 29};

    remove_instances(vec,1);

    for (int i : vec) {
        std::cout << i << " ";
    }

    return 0;
}
