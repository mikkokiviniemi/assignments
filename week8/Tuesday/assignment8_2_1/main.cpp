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
#include <type_traits>
#include "utils.h"

//EX1
template <typename T>
void exercise1(T&& arg) {
    if constexpr (std::is_lvalue_reference_v<T>) {
        std::cout << "lvalue reference\n";
    } else {
        std::cout << "rvalue reference\n";
    }
}
//EX2
template <bool console_call = true>
class EX2 {
    public:
        EX2(){
            if (console_call) {
                std::cout << "Default constructor called\n";
            }
            ++default_constructor;
        }
        EX2(EX2& other){
            if (console_call) {
                std::cout << "Copy constructor called\n";
            }
            ++copy_constructor;
        }
        EX2(EX2&& other){
            if (console_call) {
                std::cout << "Move constructor called\n";
            }
            ++move_constructor;
        }
        ~EX2(){
            if (console_call) {
                std::cout << "Destructor called\n";
            }
            ++destructor;
        }

        int default_constructor_count () {
            return default_constructor;
        }
        int copy_constructor_count () {
            return copy_constructor;
        }
        int move_constructor_count () {
            return move_constructor;
        }
        int destructor_count () {
            return destructor;
        }
        void all_counts() {
            std::cout << "default_constructor " << default_constructor << "\n";
            std::cout << "copy_constructor " << copy_constructor << "\n";
            std::cout << "move_constructor " << move_constructor << "\n";
            std::cout << "destructor " << destructor << "\n";
        }

    private:
        static int default_constructor;
        static int copy_constructor;
        static int move_constructor;
        static int destructor;

};

template <bool console_call>
int EX2<console_call>::default_constructor = 0;

template <bool console_call>
int EX2<console_call>::copy_constructor = 0;

template <bool console_call>
int EX2<console_call>::move_constructor = 0;

template <bool console_call>
int EX2<console_call>::destructor = 0;

//EX3
class EX3 {
public:
    EX3() : instances(0) {
        ++total_count;
    }
    EX3(const EX3&) = delete;

    // Implement the move constructor
    EX3(EX3&& other) noexcept : instances(other.instances) {
        other.instances = 0;
        ++total_count;
    }

    ~EX3() {
        --total_count;
    }
    //Return instances
    int get_instance_count() const {
        return instances;
    }
    //Return total_count
    static int get_total_count() {
        return total_count;
    }
private:
    static int total_count;
    int instances;
};

int EX3::total_count = 0;

int main()
{
    //EX1
    int value = 3;
    exercise1(value);
    exercise1(std::move(value));

    //EX2
    EX2<false> testing1;
    {
    EX2<false> testing2(testing1);
    EX2<false> testing3(std::move(testing1));
    }
    EX2<false>().all_counts();

    EX3 thing;
    std::cout << thing.get_total_count() << "\n";
    EX3 another(std::move(thing));
    std::cout << another.get_total_count() << "\n";


    return 0;
}
