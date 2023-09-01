#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits.h>

class Instance {
    public:
        Instance() {
            instance_count++;
        }

        ~Instance() {
            instance_count--;
        }

        static int get_count() {
            return instance_count;
        }
        
        static int instance_count;
};


class Positive_int {
    public:
        Positive_int() : value(0) {}
        Positive_int(int number){
            if (number < 0) {
                throw std::invalid_argument("Can't be negative number!");
            }
            else if (number > INT_MAX){
                value = INT_MAX;
            }
            value = number;
        };
        Positive_int(const Positive_int& other) : value(other.value){};
        
        Positive_int& operator =(const Positive_int& other){
            value = other.value;
            return *this;
        };

        Positive_int& operator =(int number){
            if (number < 0) {
                throw std::invalid_argument("Can't be negative number!");
            }
            else if (number > INT_MAX){
                value = INT_MAX;
            }
            value = number;
            return *this;
        };

        Positive_int operator -(const Positive_int& other) const{
            Positive_int sum;
            int num1 = value;
            int num2 = other.value;
            if(num1 - num2 > 0){
                sum = num1 - num2;
            } 
            else {
                sum = 0;
            }
            return sum;

        };

        Positive_int operator +(const Positive_int& other) const{
            Positive_int sum;
            int num1 = value;
            int num2 = other.value;
            if (num1 + num2 > INT_MAX){
                sum = INT_MAX;
            } else {
                sum = num1 + num2;
            }
            return sum;

        };

        void print_value () const 
        {
            std::cout << value << "\n";
        };

    private:
        int value;
};


#endif  