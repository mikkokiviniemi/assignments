#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <charconv>

class Text_file_reader {
    public:
        std::vector<std::string> lines;
        Text_file_reader(const std::string &file_name);
        ~Text_file_reader();
        std::string read_line();
        void save_line(const std::string &line);

    private:
        FILE* file;
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
        Entity(){};
        void set_id (int id);
        void set_id (char id);
        void set_id (float id);

        Type get_type();
        Identifyer get_id();

        std::string info();
        Entity(std::string input);
        friend std::ostream &operator<<(std::ostream &os, const Entity being);

    private:
        Type type;
        Identifyer id;

};

bool is_float(std::string_view input);

bool is_int(std::string_view input);

#endif  