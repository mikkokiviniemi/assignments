#include "source/utils.h"
#include <iostream>
#include <cassert>
#include <fmt/core.h>
#include <nlohmann/json.hpp>
#include <backward.hpp>
#include <fstream>

using json = nlohmann::json;



int main() {

    json json_object = {
        {"name", "John"},
        {"age", 30},
        {"city", "New York"}
    };


    std::ifstream f("json-example-master/animals-1.json", std::ifstream::in);

    json j;

    f >> j;

    std::cout << j.dump(2) << std::endl;


    std::ofstream o("json-example-master/test.json");
    o << json_object.dump(2) << std::endl;

    fmt::print("Hello, {}!\n", "world");

    
    using namespace backward;
    StackTrace st; st.load_here(32);
    Printer p; p.print(st);
    assert(0);
    return 0;
}