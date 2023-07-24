#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdio>
#include <cstdlib>

class Text_file_reader {
    public:
        Text_file_reader(const std::string &file_name);
        ~Text_file_reader();
        std::string read_line();
    private:
        FILE* file;
};


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
        Positive_int();
        Positive_int(int number);
        Positive_int(const Positive_int &other);
        Positive_int &operator=(const Positive_int &other);
        Positive_int &operator=(int number);
        Positive_int operator-(const Positive_int &other);
        Positive_int operator+(const Positive_int &other);
        void print_value() const;
        friend Positive_int add(const Positive_int &number1, Positive_int &number2);
        friend Positive_int sub(const Positive_int &number1, Positive_int &number2);   

    private:
        int value;
};

//Type of entity
enum class Type
{
    Robot,
    Person,
    Alien,
};

//Identifyer of entity
union Identifyer
{
    int id;
    char initial;
    float eye_wave;
};

//Entity class
class Entity
{
    public:
        void set_id (int id);
        void set_id (char id);
        void set_id (float id);

        Type get_type();
        Identifyer get_id();

        std::string info();
    private:
        Type type;
        Identifyer id;

};

#endif

