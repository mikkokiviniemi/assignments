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

        Entity() = default;

        Entity(int id) {
            set_id(id);
        }
        Entity(char id) {
            set_id(id);
        }
        Entity(float id) {
            set_id(id);
        }

        ~Entity() {}

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