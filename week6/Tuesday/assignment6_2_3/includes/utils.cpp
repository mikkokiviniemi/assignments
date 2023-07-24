#include "utils.h"

//Sets id and type based on id
void Entity::set_id(int id)
{
    type = Type::Robot;
    this->id.id = id;
}
//Sets id and type based on id
void Entity::set_id(char id)
{
    type = Type::Person;
    this->id.initial = id;
}
//Sets id and type based on id
void Entity::set_id(float id)
{
    type = Type::Alien;
    this->id.eye_wave = id;
}

//Return type of the entity
Type Entity::get_type()
{
    return this->type;
}
//Return union of id
Identifyer Entity::get_id()
{
    return this->id;
}

//Returns info as string "id type"
std::string Entity::info()
{
    switch (type)
    {
        case Type::Robot:
        {
            return std::to_string(id.id) + " Robot";
        }
        case Type::Person:
        {
            std::string s(1, id.initial);
            return  s + " Person";
        }
        case Type::Alien:
        {
            return std::to_string(id.eye_wave) + " Alien";
        }

    }
}