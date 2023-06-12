/*
Write a C++ program that simulates a simple game.
Implement a function called play_game() that takes a number as input and checks if it is within a certain range.
Use assert statements to check if the number is within the range of 1 to 100 (inclusive).
If the assertion fails, display an error message indicating that the number is out of range.
Compile the program both with and without the NDEBUG macro defined and observe the behaviour when the assertion fails in each case.
*/
#include <cassert>
#include <iostream>
#define NDEBUG;


void play_game(float num1, float num2) {
    assert((num1 < 100 || num2 < 100 || num1 > 0 || num2 > 0) && "Fail");

    if(num1 - num2 < 5){
        std::cout << "Hienoo";
    } else {
        std::cout << "Eipä osunu";
    }
}

int main()
{
    play_game(7,-3);
    return 0;
}
