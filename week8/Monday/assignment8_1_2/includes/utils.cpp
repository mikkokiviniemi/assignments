#include "utils.h"

void demonstrate_animal (animal& animal) {
    std::cout << "Name: " <<  animal.get_name() << "\nSound:\n- ";
    animal.make_sound();
    std::cout << std::boolalpha <<  "\nIs fluffy: " << animal.is_fluffy() << "\n";
}

std::vector<std::unique_ptr<animal>> read_file(std::string filename) {
    std::vector<std::unique_ptr<animal>> animals;
    std::ifstream file(filename);
    
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);

            std::string species;
            std::string name;

            std::getline(ss, species, ',');
            std::getline(ss, name);

            std::unique_ptr<animal> new_animal;
            if (species == "cow") {
                new_animal = std::make_unique<cow>();
            } 
            else if (species == "chicken") {
                new_animal = std::make_unique<chicken>();
            }
            else {
                throw std::runtime_error("Bad file!\n");
            }
            if (name != "") {
                new_animal->set_name(name);
            }
            animals.push_back(std::move(new_animal));
        }
        file.close();
    } else {
        throw std::runtime_error("Failed to open the file!\n");
    }

    return animals;
}