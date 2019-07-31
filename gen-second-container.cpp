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

TEST_CASE("019 copy_n")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};
    auto dest = std::vector<int>{};

    SECTION("stl")
    {
        std::copy_n(begin(arr), 3, std::back_inserter(dest));
        constexpr auto result = std::array{0, 1, 2};
        CHECK(std::equal(begin(dest), end(dest), begin(result), end(result)));
    }
}

TEST_CASE("020 copy_backward")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};
    auto dest = std::vector<int>(arr.size());

    SECTION("stl")
    {
        std::copy_backward(begin(arr), end(arr), end(dest));
        CHECK(std::equal(begin(arr), end(arr), begin(dest), end(dest)));
    }
}

TEST_CASE("021 move")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};
    auto dest = std::vector<int>{};

    SECTION("stl")
    {
        std::move(begin(arr), end(arr), std::back_inserter(dest));
        CHECK(std::equal(begin(arr), end(arr), begin(dest), end(dest)));
    }
}

TEST_CASE("022 move_backward")
{
    constexpr auto arr = std::array{0, 1, 2, 3, 4, 5};
    auto dest = std::vector<int>(arr.size());

    SECTION("stl")
    {
        std::move_backward(begin(arr), end(arr), end(dest));
        CHECK(std::equal(begin(arr), end(arr), begin(dest), end(dest)));
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
        CHECK(std::equal(begin(result), end(result), begin(dest), end(dest)));
    }
}

TEST_CASE("024 generate")
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

TEST_CASE("025 generate_n")
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
