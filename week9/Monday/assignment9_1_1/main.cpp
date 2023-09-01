#include "source/utils.h"
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
Exercise 1

Create a table of functions (std::vector is fine).  
Then read user input from command line, standard input or a file (your choice), 
where user determines which function in the array to call.

 

Exercise 2

Use std::unordered_map<char, std::function<...>> to map a character to a function.
Fill the map with operations '+', '-', '*' and '/'.
Then read a line such as

1 + 1

and parse the line to call the right function with the right parameters.
(You could e.g. use spaces as separators for left value, operator, right value, there are plenty of ways to parse it)
This is basically a improved way to handle the usual "make a calculator" exercise.
Try adding your own operators to do other stuff as well.
*/


int add(int lhs,int rhs) {
    return lhs + rhs;
}
int substract(int lhs,int rhs) {
    return lhs - rhs;
}
int multiply(int lhs,int rhs) {
    return lhs * rhs;
}
int divide(int lhs,int rhs) {
    if(rhs == 0) {
        throw std::runtime_error("Cant divide with zero!");
    }
    return lhs / rhs;
}

int main(int argc, char const *argv[])
{
    //EX1
    std::vector<std::function<void()>> ex1;
    ex1.push_back(print_moi);
    ex1.push_back(print_hello);
    ex1.push_back(print_hello_world);

    std::string input;
    std::cout << "Which function (1-3) ";
    std::getline(std::cin,input);
    ex1[std::stoi(input)-1]();
    
    //EX2
    std::cout << "EX2:\n";
    std::unordered_map<char,std::function<int(int,int)>> operations;
    operations['+'] = add;
    operations['-'] = substract;
    operations['*'] = multiply;
    operations['/'] = divide;

    std::string input2;
    std::cout << "";
    std::getline(std::cin,input2);

    if (input2.length() == 5) {
        std::cout << operations[input2[2]](input2[0]- '0',input2[4]- '0') << "\n";
    } else {
        throw std::runtime_error("Example: 3+3");
    }

    return 0;
}

