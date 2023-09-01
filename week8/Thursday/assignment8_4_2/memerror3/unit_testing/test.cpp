#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../source/utils.h"

TEST_CASE("Test C++ Wrapper") {
    cpp_wrapper wrapped;

    CHECK(wrapped.values().random == 53); // Checking the default value

    SUBCASE("Test do_stuff()") {
        // Redirect cout for testing output
        std::stringstream ss;
        std::streambuf* oldCout = std::cout.rdbuf(ss.rdbuf());

        wrapped.do_stuff();

    }

    SUBCASE("Test build_wrapper()") {
        cpp_wrapper wrapped2 = build_wrapper();

        CHECK(wrapped2.values().random == 42);
    }
}

