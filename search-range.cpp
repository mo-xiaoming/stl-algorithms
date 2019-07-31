#include <algorithm>
#include <array>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("012 find_end")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 1, 2, 3, 4};
    constexpr auto pat = std::array{1, 2, 3};
    constexpr auto pat1 = std::array{4, 5, 6};

    SECTION("stl")
    {
        CHECK(std::find_end(begin(arr), end(arr), begin(pat), end(pat)) == (begin(arr) + 5));
        CHECK(std::find_end(begin(arr), end(arr), begin(pat1), end(pat1)) == end(arr));
    }
}

TEST_CASE("012 find_end with func")
{
    const auto s = std::string{"abcefghabcd"};
    const auto p1 = std::string{"abc"};
    const auto p2 = std::string{"ABC"};

    SECTION("stl")
    {
        CHECK(std::find_end(begin(s), end(s), begin(p1), end(p1), icase_compare) == (end(s) - 4));
        CHECK(std::find_end(begin(s), end(s), begin(p2), end(p2), icase_compare) == (end(s) - 4));
    }
}

TEST_CASE("015 search")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 1, 2, 3, 4};
    constexpr auto pat = std::array{1, 2, 3};
    constexpr auto pat1 = std::array{4, 5, 6};

    SECTION("stl")
    {
        CHECK(std::search(begin(arr), end(arr), begin(pat), end(pat)) == (begin(arr) + 1));
        CHECK(std::search(begin(arr), end(arr), begin(pat1), end(pat1)) == end(arr));
    }
}

TEST_CASE("015 search with func")
{
    const auto s = std::string{"abcefghabcd"};
    const auto p1 = std::string{"bce"};
    const auto p2 = std::string{"BCE"};

    SECTION("stl")
    {
        CHECK(std::search(begin(s), end(s), begin(p1), end(p1), icase_compare) == (begin(s) + 1));
        CHECK(std::search(begin(s), end(s), begin(p2), end(p2), icase_compare) == (begin(s) + 1));
    }
}

TEST_CASE("015 search with searcher")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 1, 2, 3, 4};
    constexpr auto pat = std::array{1, 2, 3};
    constexpr auto pat1 = std::array{4, 5, 6};

    SECTION("stl")
    {
        CHECK(std::search(begin(arr), end(arr), std::boyer_moore_searcher(begin(pat), end(pat)))
              == (begin(arr) + 1));
        CHECK(std::search(begin(arr), end(arr), std::boyer_moore_searcher(begin(pat1), end(pat1)))
              == end(arr));

        CHECK(std::search(begin(arr), end(arr),
                          std::boyer_moore_horspool_searcher(begin(pat), end(pat)))
              == (begin(arr) + 1));
        CHECK(std::search(begin(arr), end(arr),
                          std::boyer_moore_horspool_searcher(begin(pat1), end(pat1)))
              == end(arr));
    }
}

TEST_CASE("016 search_n")
{
    constexpr auto arr = std::array{0, 1, 2, 2, 3, 2, 2, 2, 4};

    SECTION("stl") { CHECK(std::search_n(begin(arr), end(arr), 3, 2) == (begin(arr) + 5)); }
}

TEST_CASE("016 search_n with func")
{
    constexpr auto arr = std::array{0, 1, 2, 2, 3, 2, 2, 2, 4};

    SECTION("stl")
    {
        CHECK(std::search_n(begin(arr), end(arr), 7, 2,
                            [](auto i, auto j) { return std::abs(i - j) <= 1; })
              == (begin(arr) + 1));
    }
}
