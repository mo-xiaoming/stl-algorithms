#include <algorithm>
#include <array>
#include <functional>

#include <catch2/catch.hpp>

#include "my_algorithm.h"

TEST_CASE("039 rotate")
{
    auto v = std::vector{1, 2, 3, 4, 5};
    constexpr auto result = std::array{3, 4, 5, 1, 2};

    SECTION("stl")
    {
        std::rotate(begin(v), begin(v) + 2, end(v));
        CHECK(std::equal(begin(v), end(v), begin(result), end(result)));
    }
}

TEST_CASE("040 rotate_copy")
{
    auto v = std::vector{1, 2, 3, 4, 5};
    constexpr auto result = std::array{3, 4, 5, 1, 2};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::rotate_copy(begin(v), begin(v) + 2, end(v), std::back_inserter(dest));
        CHECK(std::equal(begin(dest), end(dest), begin(result), end(result)));
    }
}

TEST_CASE("041 shuffle")
{
    auto v = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7};

    SECTION("stl")
    {
        std::shuffle(begin(v), end(v), std::mt19937{std::random_device{}()});
        SUCCEED();
    }
}

TEST_CASE("042 sample")
{
    auto v = std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7};

    SECTION("stl")
    {
        auto dest = std::vector<int>{};
        std::sample(begin(v), end(v), std::back_inserter(dest), 7,
                    std::mt19937{std::random_device{}()});
        CHECK(dest.size() == 7);
        std::sort(begin(v), end(v));
        std::sort(begin(dest), end(dest));
        CHECK(std::includes(begin(v), end(v), begin(dest), end(dest)));
    }
}
