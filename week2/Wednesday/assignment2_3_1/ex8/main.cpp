/*
Exercise 8:

Create a vector of pairs with repeating first elements. After sorting, check if the pairs with equal first elements maintain their relative order.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::pair<std::string,int>> vec = {{"Mikko",5},{"Mikko",3},{"Mikko",4},{"Ceetu",23},{"Aatu",1},{"Beetu",1},{"Mikko",5},{"Mikko",3},{"Mikko",4},{"Ceetu",23},{"Aatu",1},{"Beetu",1}};

    std::sort(vec.begin(),vec.end());

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i].first << " " << vec[i].second << "\n";
    }
    return 0;
}
