#include <algorithm>
#include <array>
#include <functional>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
#include <boost/sort/spreadsort/spreadsort.hpp>
#include <boost/algorithm/sort_subrange.hpp>
#include <boost/algorithm/is_partitioned_until.hpp>
#include <boost/algorithm/searching/knuth_morris_pratt.hpp>
#include <boost/algorithm/searching/boyer_moore.hpp>
#include <boost/algorithm/searching/boyer_moore_horspool.hpp>
#include <boost/algorithm/gather.hpp>
#include <boost/algorithm/cxx11/one_of.hpp>
#include <boost/algorithm/is_palindrome.hpp>
#include <boost/algorithm/clamp.hpp>

namespace {
template<typename C>
void print_container(const C &c, const std::string &tag = "")
{
    std::cout << std::setw(30) << tag << ": ";
    std::copy(cbegin(c), cend(c), std::ostream_iterator<typename C::value_type>(std::cout, " "));
    std::cout << std::endl;
}
}

int main()
{
    auto d = std::vector{3, 5, 1, 9, 0, 8, 2, 4, 6, 8};

    auto print = [&d](const std::string &tag) { print_container(d, tag); };
    auto print_func = [](auto... ss) {
        for (auto s : {ss...}) {
            std::cout << std::setw(30) << s << std::endl;
        }
    };
    print("original");

    // heap
    std::make_heap(begin(d), end(d));
    print("make_heap");
    print("is_heap: " + std::to_string(is_heap(d.begin(), d.end())));
    print("is_heap_until end " + std::to_string(is_heap_until(d.begin(), d.end()) == d.end()));

    d.push_back(7);
    push_heap(begin(d), end(d));
    print("push_heap 7");

    pop_heap(begin(d), end(d));
    d.pop_back();
    print("pop_heap, 9 is gone");

    sort_heap(d.begin(), d.end());
    print("sort_heap");

    // sort
    std::sort(d.begin(), d.end(), std::greater<>());
    print("sort by greater");

    partial_sort(d.begin(), d.begin() + 3, d.end());
    print("partial_sort 3 smallest");

    nth_element(d.begin(), d.begin() + 2, d.end());
    print("nth_element 2th smallest");

    shuffle(d.begin(), d.end(), std::mt19937(std::random_device()()));
    print("random_shuffle");

    sort(d.begin(), d.begin() + 5);
    sort(d.begin() + 5, d.end());
    inplace_merge(d.begin(), d.begin() + 5, d.end());
    print("inplace_merge");

    shuffle(d.begin(), d.end(), std::mt19937(std::random_device()()));
    boost::sort::spreadsort::spreadsort(begin(d), end(d));
    print("spreadsort");

    shuffle(d.begin(), d.end(), std::mt19937(std::random_device()()));
    boost::algorithm::sort_subrange(d.begin(), d.end(), d.begin() + 2, d.end() - 2);
    print("sort_subrange");

    shuffle(d.begin(), d.end(), std::mt19937(std::random_device()()));
    boost::algorithm::partition_subrange(d.begin(), d.end(), d.begin() + 2, d.end() - 2);
    print("partition_subrange");

    auto is_even = [](int i) { return i % 2 == 0; };

    // partition
    {
        auto n = partition(d.begin(), d.end(), is_even);
        print("partition even @" + std::to_string(distance(d.begin(), n)));

        auto m = partition_point(d.begin(), d.end(), is_even);
        print("partition_point get it: " + std::to_string(m == n));
    }

    // permutation
    rotate(d.begin(), d.begin() + 1, d.end());
    print("rotate 1st to left");
    rotate(d.rbegin(), d.rbegin() + 1, d.rend());
    print("rotate it back");

    {
        d = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        print("new sorted std::vector");
        auto i = 0;
        while (next_permutation(d.begin(), d.end())) {
            ++i;
        }
        print("next_permutation 10!-1(" + std::to_string(i) + ")times");
        prev_permutation(d.begin(), d.end());
        print("prev_permutation");

        print("is_permuation to self: "
              + std::to_string(is_permutation(d.begin(), d.end(), d.rbegin())));
    }

    reverse(d.begin(), d.end());
    print("reverse");

    shuffle(d.begin(), d.end(), std::mt19937(std::random_device()()));
    print("random_shuffle");

    stable_sort(d.begin(), d.end());
    print("stable_sort?");
    print("is_sorted " + std::to_string(is_sorted(d.begin(), d.end())));
    print("is_sorted_until end" + std::to_string(is_sorted_until(d.begin(), d.end()) == d.end()));

    stable_partition(d.begin(), d.end(), is_even);
    print("stable_partition?");
    print("is_partitioned " + std::to_string(is_partitioned(d.begin(), d.end(), is_even)));
    print("is_partitioned_until "
          + std::to_string(boost::algorithm::is_partitioned_until(d.begin(), d.end(), is_even)
                           == d.end()));

    {
        auto c = count(d.begin(), d.end(), 5);
        print("count 5: " + std::to_string(c));
    }

    {
        auto s = accumulate(d.begin() + 1, d.end(), 1, std::multiplies<>());
        print("accumulate by multiply: " + std::to_string(s));
    }

    print("reduce: not in stl");
    print("transform_reduce: not in stl");

    partial_sum(d.begin(), d.end(), d.begin());
    print("partion_sum");

    print("(transform)_(e|i)nclusive_scan: not in stl");

    {
        auto s = inner_product(d.begin(), d.end(), d.begin(), 0);
        print("inner_product: s" + std::to_string(s));
    }

    adjacent_difference(d.begin(), d.end(), d.begin());
    print("adjacent_difference");

    {
        auto v = std::vector<int>{};
        sample(d.begin(), d.end(), back_inserter(v), 5, std::mt19937{std::random_device{}()});
        print_container(v, "5 sample");
    }

    print("all_of even: " + std::to_string(all_of(d.begin(), d.end(), is_even)));
    print("any_of even: " + std::to_string(any_of(d.begin(), d.end(), is_even)));
    print("none_of even: " + std::to_string(none_of(d.begin(), d.end(), is_even)));
    print("one_of even: " + std::to_string(boost::algorithm::one_of(d.begin(), d.end(), is_even)));
    print_func("all_of_equal", "none_of_equal", "any_of_equal", "one_of_equal");

    print("is_palindrome: " + std::to_string(boost::algorithm::is_palindrome(d)));

    print("equal to self: " + std::to_string(equal(d.begin(), d.end(), d.begin())));
    print("lexicographic_compare to self: " + std::to_string(equal(d.begin(), d.end(), d.begin())));

    {
        auto v = d;
        v[3] += 1;
        auto [i, j] = mismatch(d.begin(), d.end(), v.begin());
        print("mismatch: " + std::to_string(*i) + " | " + std::to_string(*j));
    }

    {
        auto i = find(d.begin(), d.end(), 3);
        print("find 3 @" + std::to_string(distance(d.begin(), i)));
    }

    {
        auto i = adjacent_find(d.begin(), d.end());
        print("adjacent_find equal: " + std::to_string(i == d.end()));
    }

    {
        d = {0, 1, 2, 3, 3, 3, 4, 5, 6};
        auto [i, j] = equal_range(d.begin(), d.end(), 3);
        print("equal_range find " + std::to_string(distance(i, j)) + " 3s");
        print("lower_bound 3 at @" + std::to_string(*lower_bound(d.begin(), d.end(), 3)));
        print("upper_bound 3 at @" + std::to_string(*upper_bound(d.begin(), d.end(), 3)));
        print("clamp 3 between 1 and 2" + std::to_string(boost::algorithm::clamp(3, 1, 2)));
        boost::algorithm::clamp_range(begin(d), end(d), begin(d), 1, 2);
        print("clamp_range between 1 and 2");
    }

    {
        d = {0, 1, 2, 3, 4, 5, 6, 8, 9};
        print("binary_search 7: " + std::to_string(binary_search(d.begin(), d.end(), 7)));
    }

    {
        auto v = {2, 3, 4};
        print("search 2,3,4: @"
              + std::to_string(
                      distance(d.begin(), search(d.begin(), d.end(), v.begin(), v.end()))));
        print("find_end 2,3,4: @"
              + std::to_string(
                      distance(d.begin(), find_end(d.begin(), d.end(), v.begin(), v.end()))));
        shuffle(d.begin(), d.end(), std::mt19937(std::random_device()()));
        print("find_first 2,3,4: @"
              + std::to_string(
                      distance(d.begin(), find_first_of(d.begin(), d.end(), v.begin(), v.end()))));

        sort(d.begin(), d.end());
        auto [i, j] = boost::algorithm::knuth_morris_pratt_search(d, v);
        print("KMP search @" + std::to_string(distance(d.begin(), i)) + "-@"
              + std::to_string(distance(d.begin(), j)));

        auto [m, n] = boost::algorithm::boyer_moore_search(d, v);
        print("Boyer-Moore search @" + std::to_string(distance(d.begin(), m)) + "-@"
              + std::to_string(distance(d.begin(), n)));

        auto [k, p] = boost::algorithm::boyer_moore_horspool_search(d, v);
        print("Boyer-Moore-Horspool search @" + std::to_string(distance(d.begin(), k)) + "-@"
              + std::to_string(distance(d.begin(), p)));

        auto [q, r] = boost::algorithm::gather(begin(d), end(d), begin(d) + 5, is_even);
        print("gather @" + std::to_string(distance(d.begin(), q)) + "-@"
              + std::to_string(distance(d.begin(), r)));
    }

    {
        print("min_element: " + std::to_string(*min_element(d.begin(), d.end())));
        print("max_element: " + std::to_string(*max_element(d.begin(), d.end())));
        auto [i, j] = minmax_element(d.begin(), d.end());
        print("minmax_element: " + std::to_string(*i) + " " + std::to_string(*j));
    }

    {
        sort(d.begin(), d.end());
        print("sort");
        auto r = std::vector<int>{};
        auto f = std::vector<int>{1, 3, 4, 5, 7};
        print_container(f, "set operation with");
        set_difference(d.begin(), d.end(), f.begin(), f.end(), back_inserter(r));
        print_container(r, "set_difference");

        r.clear();
        set_intersection(d.begin(), d.end(), f.begin(), f.end(), back_inserter(r));
        print_container(r, "set_intersection");

        r.clear();
        set_union(d.begin(), d.end(), f.begin(), f.end(), back_inserter(r));
        print_container(r, "set_union");

        r.clear();
        set_symmetric_difference(d.begin(), d.end(), f.begin(), f.end(), back_inserter(r));
        print_container(r, "set_symmetric_difference");

        print("includes: " + std::to_string(includes(d.begin(), d.end(), f.begin(), f.end())));

        r.clear();
        merge(d.begin(), d.end(), f.begin(), f.end(), back_inserter(r));
        print_container(r, "merge: " + std::to_string(r.size()) + " elems");
    }

    {
        auto v = std::vector<int>{};
        move(d.begin(), d.end(), back_inserter(v));
        print("move");
        print_func("move_backwards", "copy_backwards", "remove_copy", "unique_copy", "reverse_copy",
                   "rotate_copy", "replace_copy", "partition_copy", "partial_sort_copy");
    }

    {
        d = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        auto v = std::vector(d.rbegin(), d.rend());
        swap_ranges(d.begin(), d.end(), v.begin());
        print("swap_ranges");
    }

    fill(d.begin(), d.end(), 42);
    print("fill with 42");
    generate(d.begin(), d.end(), [] { return 3; });
    print("generate with 3");
    iota(d.begin(), d.end(), 42);
    print("iota from 42");

    replace(d.begin(), d.end(), 42, 43);
    print("replace 42 with 43");

    {
        auto i = remove(d.begin(), d.end(), 43);
        print("remove elems begin @" + std::to_string(distance(d.begin(), i)));
        d = {1, 2, 3, 3, 3, 4, 3, 5, 6};
        auto j = unique(d.begin(), d.end());
        print("unique elems ends @" + std::to_string(distance(d.begin(), j)));
    }

    print_func("find_if", "find_if_not", "count_if", "remove_if", "remove_copy_if", "replace_if",
               "replace_copy_if", "copy_if");

    {
        d = {0, 1, 2, 3, 4, 5, 6};
        auto v = std::vector<int>{};
        transform(d.begin(), d.end(), back_inserter(v), [](auto i) { return i * i; });
        print("transform");

        transform(d.begin(), d.end(), v.begin(), d.begin(), [](auto i, auto j) { return i + j; });
        print("trasform 2d");
    }

    print_func("copy_n", "generate_n", "fill_n", "search_n", "for_each_n");
}
