#include <algorithm>
#include <array>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("017 copy")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};
    auto dest = std::vector<int>{};

    SECTION("stl")
    {
        std::copy(begin(arr), end(arr), std::back_inserter(dest));
        CHECK(std::equal(begin(arr), end(arr), begin(dest), end(dest)));
    }
}

TEST_CASE("018 copy_if")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};
    auto dest = std::vector<int>{};

    SECTION("stl")
    {
        std::copy_if(begin(arr), end(arr), std::back_inserter(dest), is_even<int>);
        constexpr auto result = std::array{0, 2, 4};
        CHECK(std::equal(begin(dest), end(dest), begin(result), end(result)));
    }
}
