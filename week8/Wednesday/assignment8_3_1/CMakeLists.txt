cmake_minimum_required(VERSION 3.20)
project(assignment)

add_executable(${PROJECT_NAME} main.cpp ${sources})

add_subdirectory(utils)

target_link_libraries(${PROJECT_NAME} Utils)