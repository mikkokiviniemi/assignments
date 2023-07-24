/*
Exercise 1

Create a type for positive integers with following requirements

Default-initialises to 0
Initialising with a negative number reports an error to the user and cleans up correctly (printing is not a valid way to report errors to the user)
Can be copied (e.g. a = b assignment works, where a and b are instances of the type)
Has a member function to print the contents
 

Exercise 2

Create functions to add and substract our ex1. positive integers from each other.  The integers should saturate
at 0 and the maximum value (so they do not overflow, e.g. 42 - 51 = 0)

(optional) Add overloads to your add and substract functions so they work with normal integer values too.

 

Exercise 3

Create a class that counts how many instances of it exist.  Do not use global variables.  Create a function to print the count.
*/

#include <iostream>
#include "utils.h"

int Instance::instance_count = 0;

int main()
{
    Positive_int default_value;
    //Prints 0
    default_value.print_value();
    Positive_int with_number(25);
    //Prints 25
    with_number.print_value();
    //Prints error message
    try {
        Positive_int with_error(-12);
    }
    catch (const std::exception& e){
        std::cout << e.what() << "\n";
    }
    Positive_int with_another(with_number);
    //Prints 25
    with_another.print_value();
    
    Positive_int kaksseiska = 27;
    //Prints 25
    kaksseiska.print_value();

    Positive_int sum = kaksseiska + with_number;
    sum.print_value();
    Positive_int sub = kaksseiska - with_number;
    sub.print_value();


    std::cout << "Ex3\n";
    Instance new_instance;
    Instance new_instance2;
    std::cout << Instance::get_count() << "\n";
    new_instance2.~Instance();
    std::cout << Instance::get_count() << "\n";
    return 0;
}
