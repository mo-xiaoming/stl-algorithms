#include <algorithm>
#include <array>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("036 swap_ranges")
{
    auto a = std::vector{1, 1, 1, 1};
    auto b = std::vector{2, 2, 2, 2};

    SECTION("stl")
    {
        std::swap_ranges(begin(a), end(a), begin(b));
        CHECK(std::all_of(begin(a), end(a), [](auto i) { return i == 2; }));
        CHECK(std::all_of(begin(b), end(b), [](auto i) { return i == 1; }));
    }
}
