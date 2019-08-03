#include <algorithm>
#include <array>
#include <vector>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("027 remove")
{
    auto v = std::vector{1, 2, 3, 4, 5};
    constexpr auto result = std::array{1, 3, 4, 5};

    SECTION("stl")
    {
        v.erase(std::remove(begin(v), end(v), 2), end(v));
        CHECK(equal(v, result));
    }
}

TEST_CASE("028 remove_if")
{
    auto v = std::vector{1, 2, 3, 4, 5};
    constexpr auto result = std::array{1, 3, 5};

    SECTION("stl")
    {
        v.erase(std::remove_if(begin(v), end(v), is_even<int>), end(v));
        CHECK(equal(v, result));
    }
}

TEST_CASE("031 replace")
{
    auto v = std::vector{1, 2, 3, 4, 5};
    constexpr auto result = std::array{1, 7, 3, 4, 5};

    SECTION("stl")
    {
        std::replace(begin(v), end(v), 2, 7);
        CHECK(equal(v, result));
    }
}

TEST_CASE("032 replace_if")
{
    auto v = std::vector{1, 2, 3, 4, 5};
    constexpr auto result = std::array{1, 7, 3, 7, 5};

    SECTION("stl")
    {
        std::replace_if(begin(v), end(v), is_even<int>, 7);
        CHECK(equal(v, result));
    }
}

TEST_CASE("038 reverse")
{
    auto v = std::vector{1, 2, 3, 4};
    constexpr auto result = std::array{4, 3, 2, 1};

    SECTION("stl")
    {
        std::reverse(begin(v), end(v));
        CHECK(equal(v, result));
    }
}

TEST_CASE("043 unique")
{
    auto v = std::vector{1, 2, 2, 3, 2};
    constexpr auto result = std::array{1, 2, 3, 2};

    SECTION("stl")
    {
        v.erase(std::unique(begin(v), end(v)), end(v));
        CHECK(equal(v, result));
    }
}
