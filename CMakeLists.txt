cmake_minimum_required(VERSION 3.16)

project(cpp)


add_subdirectory(lib/Catch2-3.2.1)

add_executable(getline getline.cpp)
target_link_libraries(getline PRIVATE Catch2::Catch2WithMain)
