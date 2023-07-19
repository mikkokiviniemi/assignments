/*

:::::::::::::::
Animal created
Wings created
Eyes created
Bird created
Parrot created
Mass: 3.1
Length: 1.5
Wingspan: 4
Eye color: Red
Parrot destroyed
Bird destroyed
Eyes destroyed
Wings destroyed
Animal destroyed

*/


#ifndef UTILS_H
#define UTILS_H

#include <iostream>

class Animal
{
    public:
        Animal(float mass,float length) {
            this->mass = mass;
            this->length = length;
            std::cout << "Animal created\n";
        }
        ~Animal(){
            std::cout << "Animal destroyed\n";
        }
        void info (){
            std::cout 
            << "Mass: " <<this->mass << "\n"
            << "Length: " <<this->length << "\n";
        }
        float mass;
        float length;
    private:
        
};
class Wings
{
    public:
        Wings(){}
        Wings(float length) {
            wingspan_length = length;
            std::cout << "Wings created\n";
        }
        ~Wings(){
            std::cout << "Wings destroyed\n";
        }
        void info (){
            std::cout 
            << "Wing span: " <<this->wingspan_length << "\n";
        }
        float wingspan_length;
    private:
        
};
class Eyes
{
    public:
        Eyes(){};
        Eyes(std::string color) {
            this->color = color;
            std::cout << "Eyes created\n";
        }
        ~Eyes(){
            std::cout << "Eyes destroyed\n";
        }
        std::string color;
        void info (){
            std::cout 
            << "Eye color: " <<this->color << "\n";
        }
    private:
        
};
class Bird : public Animal
{
    public:
        Bird(float mass, float length, float wing_span,std::string eye_color) : Animal(mass,length),eye(eye_color),wing(wing_span){
            std::cout << "Bird created\n";
        }
        ~Bird(){
            std::cout << "Bird destroyed\n";
        }
        Wings wing;
        Eyes eye;

        void info (){
            std::cout 
            << "Mass: " <<this->mass << "\n"
            << "Length: " <<this->length << "\n"
            << "Wingspan: " <<this->wing.wingspan_length << "\n"
            << "Eye color: " <<this->eye.color << "\n";
        }
    private:
};
class Parrot : public Bird
{
    public:
        Parrot (float mass, float length, float wing_span,std::string eye_color) : Bird(mass,length,wing_span,eye_color) {
            std::cout << "Parrot created\n";
        }
        ~Parrot(){
            std::cout << "Parrot destroyed\n";
        }
        void info (){
            std::cout 
            << "Parrot: \n"
            << "Mass: " <<this->mass << "\n"
            << "Length: " <<this->length << "\n"
            << "Wingspan: " <<this->wing.wingspan_length << "\n"
            << "Eye color: " <<this->eye.color << "\n";
        }
    private:
};
class Dog : public Animal
{
    public:
        Dog(float mass, float length,std::string eye_color) : Animal(mass,length),eye(eye_color) {
            std::cout << "Dog created\n";
        }
        ~Dog(){
            std::cout << "Dog destroyed\n";
        }
        void info (){
            std::cout 
            << "Mass: " <<this->mass << "\n"
            << "Length: " <<this->length << "\n"
            << "Eye color: " <<this->eye.color << "\n";
        }
        Eyes eye;
    private:
        
        
};

#endif  