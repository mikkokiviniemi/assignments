#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "utils.h"

TEST_CASE("testing math functions") {
    std::vector<int> test_vec = {1};
    std::vector<int> want_vec = {1, 3, 3, 1};
    std::vector<int> result_vec = pascal_triangle(4, test_vec);
    CHECK(result_vec == want_vec);
}