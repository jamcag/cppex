cmake_minimum_required(VERSION 3.16)

project(cpp)


add_subdirectory(lib/Catch2-3.2.1)

add_executable(getline getline.cpp)
target_link_libraries(getline PRIVATE Catch2::Catch2WithMain)

add_executable(mapcontains mapcontains.cpp)
target_link_libraries(mapcontains PRIVATE Catch2::Catch2WithMain)
set_property(TARGET mapcontains PROPERTY CXX_STANDARD 20)

add_executable(accumulate accumulate.cpp)
target_link_libraries(accumulate)
set_property(TARGET accumulate PROPERTY CXX_STANDARD 20)
