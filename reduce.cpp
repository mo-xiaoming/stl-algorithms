#include <algorithm>
#include <array>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("092 reduce")
{
    constexpr auto arr = std::array{0, 1, 2, 3};

    SECTION("stl")
    {
        CHECK(std::reduce(begin(arr), end(arr), 0), == 6);
    }
}
