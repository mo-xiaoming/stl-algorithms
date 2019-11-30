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
        CHECK(std::reduce(begin(arr), end(arr), 0) == 6);
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

TEST_CASE("089 inner_product")
{
    constexpr auto a = std::array{1, 2, 3};
    constexpr auto b = std::array{4, 5, 6};
    constexpr int result = (1 + 4) * (2 + 5) * (3 + 6) * 2;

    constexpr auto c = std::array{1, 2, 3, 4, 5};
    constexpr auto d = std::array{1, 0, 3, 4, 7};

    SECTION("stl")
    {
        CHECK(std::inner_product(begin(a), end(a), begin(b), 2, std::multiplies<int>(),
                                 std::plus<int>())
              == result);
        CHECK(std::inner_product(begin(c), end(c), begin(d), 0, std::plus<int>(),
                                 std::equal_to<int>())
              == 3);
    }
}

TEST_CASE("094 transform_reduce")
{
    constexpr auto a = std::array{1, 2, 3};
    constexpr auto b = std::array{4, 5, 6};
    constexpr int result = (1 + 4) * (2 + 5) * (3 + 6) * 2;

    constexpr auto c = std::array{1, 2, 3, 4, 5};
    constexpr auto d = std::array{1, 0, 3, 4, 7};

    SECTION("stl")
    {
        CHECK(std::transform_reduce(begin(a), end(a), begin(b), 2, std::multiplies<int>(),
                                 std::plus<int>())
              == result);
        CHECK(std::transform_reduce(begin(c), end(c), begin(d), 0, std::plus<int>(),
                                 std::equal_to<int>())
              == 3);
    }
}
