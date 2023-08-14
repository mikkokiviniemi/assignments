#include "source/utils.h"
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
/*
Exercise 1

From the main thread, create two threads, one of which prints "Hello, " and the other "world!\n".
Run your program a couple of times.
*/

void print_hello() {
    std::cout << "Hello, ";
}
void print_world() {
    std::cout << "world!\n";
}
/*
Exercise 2

Create a function that adds an integer n times to a static global variable.  e.g. void add(int increment int times);  Use a loop to do the increments.
Create 100 threads from the main() function to call the add-function.
Compare the result to straight-up calculation.
*/

static int global_int = 0;
void add(int increment,int times) {
    for (int i = 0; i < times; ++i) {
        global_int += increment;
    }
}
/*
Exercise 3

Repeat exercise 2, but use mutexes to lock the summation so only one thread can do the increment at a time (check out std::lock_guard as well)
*/

static int global_int_2 = 0;
std::mutex ex3_mutex;

void add_2(int increment,int times) {
    for (int i = 0; i < times; ++i) {
        std::lock_guard<std::mutex> lock(ex3_mutex);
        global_int_2 += increment;
    }
}
/*
Exercise 4

Repeat exercise 2, but use std::atomic type as your global sum type.
*/

std::atomic<int> global_int_3(0);
void add_3(int increment,int times) {
    for (int i = 0; i < times; ++i) {
        global_int_3 += increment;
    }
}

int main(int argc, char const *argv[])
{
    //This sometimes prints it "world!\n Hello, "
    std::thread thread1(print_hello);
    std::thread thread2(print_world);
    thread1.join();
    thread2.join();

    //Usually prints 900 but sometimes 891
    std::vector<std::thread> threads;
    for(int i = 0; i < 100;i++) {
        threads.push_back(std::thread(add,3,3));
    }
    for (auto& thread : threads) {
        thread.join();
    }
    std::cout << global_int << "\n";

    //Should work
    std::vector<std::thread> threads_2;
    for(int i = 0; i < 100;i++) {
        threads_2.push_back(std::thread(add_2,3,3));
    }
    for (auto& thread : threads_2) {
        thread.join();
    }
    std::cout << global_int_2 << "\n";
    
    //Should work
    std::vector<std::thread> threads_3;
    for(int i = 0; i < 100;i++) {
        threads_3.push_back(std::thread(add_3,3,3));
    }
    for (auto& thread : threads_3) {
        thread.join();
    }
    std::cout << global_int_3 << "\n";
    return 0;
}

