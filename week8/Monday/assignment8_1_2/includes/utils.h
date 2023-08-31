#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>

class animal {
    public:
        virtual ~animal() {}
        virtual void make_sound() = 0;
        virtual bool is_fluffy() const {return false;}
        virtual std::string get_name(){return "";}
        virtual void set_name(const std::string& new_name) = 0;
};
class cow : public animal {
    public:
        cow(){}
        void make_sound() override {
            std::cout << "Muu!";
        }
        bool is_fluffy() const override {
            return fluffy;
        }
        std::string get_name() override{
            return name;
        }
        void set_name (const std::string& new_name) {
            name = new_name;
        }
    private:
        std::string name = "Mansikki";
        bool fluffy = true;
};
class chicken : public animal {
    public:
        chicken(){}
        void make_sound() override {
            std::cout << "Kotkot!";
        }
        std::string get_name() override{
            return name;
        }
        void set_name (const std::string& new_name) {
            name = new_name;
        }
    private:
        std::string name = "Teriaki";
};
// Print animal name, sound and if its fluffy.
void demonstrate_animal (animal& animal);
// Reads file and makes vector of animal pointers. If animal have name, updates it.
std::vector<std::unique_ptr<animal>> read_file(std::string filename);

#endif  