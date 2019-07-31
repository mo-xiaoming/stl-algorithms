#include <algorithm>
#include <array>
#include <vector>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("023 fill")
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
        CHECK(std::equal(begin(result), end(result), begin(dest), end(dest)));
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
        CHECK(std::equal(begin(result), end(result), begin(dest), end(dest)));
    }
}
