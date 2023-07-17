#include "utils.h"

//Random int generator between min and max
int random_between(int min, int max){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(min, max);
    return distr(generator);
}

//Returns order's state as string
std::string Order::string_state () 
{
    switch (Order::status)
    {
        case State::ordered:
        {
            return "ordered";
            break;
        }
        case State::sent: 
        {
            return "sent";
            break;
        }
        case State::on_delivery:
        {
            return "on delivery";
            break;   
        }
        case State::delivered:
        {
            return "delivered";
            break;
        }
    }
}
//Changes order's state to next state
void Order::next_state()
{
    switch (Order::status)
    {
        case State::ordered: 
        {
            Order::status = State::sent;
            break;
        }
        case State::sent:
        {
            Order::status = State::on_delivery;
            break;
        }
        case State::on_delivery:
        {
            Order::status = State::delivered;
            break;
        }
        case State::delivered:
        {
            std::cout << "Order is delivered.\n";
            break;
        }
    }
}