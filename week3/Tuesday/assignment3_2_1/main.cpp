/*
Travelling Salesperson Problem.

You have been assigned the task to plan the route of a container ship. The ship starts in Panama and there are four other ports. New York, Amsterdam, Helsinki and Durban. The ship can visit each port only once. The goal is to minimize the carbon emissions, which means that a shorter route is better than a longer one.

Exericse 1:

Create a recursive function that will print out all the possible routes that start from Panama.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void routes(std::vector<std::pair<std::string,int>> cities,int left, int right, std::string wanted) {
    if (cities.at(left).first == cities.at(right).first) {
        if(cities.at(0).first == wanted) {
            for (auto& city : cities) {
                std::cout << city.first << " ";
            }
            std::cout << "\n";
        }
    }
    else {
        for (int i = left; i <= right; i++) {
            std::swap(cities[left],cities[i]);
            routes(cities,left + 1,right,wanted);
            std::swap(cities[left],cities[i]);
        }
    }
}


int main()
{
    std::vector<std::pair<std::string,int>> cities = {{"Panama",0},{"New York",4460},{"Amsterdam",8440},{"Helsinki",9250},{"Durban",1290}};
    routes(cities,0,cities.size()-1,"Panama");

    return 0;
}
