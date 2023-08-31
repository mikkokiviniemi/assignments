#include "source/utils.h"
#include <iostream>
#include <bitset>
#include <string>

/*
Exercise 1
Create a function to check if nth bit is set in an value.
*/
bool ex1(int value, int n) {
    int helper = 1 << n+1;
    return (value & helper) != 0;
}
/*
Exercise 2
Create a template function to swap byte order of the value it is given, regardless of its size.
It should work at least for unsigned integer types.
Use static_assert with the type_traits header to make sure only integral types are accepted.
*/
template <typename T>
T ex2(T value) {
    T result = 0;
    for (size_t i = 0; i < sizeof(T); ++i) {
        result |= static_cast<T>((value >> (i * 8)) & 0xFF) << ((sizeof(T) - 1 - i) * 8);
    }
    return result;
}
/*
Exercise 3
Create a set of flags for 8 different options.
You may make the options up yourself or use the following
*/
constexpr static uint8_t IS_FUZZY            = 0b1;
constexpr static uint8_t IS_LARGE            = 0b10;
constexpr static uint8_t HAS_GOOGLY_EYES     = 0b100;
constexpr static uint8_t IS_CUTE             = 0b1000;
constexpr static uint8_t HAS_TEETH           = 0b10000;
constexpr static uint8_t IS_ABOUT_TO_EAT_YOU = 0b100000;
constexpr static uint8_t IS_FRIENDLY         = 0b1000000;
constexpr static uint8_t IS_SPIDER           = 0b10000000;

/*
Create a function to print out set options given a set of flags in human-readable form.
You can use a type of your own or uint8_t directly (it is smart to create at least a type alias though)
*/
void ex3 (uint8_t option) {
    if (option & IS_FUZZY) {
        std::cout << "IS_FUZZY \n";
    }
    if (option & IS_LARGE) {
        std::cout << "IS_LARGE \n";
    }
    if (option & HAS_GOOGLY_EYES) {
        std::cout << "HAS_GOOGLY_EYES \n";
    }
    if (option & IS_CUTE) {
        std::cout << "IS_CUTE \n";
    }
    if (option & HAS_TEETH) {
        std::cout << "HAS_TEETH \n";
    }
    if (option & IS_ABOUT_TO_EAT_YOU) {
        std::cout << "IS_ABOUT_TO_EAT_YOU \n";
    }
    if (option & IS_FRIENDLY) {
        std::cout << "IS_FRIENDLY \n";
    }
    if (option & IS_SPIDER) {
        std::cout << "IS_SPIDER \n";
    }
}
/*
Exercise 4
Create another function to check for certain combinations of the set flags, and print out something special for those.
There are 256 options in the 8-bit bitset, so don't worry about covering every case, just a couple of them will do.
*/
void ex4(uint8_t option) {
    if ((option & IS_FUZZY) && (option & IS_LARGE) && (option & HAS_TEETH) && (option & IS_ABOUT_TO_EAT_YOU) ){
        std::cout << "I am bear!\n";
    }
    if ((option & IS_FUZZY) && (option & IS_FRIENDLY) && (option & HAS_TEETH) && (option & IS_CUTE)) {
        std::cout << "I am dog!\n";
    }
}

/*
Exercise 5
Bitmasking is a technique to mark locations of certain values.
We now want to create a bitmask from a string input.

Create a program, where you let user input a string (either read it from command line or use I/O functions, 
it doesn't matter as long as the string is given by the end-user)  You may assign a max size for the string.
Go through bytes in the string, and for each character of the string, mark the bit set if the character represents a comma.

Print out the resulting bits.
e.g. ( "123,43,55" would produce a value of 0b1001000, as fourth and seventh character is a comma)
*/
void ex5() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::bitset<8> bitmask;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == ',') {
            bitmask.set(input.size() - 1 - i);
        }
    }
    std::cout << "Resulting bitmask: " << bitmask << "\n";
}


int main()
{
    int thing = 0b0101;
    std::cout << ex1(thing,1) << "\n";
    uint16_t value2 = 0x1234;
    std::cout << std::hex << ex2(value2) << "\n";

    ex3(0b01001001);
    ex4(0b00110011);
    ex4(0b01011001);
    ex5();

    return 0;
}

