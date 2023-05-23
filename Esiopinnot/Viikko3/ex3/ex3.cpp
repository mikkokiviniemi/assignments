#include <iostream>

int main() {
    float membershipPrice, visitPrice;
    int visitsPerYear;

    std::cout << "Enter the price of the membership card: ";
    std::cin >> membershipPrice;

    std::cout << "Enter the price of a single visit: ";
    std::cin >> visitPrice;

    std::cout << "Enter the number of visits per year: ";
    std::cin >> visitsPerYear;

    double visitCost = visitPrice * visitsPerYear;

    if (membershipPrice <= visitCost) {
        std::cout << "Buy a membership card" << std::endl;
        std::cout << "Cost with membership: " << membershipPrice << std::endl;
        std::cout << "Cost with individual visits: " << visitCost << std::endl;
    } else {
        std::cout << "Buy individual visits" << std::endl;
        std::cout << "Cost with membership: " << membershipPrice << std::endl;
        std::cout << "Cost with individual visits: " << visitCost << std::endl;
    }

    return 0;
}
