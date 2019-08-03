#include <algorithm>
#include <array>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("006 for_each")
{
    auto arr = std::array{1, 2, 3, 4, 5, 4, 7};
    constexpr auto result = std::array{2, 3, 4, 5, 6, 5, 8};
    SECTION("stl")
    {
        std::for_each(begin(arr), end(arr), inc_self);
        CHECK(equal(arr, result));
    }

    SECTION("my")
    {
        my_for_each(begin(arr), end(arr), inc_self);
        CHECK(equal(arr, result));
    }
}

TEST_CASE("007 for_each_n")
{
    auto arr = std::array{1, 2, 3, 4, 5, 4, 7};
    constexpr auto result = std::array{2, 3, 4, 4, 5, 4, 7};
    SECTION("stl")
    {
        // could not get it build, because boost needs opencl for for_each_n?
        // boost::compute::for_each_n(begin(arr), 3, inc_self);
        // CHECK(equal(arr, result));
    }

    SECTION("my")
    {
        my_for_each_n(begin(arr), 3, inc_self);
        CHECK(equal(arr, result));
    }
}

TEST_CASE("037 iter_swap")
{
    auto arr = std::vector{1, 2, 3, 4};
    constexpr auto result = std::array{4, 2, 3, 1};

    SECTION("stl")
    {
        std::iter_swap(begin(arr), end(arr) - 1);
        CHECK(equal(arr, result));
    }
}

TEST_CASE("080 clamp")
{
    SECTION("stl")
    {
        CHECK(std::clamp(3, 1, 4) == 3);
        CHECK(std::clamp(3, 4, 7) == 4);
        CHECK(std::clamp(5, 1, 4) == 4);
    }
}

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
