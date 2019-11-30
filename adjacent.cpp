#include <algorithm>
#include <array>
#include <functional>
#include <numeric>

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

TEST_CASE("090 adjacent_difference")
{
    auto v = std::vector{0, 3, 2, 9, 8};
    constexpr auto result = std::array{0, 3, -1, 7, -1};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::adjacent_difference(begin(v), end(v), std::back_inserter(dest));
        CHECK(equal(result, dest));
    }
}

TEST_CASE("091 partial_sum")
{
    auto v = std::vector{0, 3, 2, 9, 8};
    constexpr auto result = std::array{0, 3, 5, 14, 22};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::partial_sum(begin(v), end(v), std::back_inserter(dest));
        CHECK(equal(result, dest));
    }
}


TEST_CASE("093 inclusive_sum")
{
    auto v = std::vector{0, 3, 2, 9, 8};
    constexpr auto result = std::array{0, 3, 5, 14, 22};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::inclusive_scan(begin(v), end(v), std::back_inserter(dest));
        CHECK(equal(result, dest));
    }
}

TEST_CASE("094 exclusive_sum")
{
    auto v = std::vector{0, 3, 2, 9, 8};
    constexpr auto result = std::array{0, 0, 3, 5, 14};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::exclusive_scan(begin(v), end(v), std::back_inserter(dest), 0);
        CHECK(equal(result, dest));
    }
}
