#include <algorithm>
#include <array>
#include <vector>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("070 fill")
{
    auto v = std::vector<int>(10, 0);
    SECTION("stl")
    {
        std::fill(begin(v), end(v), 1);
        CHECK(std::all_of(begin(v), end(v), [](auto i) { return i == 1; }));
    }
}

TEST_CASE("024 fill_n")
{
    auto v = std::vector<int>(10, 0);
    SECTION("stl")
    {
        std::fill_n(begin(v), 4, 1);
        CHECK(std::all_of(begin(v), begin(v) + 4, [](auto i) { return i == 1; }));
        CHECK(std::all_of(begin(v) + 4, end(v), [](auto i) { return i == 0; }));
    }
}

TEST_CASE("025 generate")
{
    constexpr auto result = std::array{1, 2, 3, 4, 5};

    SECTION("stl")
    {
        auto n = 0;
        auto dest = std::vector<int>(result.size());
        std::generate(begin(dest), end(dest), [&n] { return ++n; });
        CHECK(equal(result, dest));
    }
}

TEST_CASE("026 generate_n")
{
    constexpr auto result = std::array{1, 2, 3, 4, 5};

    SECTION("stl")
    {
        auto n = 0;
        auto dest = std::vector<int>(result.size());
        std::generate_n(begin(dest), result.size(), [&n] { return ++n; });
        CHECK(equal(result, dest));
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

TEST_CASE("087 iota")
{
    auto v = std::vector<int>(4);
    constexpr auto result = std::array{5, 6, 7, 8};

    SECTION("stl")
    {
        std::iota(begin(v), end(v), 5);
        CHECK(equal(v, result));
    }
}
