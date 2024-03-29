/*
We are going to create a very simple and lightweight tagged union.  
A tagged union is
an union that has a tag to describe what kind of data it is holding.  This is an useful pattern,
and while the standard library has `std::variant` for this, it is sometimes useful to make a
quick version for yourself.  (Also, `std::variant` can be a bit intimidating at first, sometimes
your coworkers might prefer self-built option)

We will be improving on this during the week.

 

Exercise 1

Our tagged union will represent either a person, a robot or an alien.  The robots are
identified using an ID (integer value), persons are identified by the first letter of their
name (a char), and aliens are identified by the approximate wavelength of the light
their eyes emit. (a floating point value)

Create a header file where you declare the type and its member function prototypes,
requirements are
A way to check what type of object is stored
A way to access each of the different value types
A member function to set the stored value (overloading will be your friend here)
The type should be an union-like class (i.e. a class or struct with anonymous union member)
Pay attention to the const-ness of member functions and return values
Make sure you use references where needed!
 

Exercise 2

Implement the function prototypes
Think about error handling, how can the user of this class accidentally mess up?  Is there a case
where the use of a type is clearly an error from the user
Use assert() to make sure erronous use is caught.
*/

#include <iostream>
#include <typeinfo>
#include <cassert>
#include "utils.h"

int main()
{
    Entity new_entity;
    int id = 3;
    new_entity.set_id(id);
    assert(new_entity.get_type() == Type::Robot);
    std::cout << new_entity.info() << "\n";

    char initial = 'M';
    new_entity.set_id(initial);
    assert(new_entity.get_type() == Type::Person);
    std::cout << new_entity.info() << "\n";

    float eye_wave = 3.14;
    new_entity.set_id(eye_wave);
    assert(new_entity.get_type() == Type::Alien);
    std::cout << new_entity.info() << "\n";

    //This is not working :D
    Entity new_entity2;
    assert(new_entity2.get_type() != Type::Robot);
    std::cout << new_entity2.info() << "\n";


    return 0;
}
