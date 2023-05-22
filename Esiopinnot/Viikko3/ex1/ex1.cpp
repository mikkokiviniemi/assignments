#include <iostream>

int main(){

    std::cout << "Distance (km): ";
    std::string distance;
    std::getline(std::cin, distance);

    std::cout << "Consumption (l/100k): ";
    std::string consumption;
    std::getline(std::cin, consumption);

    std::cout << "Fuel €/l: ";
    std::string cost;
    std::getline(std::cin, cost);

    float d = std::stof(distance);
    float c = std::stof(consumption);
    float co = std::stof(cost);


    std::cout << "Cost: "<< d*(c/100)* co <<" €"<< std::endl;



    return 0;
}