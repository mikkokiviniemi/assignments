/*
Create a program that will ask the user for the size of a vector.
*/
#include <iostream>
#include <vector>

int main()
{
    int size;
    std::cout << "Size for the vector: ";
    std::cin >> size;

    std::vector<int> vec(size,7);

    for (int i : vec) {
        std::cout << i << " ";
    }

    

    return 0;
}
