#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../source/utils.h"

TEST_CASE("Utils test"){        

    flawed_array<int,10> test_array;
    for (std::size_t i = 0; i < test_array.size(); ++i) {
        test_array[i] = i;
    }
    CHECK(test_array[3] == 3);
    
}

