#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../utils/utils.h"

TEST_CASE("Some tests") {

        heap_array<int,10> test_array;
        CHECK(test_array[10] == 0);
        
        heap_array<int,10> test_array2 = test_array;
        CHECK(test_array2 == test_array);
        
        for(int i = 0; i < test_array.size(); i++){
            test_array[i] = i;
        }
        test_array2 = test_array;
        CHECK(test_array2 == test_array);

        CHECK(test_array2[3] == 3);
        
        
        
}