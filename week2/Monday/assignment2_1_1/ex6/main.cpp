/*
Create a function that will output the smallest and largest number in the list.
*/
#include <iostream>
#include <list>
#include <algorithm>

void smallest_largest_num(std::list<int> list) {
    auto smallest = std::min_element(list.begin(), list.end());
    auto largest = std::max_element(list.begin(), list.end());

    std::cout << "Smallest: " << *smallest << "\n" << "Largest: " << *largest << "\n";
}


int main()
{
    std::list<int> list = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    smallest_largest_num(list);
    return 0;
}
