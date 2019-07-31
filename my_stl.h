#pragma once

#include <cctype>

template<typename I>
inline bool is_even(I i)
{
    return i % 2 == 0;
}

bool icase_compare(char i, char j)
{
    return std::toupper(i) == std::toupper(j);
}
