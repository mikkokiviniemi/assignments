/*
Exercise 5:
Create a vector of pairs where each pair contains a string and an integer (like a name and an age). Sort the vector based on the integer.
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool comp_int(const std::pair<std::string, int>& pair1, const std::pair<std::string, int>& pair2) {
    return pair1.second < pair2.second;
}


int main()
{
    std::vector<std::pair<std::string,int>> vec = {{"Mikko",5},{"Mikko",3},{"Mikko",4},{"Ceetu",23},{"Aatu",1},{"Beetu",1}};

    std::stable_sort(vec.begin(),vec.end(),comp_int);

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i].first << " " << vec[i].second << "\n";
    }
    return 0;
}