#ifndef UTILS_H
#define UTILS_H

#include <iostream>

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