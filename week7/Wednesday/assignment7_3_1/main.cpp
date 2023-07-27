/*
Exercise 1.

Create a template class and overload its equality operator.

The overridden operator should `static_cast` its arguments to a type given as a template parameter and do the comparison using e.g. template argument's < operator.

 

Exercise 2.

Create a new type of your own choosing, and use CRTP to give it the equality comparison functionality from the result of exercise 1.  (e.g. have the new type have < operator, and use that to give the required functionality with the Exercise 1 class)

(Optional) Add other comparisons, (e.g. >, !=, >=, <=) as well with the exercise 1 class.

 

Exercise 3

Create another template class and give it a function to print out its type (e.g. by using typeid or some simple checker with type_traits, no need to handle everything).
Then inherit both this functionality and the functionality created in ex 1. to your type.
*/

#include <iostream> 
#include <type_traits>
#include "utils.h"

template <typename T>
struct EX1 {};

template <typename T>
struct EX3 {};

class EX2 : public EX1<EX2>, public EX3<EX2>{
public:
    EX2() noexcept = default;
    EX2(int value) noexcept : data(value) {}

    bool operator<(const EX2& other) const {
        return data < other.data;
    }

private:
    int data;
};

//EX2 + Optional 
template <typename T>
bool operator==(const EX1<T>& lhs,const EX1<T>& rhs) noexcept {
    return !(static_cast<const T&>(lhs) < static_cast<const T&>(rhs)) && !(static_cast<const T&>(rhs) < static_cast<const T&>(lhs));
};
template <typename T>
bool operator!=(const EX1<T>& lhs,const EX1<T>& rhs) noexcept {
    return !(!(static_cast<const T&>(lhs) < static_cast<const T&>(rhs)) && !(static_cast<const T&>(rhs) < static_cast<const T&>(lhs)));
};
template <typename T>
bool operator<=(const EX1<T>& lhs,const EX1<T>& rhs) noexcept {
    return (static_cast<const T&>(lhs) < static_cast<const T&>(rhs)) || (!(static_cast<const T&>(lhs) < static_cast<const T&>(rhs)) && !(static_cast<const T&>(rhs) < static_cast<const T&>(lhs)));
};
template <typename T>
bool operator>=(const EX1<T>& lhs,const EX1<T>& rhs) noexcept {
    return (static_cast<const T&>(rhs) < static_cast<const T&>(lhs)) || (!(static_cast<const T&>(lhs) < static_cast<const T&>(rhs)) && !(static_cast<const T&>(rhs) < static_cast<const T&>(lhs)));
};
template <typename T>
bool operator>(const EX1<T>& lhs,const EX1<T>& rhs) noexcept {
    return static_cast<const T&>(rhs) < static_cast<const T&>(lhs);
};

//EX3
template <typename T>
void print_type(const EX3<T>& value) {
    std::cout << "Type: " << typeid(value).name() << "\n";
}


int main()
{
    EX2 test1 {3};
    EX2 test2 {3};
    if(test1 >= test2) {
        std::cout << "Hurraa\n";
        print_type(test2);
    }
    
    return 0;
}
