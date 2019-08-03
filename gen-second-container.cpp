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

TEST_CASE("039 reverse_copy")
{
    constexpr auto arr = std::array{1, 2, 3, 4};
    constexpr auto result = std::array{4, 3, 2, 1};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::reverse_copy(begin(arr), end(arr), std::back_inserter(dest));
        CHECK(equal(result, dest));
    }
}

TEST_CASE("044 unique_copy")
{
    auto v = std::vector{1, 2, 2, 3, 2};
    constexpr auto result = std::array{1, 2, 3, 2};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::unique_copy(begin(v), end(v), std::back_inserter(dest));
        CHECK(equal(dest, result));
    }
}

TEST_CASE("040 rotate_copy")
{
    auto v = std::vector{1, 2, 3, 4, 5};
    constexpr auto result = std::array{3, 4, 5, 1, 2};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::rotate_copy(begin(v), begin(v) + 2, end(v), std::back_inserter(dest));
        CHECK(equal(dest, result));
    }
}

TEST_CASE("042 sample")
{
    auto v = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::sample(begin(v), end(v), std::back_inserter(dest), 7,
                    std::mt19937{std::random_device{}()});
        CHECK(dest.size() == 7);
        std::sort(begin(v), end(v));
        std::sort(begin(dest), end(dest));
        CHECK(std::includes(begin(v), end(v), begin(dest), end(dest)));
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
