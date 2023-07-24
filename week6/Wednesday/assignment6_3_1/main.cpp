/*
Exercise 1

Create a class that can only be instantiated by static member functions.  (i.e. a class
that has a static member function that returns an object of the type of the class itself)

Exercise 2

Create class declarations for animal, bird, wings, eyes, parrot and dog.  Use inheritance to
show relations between the classes.

Exercise 3

Play around the classes of ex2. a bit.

Create a constructor and destructor for each of the classes, where you print out what happens
e.g. ("created an animal", "destroyed eyes", yes, that sounds weird, feel free to write something
else as long as you know what is happening.)  Try out what happens when you instantiate different
classes.

Create function with the same name inside base and derived classes.  Try out how the calls work
from different clases.

It was/is a common job interview question for object-oriented programming to be able to explain
how these work, so just get a general feel for it.  We'll get more into it when we talk about
polymorphism.
*/

#include <iostream>
#include "utils.h"

class Some_class
{
    public:
        static Some_class create(){
            return Some_class ();
        }
        void hello() {
            std::cout << "Hello\n";
        }
    private:
        Some_class() {}

};

int main()
{
    Some_class olio = Some_class::create();
    olio.hello();
    Parrot new_parrot(3.1,1.5,4,"Red");
    new_parrot.info();
    std::cout<<"Wing info\n";
    new_parrot.wing.info();
    return 0;
}
