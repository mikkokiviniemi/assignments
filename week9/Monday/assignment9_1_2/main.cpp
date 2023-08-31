#include "source/utils.h"
#include <iostream>
/*
This is more about treating functions as template arguments.
It can be useful every now and then to pass function directly as a template argument.
You won't need <functional> for these.

Exercise 1a

Create a template class, that takes an arbitrary function as its template parameter.
Use the constructor to deduce the template types so user doesn't have to provide them.

Exercise 1b

Save the information about function return type (via using) and 
function arity (number of arguments) in the class.
(This requires you to template the return type and function parameters separately)


Exercise 1c
Create a function to test your class with.
Use decltype to printing out infomation contained without manually entering the template parameters.
*/

#include <iostream>
#include <functional>

template <typename Func>
class Exercise1A {
    public:
        Exercise1A(Func function) : function(function) {}

        void execute() {
            function();
        }
    private:
        Func function;
};

template <typename R, typename... Args>
class Exercise1B
{
    public:
        Exercise1B(R(*)(Args... args)) {
            arity = sizeof...(Args);
        }
        using return_type = R;
        int arity;
};

int sum(int lhs,int rhs){
    return lhs+rhs;
}

int main() {
    
    Exercise1B thing(sum);

    std::cout 
    << "Return type: " << typeid(decltype(thing)::return_type).name() << "\n"
    << "Arity: "<< thing.arity << "\n";

    return 0;
}

