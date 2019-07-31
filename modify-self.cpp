#include <algorithm>
#include <array>
#include <vector>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("027 remove")
{
    auto v = std::vector<int>{1, 2, 3, 4, 5};
    constexpr auto result = std::array{1, 3, 4, 5};

    SECTION("stl")
    {
        v.erase(std::remove(begin(v), end(v), 2), end(v));
        CHECK(std::equal(begin(v), end(v), begin(result), end(result)));
    }
}

TEST_CASE("028 remove_if")
{
    auto v = std::vector<int>{1, 2, 3, 4, 5};
    constexpr auto result = std::array{1, 3, 5};

    SECTION("stl")
    {
        v.erase(std::remove_if(begin(v), end(v), is_even<int>), end(v));
        CHECK(std::equal(begin(v), end(v), begin(result), end(result)));
    }
}
