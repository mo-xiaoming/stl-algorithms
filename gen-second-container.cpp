#include <algorithm>
#include <array>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("033 replace_copy")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};
    constexpr auto result = std::array{0, 1, 7, 3, 4, 5};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::replace_copy(begin(arr), end(arr), std::back_inserter(dest), 2, 7);
        CHECK(equal(result, dest));
    }
}

TEST_CASE("034 replace_copy_if")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};
    constexpr auto result = std::array{7, 1, 7, 3, 7, 5};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::replace_copy_if(begin(arr), end(arr), std::back_inserter(dest), is_even<int>, 7);
        CHECK(equal(result, dest));
    }
}

TEST_CASE("029 remove_copy")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};
    constexpr auto result = std::array{0, 1, 3, 4, 5};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::remove_copy(begin(arr), end(arr), std::back_inserter(dest), 2);
        CHECK(equal(result, dest));
    }
}

TEST_CASE("030 remove_copy_if")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};
    constexpr auto result = std::array{1, 3, 5};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::remove_copy_if(begin(arr), end(arr), std::back_inserter(dest), is_even<int>);
        CHECK(equal(result, dest));
    }
}

TEST_CASE("017 copy")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::copy(begin(arr), end(arr), std::back_inserter(dest));
        CHECK(equal(arr, dest));
    }
}

TEST_CASE("018 copy_if")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};
    constexpr auto result = std::array{0, 2, 4};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::copy_if(begin(arr), end(arr), std::back_inserter(dest), is_even<int>);
        CHECK(equal(result, dest));
    }
}

TEST_CASE("019 copy_n")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};
    constexpr auto result = std::array{0, 1, 2};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::copy_n(begin(arr), 3, std::back_inserter(dest));
        CHECK(equal(result, dest));
    }
}

TEST_CASE("020 copy_backward")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};

    SECTION("stl")
    {
        auto dest = std::vector<int>(arr.size());
        std::copy_backward(begin(arr), end(arr), end(dest));
        CHECK(equal(arr, dest));
    }
}

TEST_CASE("021 move")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::move(begin(arr), end(arr), std::back_inserter(dest));
        CHECK(equal(arr, dest));
    }
}

TEST_CASE("022 move_backward")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};

    SECTION("stl")
    {
        auto dest = std::vector<int>(arr.size());
        std::move_backward(begin(arr), end(arr), end(dest));
        CHECK(equal(arr, dest));
    }
}

TEST_CASE("023 transform with one input")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};
    constexpr auto result = std::array{0, 1, 4, 9, 16, 25};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::transform(begin(arr), end(arr), std::back_inserter(dest),
                       [](auto i) { return i * i; });
        CHECK(equal(result, dest));
    }
}

TEST_CASE("052 partial_sort_copy")
{
    constexpr auto arr = std::array{1, 2, 3, 4, 5};
    constexpr auto result = std::array{5, 4, 3, 2};

    SECTION("stl")
    {
        auto v = std::vector{11, 12, 33, 44};
        std::partial_sort_copy(begin(arr), end(arr), begin(v), end(v), std::greater<int>());
        CHECK(equal(result, v));
    }
}
