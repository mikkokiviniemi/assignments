#include "source/utils.h"
#include <iostream>
#include <optional>
#include "source/expected.hpp"

/*
Exercise 1.

Create a class, and then a factory function (static member function) to create a class instance.
The function should return std::optional.
Create a way for the function to fail, and return a std::nullopt in case of failure.
Then demonstrate both cases.
*/
class Ex1 {
    public:
        Ex1(const std::string& value_input) : value(value_input) {}
        static std::optional<Ex1> create_instance(const std::string& value) {
            if (value.empty()) {
                return std::nullopt;
            }
            return Ex1(value);
        }
        void print_value () {
            std::cout << value;
        }
    private:
        std::string value;
};
/*
Exercise 2.
Again, create a class with a factory function.
The function should return std::expected.
Create a way for the function to fail, and test out and demonstrate both outcomes.

(This is very useful sometimes, since constructors cannot return values and 
sometimes we want to report errors some way even when exceptions are disabled)

If your standard library version is too old to include <expected>, you can use https://github.com/TartanLlama/expected 
instead (you'll just need the header in include/tl/expected.hpp)
*/
class Ex2 {
    public:
        Ex2(const std::string& value_input) : value(value_input) {}
        static tl::expected<Ex2, std::string> create_instance(const std::string& value) {
            if (value.empty()) {
                return tl::unexpected("empty");
            }
            return Ex2(value);
        }
        void print_value () {
            std::cout << value;
        }
    private:
        std::string value;
};

int main(int argc, char const *argv[])
{
    std::optional<Ex1> test= Ex1::create_instance("Success");
    std::optional<Ex1> test2= Ex1::create_instance("");

    if (test) {
        test->print_value();
    } else {
        std::cout << "Instance 1 creation failed!\n";
    }
    std::cout << "\n";
    if (test2) {
        test2->print_value();
    } else {
        std::cout << "Fail!\n";
    }
    tl::expected<Ex2, std::string> instance1 = Ex2::create_instance("Success");
    tl::expected<Ex2, std::string> instance2 = Ex2::create_instance("");

    if (instance1) {
        instance1->print_value();
    } else {
        std::cout << "Instance 1 creation failed: " << instance1.error() << "\n";
    }
    if (instance2) {
        instance2->print_value();
    } else {
        std::cout << "Instance 1 creation failed: " << instance2.error() << "\n";
    }

    return 0;
}

