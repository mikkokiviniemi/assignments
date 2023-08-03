#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../source/utils.h"

TEST_CASE("Utils test"){        

    CHECK(0 == 0);
    
}

TEST_CASE("EX2") {
    EX2<false> obj1;
    EX2<false> obj2(obj1);
    EX2<false> obj3(std::move(obj1));
    obj2.~EX2();
    CHECK(obj1.default_constructor_count() == 1);
    CHECK(obj1.copy_constructor_count() == 1);
    CHECK(obj1.move_constructor_count() == 1);
    CHECK(obj1.destructor_count() == 1);
}
