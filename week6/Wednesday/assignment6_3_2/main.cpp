/*
Exercise 1

Returning to the earlier text file class, use encapsulation to hide the implementation details.

Split the implementation and declarations into source and header file(s).  Pay attention to the
headers you need to include in each.

Exercise 2

A friend function is a function that has access to the internals (private members)
of a type.  You can declare such inside a class using friend keyword.

Make the functions to add and substract work with the encapsulated version of
the positive integer class.

Exercise 3

Do the same for the Object class (6.1.2) we created earlier.
*/

#include <iostream>
#include "utils.h"

int main()
{   
    Positive_int first(3);
    Positive_int second = 7;
    Positive_int sum = first + second;
    sum.print_value();
    sum = sum-second;
    sum.print_value();
    sum = sum - 2;
    sum.print_value();

    Positive_int sum2 = add(first,second);
    std::cout << "Add: ";
    sum2.print_value();
    std::cout << "Subs: ";
    sum2 = sub(second,first);
    sum2.print_value();

    try {
        Text_file_reader readeri("./data/test.txt");
        std::string line;
        line = readeri.read_line();
        while (!line.empty()) {
            std::cout << line << "\n";
            line = readeri.read_line();
        }

    } catch (const std::exception& e){
        std::cout << e.what();
    }
    return 0;
}
