/*
Exercise 1:

Create a header file that contains definition for enum class "status",
and add a success status, and couple of error statuses
Create a function that returns a status code at random
Create a program to call the function and handle the status 
using `switch`-statement
 

Exercise 2:

We are going to implement a simple state machine.  
A state machine is pretty simple concept
with a lot of complicated explanations, but let's keep it simple here.

We create a state machine to track a status of an order 
(e.g. from an online store).  The order should be tracked from ordered
to delivered.  (Make up the intermediate states)

Create a type to track the state for the machine.  Use `enum class`
Create a type for the orders (this is our state machine).  
Add a member functions to print the current status and to advance 
the status of the order.
Create a program that runs through the different states and prints 
and advances through them.
*/

#include <iostream>
#include "utils.h"

int main()
{
    //Ex1
    Status random_value = static_cast<Status>(random_between(0,3));
    switch (random_value)
    {
        case Status::success: {
            std::cout << "Success\n";
            break;
        }
        case Status::error_1: {
            std::cout << "Error 1\n";
            break;
        }
        case Status::error_2: {
            std::cout << "Error 2\n";
            break;
        }
        case Status::error_3: {
            std::cout << "Error 3\n";
            break;
        }
    }

    //Ex2
    Order new_order;
    std::cout << new_order.string_state() << "\n";
    new_order.next_state();
    std::cout << new_order.string_state() << "\n";
    new_order.next_state();
    std::cout << new_order.string_state() << "\n";
    new_order.next_state();
    std::cout << new_order.string_state() << "\n";
    new_order.next_state();
}
