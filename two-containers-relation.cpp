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

TEST_CASE("062 includes")
{
    constexpr auto a = std::array{0, 1, 2, 3, 4, 5};
    constexpr auto b = std::array{1, 2, 3};

    SECTION("stl") { CHECK(std::includes(begin(a), end(a), begin(b), end(b))); }
}

TEST_CASE("081 equal")
{
    constexpr auto a = std::array{0, 1, 2, 3, 4, 5};
    constexpr auto b = std::array{1, 2, 3};

    SECTION("stl")
    {
        CHECK(std::equal(begin(a), end(a), begin(a), end(a)));
        CHECK(std::equal(begin(a), end(a), begin(b), end(b)) == false);
    }
}

TEST_CASE("082 lexicographical_equal")
{
    constexpr auto a = std::array{3, 4, 5, 6};
    constexpr auto b = std::array{4, 0, 0, 0};

    SECTION("stl") { CHECK(std::lexicographical_compare(begin(a), end(a), begin(b), end(b))); }
}
