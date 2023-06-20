/*
Optional Assignment 4

The towers of Hanoi

You have three towers and a set amount of disks  of different sizes which can slide onto any tower. 
The puzzle starts with all disks sorted in ascending order of size on one tower, with the smallest at the top. 
The objective is to move the entire stack to another tower by obeying the following rules:

Only one disk can be moved at a time.
Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on any empty rod.
No disk may be placed on top of a smaller disk
*/

#include <iostream>
#include <vector>
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const std::vector<int> dt) {

    for (auto it = dt.begin(); it != dt.end(); it++) {
        os << *it << " ";
    }
    
    return os << "\n";

}

void solver (int n,std::vector<int>& source,std::vector<int>& target,std::vector<int>& auxiliary){
    
    if (n > 0) {

        solver(n - 1, source, auxiliary, target);

        std::cout << "Source\n";
        std::cout << source;
        std::cout << "Auxiliary\n";
        std::cout << auxiliary;
        std::cout << "Target\n";
        std::cout << target;
        std::cout << "\n";

        target.push_back(*source.rbegin());

        source.pop_back();

        solver(n - 1, auxiliary, target, source);
    }
}

int main()
{
    std::vector<int>  tower1 = {3,2,1};
    std::vector<int>  tower2 = {};
    std::vector<int>  tower3 = {};

    solver(3,tower1,tower3,tower2);

    std::cout << "Source\n";
    std::cout << tower1;
    std::cout << "Auxiliary\n";
    std::cout << tower2;
    std::cout << "Target\n";
    std::cout << tower3;
    std::cout << "\n";

    return 0;
}
