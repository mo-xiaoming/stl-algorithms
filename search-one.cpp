#include <algorithm>
#include <array>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("009 find")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};

    SECTION("stl")
    {
        CHECK(std::find(begin(arr), end(arr), 3) == (begin(arr) + 3));
        CHECK(std::find(begin(arr), end(arr), 7) == end(arr));
    }

    SECTION("my")
    {
        CHECK(my_find(begin(arr), end(arr), 3) == (begin(arr) + 3));
        CHECK(my_find(begin(arr), end(arr), 7) == end(arr));
    }
}

TEST_CASE("010 find_if")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};

    SECTION("stl")
    {
        CHECK(std::find_if(begin(arr), end(arr), [](auto i) { return i + 1 >= 4; })
              == (begin(arr) + 3));
        CHECK(std::find_if(begin(arr), end(arr), [](auto i) { return i + 1 >= 10; }) == end(arr));
    }

    SECTION("my")
    {
        CHECK(my_find_if(begin(arr), end(arr), [](auto i) { return i + 1 >= 4; })
              == (begin(arr) + 3));
        CHECK(my_find_if(begin(arr), end(arr), [](auto i) { return i + 1 >= 10; }) == end(arr));
    }
}

TEST_CASE("011 find_if_no")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};

    SECTION("stl")
    {
        CHECK(std::find_if_not(begin(arr), end(arr), [](auto i) { return i + 1 < 4; })
              == (begin(arr) + 3));
        CHECK(std::find_if_not(begin(arr), end(arr), [](auto i) { return i + 1 < 10; })
              == end(arr));
    }

    SECTION("my")
    {
        CHECK(my_find_if_not(begin(arr), end(arr), [](auto i) { return i + 1 < 4; })
              == (begin(arr) + 3));
        CHECK(my_find_if_not(begin(arr), end(arr), [](auto i) { return i + 1 < 10; }) == end(arr));
    }
}

TEST_CASE("013 find_first_of")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5, 6};
    constexpr auto pat = std::array{5, 4, 2};

    SECTION("stl")
    {
        CHECK(std::find_first_of(begin(arr), end(arr), begin(pat), end(pat)) == (begin(arr) + 2));
    }
}

TEST_CASE("013 find_first_of with func")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5, 6};
    constexpr auto pat = std::array{5, 4, 2};

    SECTION("stl")
    {
        CHECK(std::find_first_of(begin(arr), end(arr), begin(pat), end(pat),
                                 [](auto i, auto j) { return i + 1 == j; })
              == (begin(arr) + 1));
    }
}

TEST_CASE("049 partition_point")
{
    constexpr auto arr = std::array{0, 2, 4, 1, 2, 3};

    SECTION("stl")
    {
        CHECK(std::partition_point(begin(arr), end(arr), is_even<int>) == begin(arr) + 3);
    }
}

TEST_CASE("056 lower_bound")
{
    constexpr auto arr = std::array{0, 2, 4, 6, 8};

    SECTION("stl")
    {
        CHECK(*std::lower_bound(begin(arr), end(arr), 5, std::less<int>()) == 6);
        CHECK(*std::lower_bound(begin(arr), end(arr), 6, std::less<int>()) == 6);
        CHECK(std::lower_bound(begin(arr), end(arr), 9, std::less<int>()) == end(arr));
    }
}

TEST_CASE("057 upper_bound")
{
    constexpr auto arr = std::array{0, 2, 4, 6, 8};

    SECTION("stl")
    {
        CHECK(*std::upper_bound(begin(arr), end(arr), 5, std::less<int>()) == 6);
        CHECK(*std::upper_bound(begin(arr), end(arr), 6, std::less<int>()) == 8);
        CHECK(std::upper_bound(begin(arr), end(arr), 9, std::less<int>()) == end(arr));
    }
}

TEST_CASE("058 binary_search")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5, 6};

    SECTION("stl")
    {
        CHECK(std::binary_search(begin(arr), end(arr), 3));
        CHECK(std::binary_search(begin(arr), end(arr), 7) == false);
    }
}

TEST_CASE("055 is_sorted_until")
{
    constexpr auto arr = std::array{6, 5, 4, 7, 2, 3};

    SECTION("stl")
    {
        CHECK(std::is_sorted_until(begin(arr), end(arr), std::greater<int>()) == begin(arr) + 3);
    }
}

TEST_CASE("069 is_heap_until")
{
    constexpr auto arr = std::array{9, 5, 4, 8, 1, 3};

    SECTION("stl") { CHECK(std::is_heap_until(begin(arr), end(arr)) == begin(arr) + 3); }
}

TEST_CASE("074 max")
{
    SECTION("stl") { CHECK(std::max({9, 5, 4, 8, 6}) == 9); }
}

TEST_CASE("075 min")
{
    SECTION("stl") { CHECK(std::min({9, 5, 4, 8, 6}) == 4); }
}

TEST_CASE("076 max_element")
{
    constexpr auto arr = std::array{9, 5, 4, 8};

    SECTION("stl") { CHECK(*std::max_element(begin(arr), end(arr)) == 9); }
}

TEST_CASE("077 min_element")
{
    constexpr auto arr = std::array{9, 5, 4, 8};

    SECTION("stl") { CHECK(*std::min_element(begin(arr), end(arr)) == 4); }
}

TEST_CASE("078 minmax_element")
{
    constexpr auto arr = std::array{9, 5, 4, 8};

    SECTION("stl")
    {
        const auto [i, j] = std::minmax_element(begin(arr), end(arr));
        CHECK(*i == 4);
        CHECK(*j == 9);
    }
}

TEST_CASE("079 minmax")
{
    SECTION("stl")
    {
        const auto [i, j] = std::minmax({9, 5, 4, 8});
        CHECK(i == 4);
        CHECK(j == 9);
    }
}
