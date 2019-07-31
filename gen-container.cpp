#include <algorithm>
#include <array>
#include <vector>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("023 fill")
{
    auto v = std::vector<int>(10, 0);
    SECTION("stl")
    {
        std::fill(begin(v), end(v), 1);
        CHECK(std::all_of(begin(v), end(v), [](auto i) { return i == 1; }));
    }
}

TEST_CASE("024 fill_n")
{
    auto v = std::vector<int>(10, 0);
    SECTION("stl")
    {
        std::fill_n(begin(v), 4, 1);
        CHECK(std::all_of(begin(v), begin(v) + 4, [](auto i) { return i == 1; }));
        CHECK(std::all_of(begin(v) + 4, end(v), [](auto i) { return i == 0; }));
    }
}
