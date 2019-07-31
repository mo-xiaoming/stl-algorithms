#include <algorithm>
#include <array>

#include <catch2/catch.hpp>

#include "my_stl.h"

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

TEST_CASE("006 for_each")
{
    auto arr = std::array{1, 2, 3, 4, 5, 4, 7};
    constexpr auto result = std::array{2, 3, 4, 5, 6, 5, 8};
    SECTION("stl")
    {
        std::for_each(begin(arr), end(arr), [](auto &i) { ++i; });
        CHECK(std::equal(begin(arr), end(arr), begin(result)));
    }

    SECTION("my")
    {
        my_for_each(begin(arr), end(arr), [](auto &i) { ++i; });
        CHECK(std::equal(begin(arr), end(arr), begin(result)));
    }
}

TEST_CASE("007 for_each_n")
{
    auto arr = std::array{1, 2, 3, 4, 5, 4, 7};
    constexpr auto result = std::array{2, 3, 4, 4, 5, 4, 7};
    SECTION("stl")
    {
        // could not get it build, because boost needs opencl for for_each_n?
        // boost::compute::for_each_n(begin(arr), 3, [](auto &i) { ++i; });
        // CHECK(std::equal(begin(arr), end(arr), begin(result)));
    }

    SECTION("my")
    {
        my_for_each_n(begin(arr), 3, [](auto &i) { ++i; });
        CHECK(std::equal(begin(arr), end(arr), begin(result)));
    }
}

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
