#include "catch2/catch_test_macros.hpp"

#include <map>

TEST_CASE("Can use std::map::contains") {
    const std::map<char, int> m{{'a', 1}, {'b', 2}};
    REQUIRE(m.contains('a'));
    REQUIRE(m.contains('b'));
    REQUIRE(!m.contains('c'));
}
