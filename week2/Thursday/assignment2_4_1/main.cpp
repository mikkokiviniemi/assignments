/*
Create a new file and header for each new feature for the program.
lorem_ipsum.txt Use this file.
https://fi.wikipedia.org/wiki/Lorem_ipsum Lorem ipsum is a traditional way of filling dummy text if there is no actual content yet.

Exercise 1:
Write a simple C++ program that takes a file name as a command-line argument and prints the contents of the file to the console.
Make sure to handle errors, like if the file doesn't exist.
Use CMake to build your program.

Exercise 2:
Add a new feature to your program.
Add a command-line option "-l" or "--lines" to activate this feature.
If this option is provided, instead of printing the file contents, your program prints the number of lines in the file.
You can use the "cxxopts" library again.

Exercise 3:
Add a word counter. Extend your program to count the number of words in the file.
Add a command-line option "-w" or "--words".

Exercise 4:
Add a character counter.
Add a command-line option "-c" or "--chars" to activate this feature.

Exercise 5:
Add a function that can calculate the size of the text files in a directory.
*/

#include <iostream>
#include "utils.h"

//Example build/lorem_ipsum lorem_ipsum2.txt -l to get lines
//Commands: -l -w -c -s (Lines,words,characters,size)
//Unfortunately one function dream
int main(int argc, char const *argv[])
{
    std::string file = argv[1];
    std::string option = argv[2];
    return file_manager(file,option);
}
