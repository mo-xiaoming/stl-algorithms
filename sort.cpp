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

TEST_CASE("049 sort")
{
    auto v = std::vector{1, 2, 3, 4};
    constexpr auto result = std::array{4, 3, 2, 1};

    SECTION("stl")
    {
        std::sort(begin(v), end(v), std::greater<int>());
        CHECK(equal(v, result));
    }
}

TEST_CASE("051 partial_sort")
{
    auto v = std::vector{1, 2, 3, 4};
    constexpr auto result = std::array{4, 3};

    SECTION("stl")
    {
        std::partial_sort(begin(v), begin(v) + 2, end(v), std::greater<int>());
        CHECK(std::equal(begin(v), begin(v) + 2, begin(result), end(result)));
    }
}

TEST_CASE("053 stable_sort")
{
    auto v = std::vector{1, 2, 3, 4};
    constexpr auto result = std::array{4, 3};

    SECTION("stl")
    {
        std::partial_sort(begin(v), begin(v) + 2, end(v), std::greater<int>());
        CHECK(std::equal(begin(v), begin(v) + 2, begin(result), end(result)));
    }
}

TEST_CASE("054 nth_element")
{
    auto v = std::vector{1, 2, 3, 4, 5, 6};

    SECTION("stl")
    {
        std::nth_element(begin(v), begin(v) + 1, end(v), std::greater<int>());
        CHECK(*(begin(v) + 1) == 5);
        CHECK(*std::min_element(begin(v), begin(v) + 2) == *(begin(v) + 1));
    }
}

TEST_CASE("060 merge")
{
    constexpr auto a = std::array{0, 2, 3, 5};
    constexpr auto b = std::array{2, 6, 7};
    constexpr auto result = std::array{0, 2, 2, 3, 5, 6, 7};

    SECTION("stl")
    {
        auto v = std::vector<int>{};
        std::merge(begin(a), end(a), begin(b), end(b), std::back_inserter(v));
        CHECK(equal(result, v));
    }
}

TEST_CASE("061 inplace_merge")
{
    auto v = std::vector{2, 6, 4, 7, 3, 5, 8, 3};
    constexpr auto result = std::array{2, 3, 3, 4, 5, 6, 7, 8};

    SECTION("stl")
    {
        std::sort(begin(v), begin(v) + 4);
        std::sort(begin(v) + 4, end(v));
        std::inplace_merge(begin(v), begin(v) + 4, end(v));
        CHECK(equal(v, result));
    }
}

TEST_CASE("067 make_heap")
{
    auto v = std::vector{3, 1, 4, 1, 5, 9};
    constexpr auto result = std::array{9, 5, 4, 1, 1, 3};

    SECTION("stl")
    {
        std::make_heap(begin(v), end(v));
        CHECK(equal(v, result));
    }
}

TEST_CASE("071 sort_heap")
{
    auto v = std::vector{3, 1, 4, 1, 5, 9};
    constexpr auto result = std::array{1, 1, 3, 4, 5, 9};

    SECTION("stl")
    {
        std::make_heap(begin(v), end(v));
        std::sort_heap(begin(v), end(v));
        CHECK(equal(v, result));
    }
}

TEST_CASE("072 push_heap")
{
    auto v = std::vector{9, 5, 4, 1, 1, 3};
    constexpr auto result = std::array{9, 5, 6, 1, 1, 3, 4};

    SECTION("stl")
    {
        v.push_back(6);
        std::push_heap(begin(v), end(v));
        CHECK(equal(v, result));
    }
}

TEST_CASE("073 pop_heap")
{
    auto v = std::vector{9, 5, 4, 1, 1, 3};
    constexpr auto result = std::array{5, 3, 4, 1, 1, 9};

    SECTION("stl")
    {
        std::pop_heap(begin(v), end(v));
        CHECK(equal(v, result));
    }
}
