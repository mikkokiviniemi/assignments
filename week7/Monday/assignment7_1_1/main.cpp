/*
Exercise 1
Create a constexpr function that checks if two types the same.  (Hint:  You do not need
any library functionality (i.e. headers) for this)

Exercise 2
Create a constexpr function that checks if a type can be decayed further.
*/

#include <iostream>
#include <type_traits>

//Ex 1 function to check if two types are the same.
template <typename T, typename U>
constexpr bool same_type(T, U) {
    return false;
}
template <typename T>
constexpr bool same_type(T, T) {
    return true;
}

//Ex 2 function to check if a type can be decayed further
template <typename T>
constexpr bool can_be_decayed() {
    return !std::is_same_v<T, std::decay_t<T>>;
}


int main() {
    const int a = 3;
    double b = 3.3;
    char c = 'A';

    std::cout << std::boolalpha;
    //Ex 1
    std::cout << "Ex 1:\n";
    std::cout <<  same_type(a, a) << "\n"; //True
    std::cout <<  same_type(a, b) << "\n"; //False
    std::cout <<  same_type(c, c) << "\n"; //True
    std::cout <<  same_type(c, a) << "\n"; //False

    //Ex 2
    std::cout << can_be_decayed<int>() << "\n";         // Output: 0 (false)
    std::cout << can_be_decayed<const int> << "\n";       // Output: 1 (true)


    return 0;
}

