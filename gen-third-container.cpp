#include <algorithm>
#include <array>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("023 transform with two input")
{
    constexpr auto arr1 = std::array{0, 1, 2, 3, 4, 5};
    constexpr auto arr2 = std::array{5, 4, 3, 2, 1, 0};
    constexpr auto result = std::array{5, 5, 5, 5, 5, 5};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::transform(begin(arr1), end(arr1), begin(arr2), std::back_inserter(dest),
                       [](auto i, auto j) { return i + j; });
        CHECK(equal(result, dest));
    }
}

TEST_CASE("063 set_difference")
{
    constexpr auto a = std::array{0, 1, 2, 3, 4};
    constexpr auto b = std::array{3, 4, 5};
    constexpr auto result = std::array{0, 1, 2};

    SECTION("stl")
    {
        auto v = std::vector<int>{};
        std::set_difference(begin(a), end(a), begin(b), end(b), std::back_inserter(v));
        CHECK(equal(v, result));
    }
}

TEST_CASE("064 set_intersection")
{
    constexpr auto a = std::array{0, 1, 2, 3, 4};
    constexpr auto b = std::array{3, 4, 5};
    constexpr auto result = std::array{3, 4};

    SECTION("stl")
    {
        auto v = std::vector<int>{};
        std::set_intersection(begin(a), end(a), begin(b), end(b), std::back_inserter(v));
        CHECK(equal(v, result));
    }
}
