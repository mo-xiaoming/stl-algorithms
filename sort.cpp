#include <algorithm>
#include <array>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("045 partition")
{
    auto v = std::vector{0, 1, 2, 3, 4, 5};

    SECTION("stl") { CHECK(std::partition(begin(v), end(v), is_even<int>) == begin(v) + 3); }
}

TEST_CASE("046 stable_partition")
{
    auto v = std::vector{0, 1, 2, 3, 4, 5};
    constexpr auto result = std::array{0, 2, 4, 1, 3, 5};

    SECTION("stl")
    {
        CHECK(std::stable_partition(begin(v), end(v), is_even<int>) == begin(v) + 3);
        CHECK(equal(v, result));
    }
}

TEST_CASE("048 partitioin_copy")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};
    constexpr auto result1 = std::array{0, 2, 4};
    constexpr auto result2 = std::array{1, 3, 5};

    SECTION("stl")
    {
        auto m = std::vector<int>{};
        auto n = std::vector<int>{};

        std::partition_copy(begin(arr), end(arr), std::back_inserter(m), std::back_inserter(n),
                            is_even<int>);

        CHECK(equal(m, result1));
        CHECK(equal(n, result2));
    }
}
