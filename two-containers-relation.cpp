#include <algorithm>
#include <array>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("008 mismatch")
{
    const auto s1 = std::string{"hello world"};
    const auto s2 = std::string{"hello World"};

    SECTION("stl")
    {
        auto [i, j] = std::mismatch(begin(s1), end(s1), begin(s2));
        CHECK(std::distance(s1.begin(), i) == std::distance(s2.begin(), j));
        CHECK(*j == 'W');
    }

    SECTION("my")
    {
        auto [i, j] = my_mismatch(begin(s1), end(s1), begin(s2));
        CHECK(std::distance(s1.begin(), i) == std::distance(s2.begin(), j));
        CHECK(*j == 'W');
    }
}

TEST_CASE("008 mismatch with func")
{
    const auto s1 = std::string{"hello worod"};
    const auto s2 = std::string{"hello World"};

    SECTION("stl")
    {
        auto [i, j] = std::mismatch(begin(s1), end(s1), begin(s2), icase_compare);
        CHECK(std::distance(s1.begin(), i) == std::distance(s2.begin(), j));
        CHECK(*i == 'o');
    }

    SECTION("my")
    {
        auto [i, j] = my_mismatch(begin(s1), end(s1), begin(s2), icase_compare);
        CHECK(std::distance(s1.begin(), i) == std::distance(s2.begin(), j));
        CHECK(*i == 'o');
    }
}
