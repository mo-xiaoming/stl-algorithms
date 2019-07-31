#pragma once

#include <cctype>
#include <utility>

template<typename I>
inline bool is_even(I i)
{
    return i % 2 == 0;
}

inline bool icase_compare(char i, char j)
{
    return std::toupper(i) == std::toupper(j);
}

inline void inc_self(int &t)
{
    ++t;
}

template<typename It, typename V>
constexpr auto my_count(It begin, It end, const V &v)
{
    auto ret = 0;
    for (; begin != end; ++begin) {
        if (*begin == v)
            ++ret;
    }
    return ret;
}

template<typename It, typename Pre>
constexpr auto my_count_if(It begin, It end, Pre p)
{
    auto ret = 0;
    for (; begin != end; ++begin) {
        if (p(*begin))
            ++ret;
    }
    return ret;
}

template<typename It, typename F>
constexpr bool my_all_of(It begin, It end, F f)
{
    for (; begin != end; ++begin) {
        if (!f(*begin))
            return false;
    }
    return true;
}

template<typename It, typename F>
constexpr bool my_any_of(It begin, It end, F f)
{
    for (; begin != end; ++begin) {
        if (f(*begin))
            return true;
    }
    return false;
}

template<typename It, typename F>
constexpr bool my_none_of(It begin, It end, F f)
{
    for (; begin != end; ++begin) {
        if (f(*begin))
            return false;
    }
    return true;
}

template<typename It, typename F>
constexpr void my_for_each(It begin, It end, F f)
{
    for (; begin != end; ++begin) {
        f(*begin);
    }
}

template<typename It, typename S, typename F>
constexpr void my_for_each_n(It begin, S s, F f)
{
    for (; s > 0; --s, ++begin) {
        f(*begin);
    }
}

template<typename It1, typename It2>
constexpr auto my_mismatch(It1 begin1, It1 end1, It2 begin2)
{
    for (; *begin1 == *begin2 && begin1 != end1; ++begin1, ++begin2)
        ;
    return std::make_pair(begin1, begin2);
}

template<typename It1, typename It2, typename F>
constexpr auto my_mismatch(It1 begin1, It1 end1, It2 begin2, F f)
{
    for (; f(*begin1, *begin2) && begin1 != end1; ++begin1, ++begin2)
        ;
    return std::make_pair(begin1, begin2);
}

template<typename It, typename V>
constexpr auto my_find(It begin, It end, const V &v)
{
    for (; begin != end; ++begin) {
        if (*begin == v)
            break;
    }
    return begin;
}

template<typename It, typename F>
constexpr auto my_find_if(It begin, It end, F f)
{
    for (; begin != end; ++begin) {
        if (f(*begin))
            break;
    }
    return begin;
}

template<typename It, typename F>
constexpr auto my_find_if_not(It begin, It end, F f)
{
    for (; begin != end; ++begin) {
        if (!f(*begin))
            break;
    }
    return begin;
}
