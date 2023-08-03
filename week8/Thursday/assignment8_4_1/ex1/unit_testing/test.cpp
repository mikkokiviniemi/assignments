#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../source/utils.h"

TEST_CASE("Default constructor") {
    heap_array<int, 5> arr;
    CHECK(arr.size() == 5);
    CHECK(arr.empty() == false);
    
}

TEST_CASE("Copy constructor") {
    heap_array<int, 5> arr1;
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;

    heap_array<int, 5> arr2(arr1);
    CHECK(arr2.size() == arr1.size());
    CHECK(arr2 == arr1);
}

TEST_CASE("Move constructor") {
    heap_array<int, 5> arr1;
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;

    heap_array<int, 5> arr2(std::move(arr1));
    CHECK(arr1.empty() == true);
    CHECK(arr2[0] == 1);
    CHECK(arr2[1] == 2);
    CHECK(arr2[2] == 3);
}

TEST_CASE("Copy assignment operator") {
    heap_array<int, 5> arr1;
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;

    heap_array<int, 5> arr2;
    arr2 = arr1;
    CHECK(arr2 == arr1);
}

TEST_CASE("Move assignment operator") {
    heap_array<int, 5> arr1;
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;

    heap_array<int, 5> arr2;
    arr2 = std::move(arr1);
    CHECK(arr1.empty() == true);
    CHECK(arr2[0] == 1);
    CHECK(arr2[1] == 2);
    CHECK(arr2[2] == 3);
}

TEST_CASE("Swap function") {
    heap_array<int, 5> arr1;
    arr1[0] = 1;
    arr1[1] = 2;

    heap_array<int, 5> arr2;
    arr2[2] = 3;

    arr1.swap(arr2);
    CHECK(arr1[2] == 3);
    CHECK(arr2[0] == 1);
    CHECK(arr2[1] == 2);

    std::swap(arr1,arr2);
    CHECK(arr2[2] == 3);
    CHECK(arr1[0] == 1);
    CHECK(arr1[1] == 2);

}

TEST_CASE("Clear function") {
    heap_array<int, 5> arr;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    arr.clear();
    for (int i = 0; i < arr.size(); ++i) {
        CHECK(arr[i] == 0);
    }
}

TEST_CASE("Access operator") {
    heap_array<int, 5> arr;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    CHECK(arr[0] == 1);
    CHECK(arr[1] == 2);
    CHECK(arr[2] == 3);
}

