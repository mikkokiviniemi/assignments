/*
You are in a buzzing startup company that is building a ordering system for a restaurant.

Exercise 1:
Set up your program and create the first set of data
To start, your menu ordering program should have a struct called Food. 
The members for the struct should contain the name, price and ingredients. 
Your program needs to be able to print out all of the attributes. 
Divide the program into multiple source and header files as needed.
Test your program by creating a food item and printing out its ingredients in the main.cpp file.

Use CMake to build your program.

Exercise 2:
Add a menu to the program.
Add a menu to the program. At this stage, you should be able to add foods into the menu and print out the menu for the customer.

Exercise 3:
The program needs to handle orders. Add a new feature where the customer can pick a food from the menu and add it to the order.
The order should also contain information of the total price.

Exercise 4:
In your main.cpp, create a loop that allows a customer to add as many items as they want to their order from the menu.
They should be able to view the menu and their current order at any time.


*/

#include <iostream>
#include <vector>
#include "food.h"
#include "utils.h"


int main()
{

    std::vector<Food> menu;


    //Adding burger to menu
    Food hamburger = {"Hamburger",5.99,{"Salad","Bun","Burger"}};
    menu.push_back(hamburger);
    Food fries = {"Fries",3.50,{"Potato"}};
    menu.push_back(fries);
    Food soda = {"Soda",2.00,{"Water","Sugar","Coloring"}};
    menu.push_back(soda);

    //Ordering
    std::vector<Food> order = ordering_function(menu);

    //Final order
    print_order(order);

    return 0;
}
