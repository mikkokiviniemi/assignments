/*
Exercise 1.

Take a look at C function printf and especially its format specifiers (https://alvinalexander.com/programming/printf-format-cheat-sheet/Links to an external site.)

Create a template function with a signature that is something like

template <typename Ts...>
void safe_printf(const std::string& fmt, Ts args...);

that checks that the arguments given to the printf are of correct type.

(printf is unfortunately still quite common in some C++ circles that refuse to leave the 90's behind.
There are multiple reasons to prefer cout (or std::print from C++23 forward), 
but this safe_printf used to be something a lot of people had to write to fix the bugs caused by incorrect printfs in the codebase.)
*/

#include <iostream>
#include "utils.h"

void safe_printf(const std::string& fmt) {
    std::cout << fmt;
}

template <typename T, typename... Ts>
void safe_printf(const std::string& fmt, T arg, Ts... args) {
    for (size_t i = 0; i < fmt.length(); i++) {
        if (fmt[i] == '%') {
            if (fmt[i+1] == 'i'){
                if (std::is_integral_v<T>) {
                    std::cout << arg;
                }
                else {
                    throw std::runtime_error("WARNINGS");
                }
            } else if (fmt[i+1] == 'f'){
                if (std::is_floating_point_v<T>) {
                    std::cout << arg;
                }
                else {
                    throw std::runtime_error("WARNINGS");
                }
            } else if (fmt[i+1] == 'd'){
                if (std::is_same_v<T, double>) {
                    std::cout << arg;
                }
                else {
                    throw std::runtime_error("WARNINGS");
                }
            } else if (fmt[i+1] == 'c'){
                if (std::is_same_v<T, char>) {
                    std::cout << arg;
                }
                else {
                    throw std::runtime_error("WARNINGS");
                }
            } else if (fmt[i+1] == 's'){
                std::cout << arg;
            } else{
                throw std::runtime_error("WARNINGS");
            }
            safe_printf(fmt.substr(i + 2),args...);
            return;
        } else {
            std::cout << fmt[i];
        }
        
    }
}
/*
Exercise 2.

We can use either static_assert of requires (c++20) to force a certain number of parameters for a variadic function.  
Create a class where the constructor takes any number of arguments and store that number in class template parameters 
or a constexpr static class member (or you can save the parameter pack itself if you want, but that is tricky, so consider it completely optional brain-teaser).

Create function to return the number of arguments the constructor was called with
Create an another function that requires, at compile-time, the exact number of arguments the constructor was called with
*/

template <typename... Args>
class Ex2 {
public:
    Ex2(Args... args) : number_of_args(sizeof...(args)) {}

    constexpr int get_number_of_args() const {
        return number_of_args;
    }

private:
    const int number_of_args;
};

template <typename... Args>
constexpr int get_number_of_args(Args...) {
    return sizeof...(Args);
}

int main()
{
    safe_printf("Moi %i Moi %d %s \n",123 ,3.12, "Moikka");
    Ex2<int,int,char> test(1,1,'c');
    std::cout << test.get_number_of_args() << "\n";
    return 0;
}
