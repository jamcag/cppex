cmake_minimum_required(VERSION 3.16)

project(cpp)


add_subdirectory(lib/Catch2-3.2.1)

add_executable(istringstream_tests istringstream_tests.cpp)
target_link_libraries(istringstream_tests PRIVATE Catch2::Catch2WithMain)
