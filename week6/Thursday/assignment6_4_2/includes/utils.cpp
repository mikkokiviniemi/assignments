#include "utils.h"

/*Text file thing*/

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
// Saves line to lines vector
void Text_file_reader::save_line(const std::string &line)
{
    lines.push_back(line);
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
// Formats Entity for std::cout
std::ostream& operator<<(std::ostream& os, const Entity being){
    switch (being.type)
    {
        case Type::Robot:
        {
            os << std::to_string(being.id.id) << " Robot";
            break;
        }
        case Type::Person:
        {
            std::string s(1, being.id.initial);
            os << s << " Human";
            break;
        }
        case Type::Alien:
        {
            os << std::to_string(being.id.eye_wave) << " Alien";
            break;
        }

    }
    return os;
}
//Check if string is float
bool is_float(std::string_view input)
{
    double val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}
//Check if string is int
bool is_int(std::string_view input)
{
    int val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}

/*
Create a function (think about where you should put this) that reads in a string,
checks its contents and creates Object type from the contents.  (So if it the string
represents an integer, the Object should contain integer, if it is a string/char, it should
be initial, etc.)
*/
Entity::Entity(std::string input) {
    if(is_float(input) && !is_int(input)) {
        Entity::set_id(std::stof(input));
    } else if (is_int(input)){
        Entity::set_id(std::stoi(input));
    } else {
        Entity::set_id(*input.data());
    }
}