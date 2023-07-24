#include "utils.h"
// Open text file
Text_file_reader::Text_file_reader(const std::string &file_name)
{
    file = std::fopen(file_name.c_str(), "r");
    if (!file)
    {
        throw std::runtime_error("Failed to open " + file_name);
    }
}
// Close text file
Text_file_reader::~Text_file_reader()
{
    if (file)
    {
        std::fclose(file);
    }
}
// Read next line from file
std::string Text_file_reader::read_line()
{
    std::string line;
    int symbol = 0;
    while ((symbol = std::fgetc(file)) != EOF && symbol != '\n')
    {
        line += static_cast<char>(symbol);
    }
    return line;
}

/*
INT THINGY
*/

Positive_int::Positive_int() : value(0) {}

Positive_int::Positive_int(int number)
{
    if (number < 0)
    {
        throw std::invalid_argument("Can't be negative number!");
    }
    value = number;
};
Positive_int::Positive_int(const Positive_int &other) : value(other.value){};
//Is equal
Positive_int &Positive_int::operator=(const Positive_int &other)
{
    value = other.value;
    return *this;
};
//Is equal
Positive_int &Positive_int::operator=(int number)
{
    if (number < 0)
    {
        throw std::invalid_argument("Can't be negative number!");
    }
    value = number;
    return *this;
};
//Substracts
Positive_int Positive_int::operator-(const Positive_int &other)
{
    Positive_int sum;
    if (value - other.value > 0)
    {
        sum = value - other.value;
    }
    
    return sum;
};
//Adds
Positive_int Positive_int::operator+(const Positive_int &other)
{
    Positive_int sum = value + other.value;

    return sum;
}
//Prints value
void Positive_int::print_value() const
{
    std::cout << value << "\n";
};

//Friend function add
Positive_int add(const Positive_int &number1, Positive_int &number2)
{
    return Positive_int(number1.value + number2.value);
}
//Friend function sub
Positive_int sub(const Positive_int &number1, Positive_int &number2)
{
    if(number1.value > number2.value) {
        return Positive_int(number1.value-number2.value);
    }
    return Positive_int();
}

/*Robot,person,alien*/
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
