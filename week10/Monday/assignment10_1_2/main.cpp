#include "source/utils.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

/*
Exercise 1

Create a log, a vector of strings is a decent choice for the storage.  Knowing it will be accessed from multiple threads, think a bit how you want to handle it.
Create a function to read user input until user writes "quit" (or some other way for the user to gracefully exit) Add the read input to the log.

Create a function to add a message to the log every second.  (e.g. "one second passed" or "program has been running for n seconds")

Make the program print the log if user input matches some command e.g. "log"
Launch both functions in separate threads, try it out.

Implement functionality so the second loop exits gracefully if the user decided to exit.
*/

static int seconds = 0;
std::mutex log_mutex;
bool quit = false;

//Logs user inputs, exit with "quit"
void user_input(std::vector<std::string>& log) {
    std::string input = "";
    while (!quit) {
        std::cout << ">";
        std::getline(std::cin, input);
        {
            std::lock_guard<std::mutex> lock(log_mutex);
            log.push_back(input);
        }
        if (input == "quit") {
            quit = true;
        }
    }
}
//Logs every second (as number);
void log_seconds(std::vector<std::string>& log) {
    while (!quit) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        seconds++;
        {
            std::lock_guard<std::mutex> lock(log_mutex);
            log.push_back(std::to_string(seconds));
        }
    }
}

int main(int argc, char const* argv[]) {
    std::vector<std::string> log;

    std::thread thread_input(user_input, std::ref(log));
    std::thread thread_seconds(log_seconds, std::ref(log));

    thread_input.join();
    thread_seconds.join();

    // Print the log after threads have finished
    for (const auto& elem : log) {
        std::cout << elem << "\n";
    }

    return 0;
}




