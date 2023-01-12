// A use case for istringstreams is to process files with relevant blank lines.
// For example in Problem 1 of AoC 2022, the input is given as sets of weights separated by blank lines.
//
// Example:
//   104
//   32
//
//   2
// Here, the first elf has two items and the second has one item.
// By default reading from an istream to an int discards whitespace.
// Passing the istream into std::noskipws disables this behavior.

#include "catch2/catch_test_macros.hpp"

#include <vector>
#include <sstream>

/// @brief Put line-separated integers into a vector until a blank line is encountered.
/// @param is The input stream.
/// @param[out] v The vector.
/// @return The passed input stream.
std::istream& operator>>(std::istream& is, std::vector<int>& v) {
    v.clear();

    // The pattern for working with these kinds of inputs is to use std::getline to detect blank lines.
    std::string s;
    while (std::getline(is, s)) {
        if (s.empty()) {
            break;
        }

        // You can then put that line into a stringstream to convert it into an integer.
        std::istringstream iss{s};
        int i;
        iss >> i;
        v.emplace_back(i);
    }
    return is;
}

// This test is for demonstrating basic functionality.
TEST_CASE("Can put blank-line free stream into a vector", "[istream-vector]") {
    std::istringstream iss("1\n2\n");
    std::vector<int> v;

    iss >> v;

    REQUIRE(v.size() == 2);
    REQUIRE(v.at(0) == 1);
    REQUIRE(v.at(1) == 2);
}

// This test is for showing that we can process files like in the example.
TEST_CASE("Can put streams with blank lines into separate vector", "[istream-vector]") {
    std::istringstream iss("1\n2\n\n3\n");
    std::vector<int> v;

    iss >> v;

    REQUIRE(v.size() == 2);
    REQUIRE(v.at(0) == 1);
    REQUIRE(v.at(1) == 2);

    iss >> v;
    REQUIRE(v.size() == 1);
    REQUIRE(v.at(0) == 3);
}
