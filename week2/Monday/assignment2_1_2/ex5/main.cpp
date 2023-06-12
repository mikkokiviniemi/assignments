/*
ex5: Create a new program that will create a vector of random size, filled with random numbers between 1 and 100.
ex6: Add a function that will output the smallest and largest number in the array.
ex7: Add a function that will remove all instances of a value from the vector and inform if the value was found and removed.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void smallest_largest_num(std::vector<int> vec) {
    auto smallest = std::min_element(vec.begin(), vec.end());
    auto largest = std::max_element(vec.begin(), vec.end());
    std::cout << "Smallest: " << *smallest << "\n" << "Largest: " << *largest << "\n";
}

void remove_instances (std::vector<int>& vec, int value) {

    bool found = false;

    auto remove = [&](int n) {if(n==value){found = true;} return n == value; };
    vec.erase(std::remove_if(vec.begin(), vec.end(), remove), vec.end());

    if(found){
        std::cout << "Value was found and removed\n";
    }
}
void print_vec (std::vector<int> vec) {
    std::cout << "Vector: ";
    for(auto i : vec){
        std::cout << i <<" ";
    }
    std::cout << "\n";
}


int main()
{
    int size = (rand()%10);
    std::vector<int> vec;
    vec.reserve(size);

    std::cout << "Size: " << vec.size() <<"\n";

    for(int i = 0; i != size; i++){
        vec.push_back((rand()%100));
    }
    print_vec(vec);

    smallest_largest_num(vec);

    remove_instances(vec,15);

    print_vec(vec);

    return 0;
}
