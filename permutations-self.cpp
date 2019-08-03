#include <algorithm>
#include <array>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("039 rotate")
{
    auto v = std::vector{1, 2, 3, 4, 5};
    constexpr auto result = std::array{3, 4, 5, 1, 2};

    SECTION("stl")
    {
        std::rotate(begin(v), begin(v) + 2, end(v));
        CHECK(equal(v, result));
    }
}

TEST_CASE("041 shuffle")
{
    auto v = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7};

    SECTION("stl")
    {
        std::shuffle(begin(v), end(v), std::mt19937{std::random_device{}()});
        SUCCEED();
    }
}

TEST_CASE("085 next_permutation")
{
    constexpr auto arr = std::array{0, 1, 2};
    auto v = std::vector(begin(arr), end(arr));

    SECTION("stl")
    {
        CHECK(std::next_permutation(begin(v), end(v)));
        CHECK(std::is_permutation(begin(v), end(v), begin(arr)));
    }
}

TEST_CASE("086 prev_permutation")
{
    constexpr auto arr = std::array{0, 1, 2};
    auto v = std::vector(begin(arr), end(arr));

    SECTION("stl") { CHECK(std::prev_permutation(begin(v), end(v)) == false); }
}
