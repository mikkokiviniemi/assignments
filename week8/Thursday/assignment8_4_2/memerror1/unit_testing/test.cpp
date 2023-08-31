#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../source/utils.h"



TEST_CASE("large_object") {
    {
    large_object obj1;
    large_object obj2;
    large_object a(obj2); //ei toimi
    large_object b = a; //ei toimi
    CHECK(object_storage.size() == 2);
    for(auto& elem : object_storage) {
        std::cout << elem.name << "\n";
    }
    }
    CHECK(object_storage.size() == 0);
}

