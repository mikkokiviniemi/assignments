#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <random>

enum class Status
{
    success,
    error_1,
    error_2,
    error_3,
};
enum class State
{
    ordered,
    sent,
    on_delivery,
    delivered,
};
class Order {
    public:
        Order() : status(State::ordered) {}
        std::string string_state();
        void next_state();

    private:
        State status;
};

int random_between(int min, int max);

#endif
