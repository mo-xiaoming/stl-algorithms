#include <algorithm>
#include <array>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

constexpr auto Empty_Array = std::array<int, 0>{};

TEST_CASE("001 count")
{
    constexpr auto arr = std::array{1, 2, 3, 4, 5, 4, 7};

    SECTION("stl")
    {
        CHECK(std::count(begin(arr), end(arr), 4) == 2);
        CHECK(std::count(begin(arr), end(arr), 3) == 1);
        CHECK(std::count(begin(arr), end(arr), 0) == 0);
    }

    SECTION("my")
    {
        CHECK(my_count(begin(arr), end(arr), 4) == 2);
        CHECK(my_count(begin(arr), end(arr), 3) == 1);
        CHECK(my_count(begin(arr), end(arr), 0) == 0);
    }
}

TEST_CASE("002 count_if")
{
    constexpr auto arr = std::array{1, 2, 3, 4, 5, 4, 7};

    SECTION("stl") { CHECK(std::count_if(begin(arr), end(arr), is_even<int>) == 3); }

    SECTION("my") { CHECK(my_count_if(begin(arr), end(arr), is_even<int>) == 3); }
}

TEST_CASE("003 all_of")
{
    constexpr auto arr = std::array{1, 2, 3, 4, 5, 4, 7};

    SECTION("stl")
    {
        CHECK(std::all_of(begin(arr), end(arr), [](auto i) { return i < 10; }));
        CHECK(std::all_of(begin(arr), end(arr), [](auto i) { return i < 5; }) == false);
    }

    SECTION("my")
    {
        CHECK(my_all_of(begin(arr), end(arr), [](auto i) { return i < 10; }));
        CHECK(my_all_of(begin(arr), end(arr), [](auto i) { return i < 5; }) == false);
    }
}

TEST_CASE("003 all_of: true if range is empty")
{
    SECTION("stl")
    {
        CHECK(std::all_of(begin(Empty_Array), end(Empty_Array), [](auto) { return false; }));
    }

    SECTION("my")
    {
        CHECK(my_all_of(begin(Empty_Array), end(Empty_Array), [](auto) { return false; }));
    }
}

TEST_CASE("004 any_of")
{
    constexpr auto arr = std::array{1, 2, 3, 4, 5, 4, 7};

    SECTION("stl")
    {
        CHECK(std::any_of(begin(arr), end(arr), [](auto i) { return i < 3; }));
        CHECK(std::any_of(begin(arr), end(arr), [](auto i) { return i > 15; }) == false);
    }

    SECTION("my")
    {
        CHECK(my_any_of(begin(arr), end(arr), [](auto i) { return i < 3; }));
        CHECK(my_any_of(begin(arr), end(arr), [](auto i) { return i > 15; }) == false);
    }
}

TEST_CASE("004 any_of: false if range is empty")
{
    SECTION("stl")
    {
        CHECK(std::any_of(begin(Empty_Array), end(Empty_Array), [](auto) { return true; })
              == false);
    }

    SECTION("my")
    {
        CHECK(my_any_of(begin(Empty_Array), end(Empty_Array), [](auto) { return true; }) == false);
    }
}

TEST_CASE("005 none_of")
{
    constexpr auto arr = std::array{1, 2, 3, 4, 5, 4, 7};

    SECTION("stl")
    {
        CHECK(std::none_of(begin(arr), end(arr), [](auto i) { return i > 10; }));
        CHECK(std::none_of(begin(arr), end(arr), [](auto i) { return i > 5; }) == false);
    }

    SECTION("my")
    {
        CHECK(my_none_of(begin(arr), end(arr), [](auto i) { return i > 10; }));
        CHECK(my_none_of(begin(arr), end(arr), [](auto i) { return i > 5; }) == false);
    }
}

TEST_CASE("005 none_of: true if range is empty")
{
    SECTION("stl")
    {
        CHECK(std::none_of(begin(Empty_Array), end(Empty_Array), [](auto) { return false; }));
    }

    SECTION("my")
    {
        CHECK(my_none_of(begin(Empty_Array), end(Empty_Array), [](auto) { return false; }));
    }
}

TEST_CASE("047 is_partitioned")
{
    constexpr auto a = std::array{0, 2, 4, 1, 3, 5};
    constexpr auto b = std::array{0, 1, 2, 3, 4, 5};

    SECTION("stl")
    {
        CHECK(std::is_partitioned(begin(a), end(a), is_even<int>));
        CHECK(std::is_partitioned(begin(b), end(b), is_even<int>) == false);
    }
}

TEST_CASE("050 is_sorted")
{
    constexpr auto a = std::array{4, 3, 2, 1};
    constexpr auto b = std::array{1, 2, 3, 4};

    SECTION("stl")
    {
        CHECK(std::is_sorted(begin(a), end(a), std::greater<int>()));
        CHECK(std::is_sorted(begin(b), end(b), std::greater<int>()) == false);
    }
}
