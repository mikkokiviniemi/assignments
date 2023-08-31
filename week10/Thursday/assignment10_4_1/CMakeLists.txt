cmake_minimum_required(VERSION 3.20)
project(my_app)
include(FetchContent)

FetchContent_Declare(backward
        GIT_REPOSITORY https://github.com/bombela/backward-cpp
        GIT_TAG v1.6)
FetchContent_MakeAvailable(backward)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(${PROJECT_NAME} main.cpp ${BACKWARD_ENABLE})
add_subdirectory(unit_testing)
add_subdirectory(source)

target_link_libraries(${PROJECT_NAME} PRIVATE Source)

# Set the path to the fmt library
set(FMT_DIR "${CMAKE_SOURCE_DIR}/external/fmt")
find_package(fmt REQUIRED PATHS ${FMT_DIR})


FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

# Link fmt library to the target
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt nlohmann_json::nlohmann_json)

# Include fmt headers
target_include_directories(${PROJECT_NAME} PRIVATE ${FMT_DIR}/include)

add_backward(${PROJECT_NAME})