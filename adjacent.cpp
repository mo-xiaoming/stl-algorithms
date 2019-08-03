#include <algorithm>
#include <array>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("014 adjacent_find")
{
    constexpr auto arr = std::array{0, 1, 1, 2, 2};

    SECTION("stl") { CHECK(std::adjacent_find(begin(arr), end(arr)) == (begin(arr) + 1)); }
}

TEST_CASE("014 adjacent_find with func")
{
    constexpr auto arr = std::array{0, 1, 1, 2, 2, 4, 5};

    SECTION("stl")
    {
        CHECK(std::adjacent_find(begin(arr), end(arr), [](auto i, auto j) { return j - i == 2; })
              == (begin(arr) + 4));
    }
}

TEST_CASE("088 accumulate")
{
    constexpr auto arr = std::array{1, 2, 3, 4};

    SECTION("stl")
    {
        CHECK(std::accumulate(begin(arr), end(arr), 1, std::multiplies<int>()) == 24);
    }
}
