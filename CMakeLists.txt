cmake_minimum_required(VERSION 3.16)

project(cpp)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib/Catch2-3.2.1)

add_executable(getline getline.cpp)
target_link_libraries(getline PRIVATE Catch2::Catch2WithMain)

add_executable(mapcontains mapcontains.cpp)
target_link_libraries(mapcontains PRIVATE Catch2::Catch2WithMain)

add_executable(accumulate accumulate.cpp)
target_link_libraries(accumulate)

add_executable(thread_hello thread_hello.cpp)

add_executable(overwrite overwrite.cpp)

add_executable(user_defined_literals user_defined_literals.cpp)
