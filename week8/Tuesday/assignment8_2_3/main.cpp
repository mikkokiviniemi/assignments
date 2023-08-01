/*
Exercise 1

Create a function that takes universal reference as is argument (template T&&) to print out
whether or not its argument is an lvalue reference or an rvalue reference

Make a program and call the function to demonstrate both cases.

Exercise 2

Create a class with following properties:

Has template parameter that enables or disables console output
Counts number of calls to
Default constructor
Copy constructor
Move constructor
Destructor
If enabed, prints out when its constructor / destructor is called
This kind of class will be your friend while debugging.

Exercise 3

Earlier, we created a class that counted the number of instances created.
Delete the classes copy constructor and implement the move constructor.

(This kind of class is extremely useful when wrapping libraries.
You can avoid user having to deal with library initialisation / 
destruction by doing the init on the first created instance of a type and then cleaning up when the last goes poof.
If you have tried libraries such as SDL, GLFW, or other low-level windowing libraries, this is the way to go.)
*/
#include <iostream>
#include <vector>
#include "utils.h"


int main() {

    Grid_2D<int> grid1(3, 3);
    int count = 1;
    for (std::size_t row = 0; row < 3; ++row) {
        for (std::size_t col = 0; col < 3; ++col) {
            grid1(row, col) = count++;
        }
    }

    Grid_2D<int> grid2 = grid1;

    Grid_2D<int> grid3(2, 2);
    grid3 = grid1;

    Grid_2D<int> grid4 = std::move(grid1);

    Grid_2D<int> grid5(1, 1);
    grid5 = std::move(grid2);

    std::cout << "Grid1: \n" << grid1 << "\n";
    std::cout << "Grid2: \n" << grid2 << "\n";
    std::cout << "Grid3: \n" << grid3 << "\n";
    std::cout << "Grid4: \n" << grid4 << "\n";
    std::cout << "Grid5: \n" << grid5 << "\n";

    return 0;
}
