#include "source/utils.h"
#include <iostream>
#include <vector>
#include <variant>
/*
Exercise 1
In exercise 6.1.2 we created a tagged union of our own.
Reimplement the same using a std::variant instead.
Use full name instead of the initial this time around.
*/
//Entity class
class Entity
{
    public:
        using Identifyer = std::variant<int,char,float>;
		Entity() : id() {};
		Entity(int id_input) : id(id_input){};
		Entity(char id_input) : id(id_input){};
		Entity(float id_input) : id(id_input){};

        void set_id (int id_input) {
			id = id_input;
		};
        void set_id (char id_input) {
			id = id_input;
		};
        void set_id (float id_input) {
			id = id_input;
		};
		void print_info() const {
			if (std::holds_alternative<int>(id)) {
				std::cout << "Robot: " << std::get<int>(id) << "\n";
			} else if (std::holds_alternative<char>(id)) {
				std::cout << "Human: " << std::get<char>(id) << "\n";
			} else if (std::holds_alternative<float>(id)) {
				std::cout << "Alien: " << std::get<float>(id) << "\n";
			}
		}
	private:
        Identifyer id;
};
/*
Exercise 2
In Ex. 7.4.1 we created a animals using virtual inheritance.
Recreate the same animals without using virtual, and then create a std::variant of the animals and fill a vector with those.

Look at documentation of std::visit, https://en.cppreference.com/w/cpp/utility/variant/visitLinks to an external site.

Using the "void visitor", call the demonstration function of each animal entry.
Using one of the type-matching visitors, print some text relating to the animal matched
*/

class cow{
    public:
        cow(){}
        void make_sound(){
            std::cout << "Muu!";
        }
        bool is_fluffy() const{
            return fluffy;
        }
        std::string get_name(){
            return name;
        }
    private:
        std::string name = "Mansikki";
        bool fluffy = true;
};
class chicken{
    public:
        chicken(){}
        void make_sound(){
            std::cout << "Kotkot!";
        }
        std::string get_name(){
            return name;
        }
    private:
        std::string name = "Teriaki";
};

using Animal = std::variant<cow,chicken>;

template<class... Ts>
struct overloaded : Ts... { using Ts::operator()...; };

template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;



int main(int argc, char const *argv[])
{
    Entity test_entity;
    test_entity.set_id('W');
    test_entity.print_info();
    test_entity.set_id(3);
    test_entity.print_info();
    test_entity.set_id(3.14f);
    test_entity.print_info();
    
    std::vector<Animal> zoo;
    chicken test_chicken;
    cow test_cow;
    zoo.push_back(test_chicken);
    zoo.push_back(test_cow);

    for(auto& animal : zoo) {
        std::visit(overloaded{
            [](auto arg) {
                std::cout << arg.get_name() << "\n";
            },
            [](cow arg) { 
                std::cout << arg.get_name() << "\n";
                arg.make_sound();
                std::cout << "\nIs fluffy: " << arg.is_fluffy() << "\n";
            },
            [](chicken arg) { 
                std::cout << arg.get_name() << "\n";
                arg.make_sound();
                std::cout << "\n";
            }
        }, animal);
    }

    return 0;
}

