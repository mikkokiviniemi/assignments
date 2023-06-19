#include "utils.h"

void print_menu (std::vector<Food> menu) {
    //Print menu
    std::cout << "\n--------------------------------\n";
    for(auto& food : menu) {
        std::cout << std::left << std::setw(20) << food.get_name() << std::right << std::setw(10) << food.get_price() << "€\n";
        std::cout << "( ";
        for(auto& ingredient : food.get_ingredients()) {
            std::cout << ingredient << " ";
        }
        std::cout << ")\n\n";
    }
    std::cout << "\n--------------------------------\n";
}

void print_order (std::vector<Food> order) {
    float end_price = 0.0;
    std::cout << "\n--------------------------------\n";
    for(auto& food : order) {   
        std::cout << std::left << std::setw(20) << food.get_name() << std::right << std::setw(10) << food.get_price() << "€\n";
        end_price += food.get_price();
    }
    std::cout << "\n--------------------------------\n";
    std::cout << std::left << std::setw(20) << "Final: " << std::right << std::setw(10) << end_price << "€\n\n";
}

std::vector<Food> ordering_function (std::vector<Food>& menu) {
    std::vector<Food> order;
    
    while(true){
        std::string input;
        std::cout << "What would you like (new,menu,order,stop): ";
        std::getline(std::cin,input);

        if(input == "stop"){break;}
        if(input == "menu") {print_menu(menu);}
        if(input == "order") {print_order(order);}
        if(input == "new") {menu.push_back(new_food());}

        for (auto& food : menu) {
            if(input == food.get_name()){
                order.push_back(food);
            }
        }
    }

    return order;
}

Food new_food() {
    std::string name;
    float price;
    std::string price_s;
    std::vector<std::string> ingredients;

    std::cout << "Food name: ";
    std::getline(std::cin,name);

    std::cout << "Price: ";
    std::getline(std::cin,price_s);
    price = std::stof(price_s);


    while(true) {
        std::string ingredient;
        std::cout << "Ingredient (enter to stop): ";
        std::getline(std::cin,ingredient);
        if(ingredient == ""){
            break;
        } else {
            ingredients.push_back(ingredient);
        }
    }

    Food new_food = {name,price,ingredients};

    return new_food;
}