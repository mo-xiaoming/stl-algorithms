# stl-algorithms

Inspired by Jonathan Boccara's talk ["105 STL Algorithms in Less Than an Hour"](https://youtu.be/2olsGf6JIkU)

## 为非空容器填充值 (gen-container.cpp)

* `fill | fill_n` 填充固定值

* `generate | generate_n` 生成值

* `iota` 填充逐渐累加的值

## 根据第一个容器生成第二个容器 (gen-second-container.cpp)

* `replace_copy | replace_copy_if` 向第二个容器拷贝时，把所有满足条件的值替换成N 

* `remove_copy | remove_copy_if | copy | copy_if | copy_n` 向第二个容器拷贝时，(不)拷贝满足条件的值

* `copy_backward` 向第二个容器拷贝时，从‘后’向前拷贝，防止覆盖

* `move | move_backward` 拷贝换成移动

* `transform` 根据容器一的值，运算生成对应的容器二的值

* `partial_sort_copy` 根据第二个容器大小N，只拷贝排序后头N个值

* `reverse_copy` 拷贝反序

* `unique_copy` 参见`unique`

* `rotate_copy` 参见`rotate`

* `partition_copy` 参见`partition`

* `sample` 随机取N个值

## 根据两个容器内容生成第三个容器 (gen-third-container.cpp)

* `transform` 根据容器一二的值，运算生成对应的容器三的值

* `set_difference` A-B

* `set_union` A+B

* `set_intersection` 在A也在B

* `set_symmetric_difference` A+B再减去AB的交集

* `inner_product` 容器一的每个值和其对应的容器二的值‘相乘’，然后再用初始值‘相加’以上结果

## 改变自身 (modify-self.cpp)

* `remove | remove_if` 删除满足条件的值

* `replace | replace_if` 替换满足条件的值

* `reverse` 反序

* `unique` 相邻的等值合并成一个

## 自身值的排列组合 (permutation-self.cpp)

* `rotate` 从指定的点开始，到最后的所有值插入到容器最前面

* `shuffle` 乱序

* `next_permutation | prev_permutation` 根据字典序生成下/上一个排列组合的值，知道到达字典序排列位置，此时返回false

## 自身值的属性 (properties-of-elements.cpp)

* `count | count_if` 对满足条件的值计数

* `all_of | any_of | none_of` 是否所有/任何/没有值满足条件

* `is_partitioned` 是否被分区

* `is_sorted` 是否排序

* `is_heap` 是否是堆

## 查找一项 (search-one.cpp)

* `find | find_if | find_if_no` 返回第一个(不)满足条件的值

* `find_first_of` 返回第二个容器中任何一项在第一个容器中第一次出现的位置

* `binary_search` 二分查找

* `partition_point` 区间的拐点

* `is_sorted_until` 找到第一个乱序值

* `is_heap_until` 找到第一个非堆值

* `max | min | minmax | max_element | min_element | minmax_element` 需要介绍吗？

## 排序 (sort.cpp)

* `partition | stable_partition` 分区
 
* `sort | stable_sort` 大家都知道

* `partial_sort` 排序后头N个值放在前面

* `nth_element` 把第N个位置放上排序后对应的值

* `merge` 排序后的两个容器合并生成排序后的第三个容器

* `inplace_merge` 同一个容器内不同有序范围合并

* `make_heap` 做堆

* `sort_heap` 把堆排序

* `push_heap | pop_heap` 添/减堆值

## 两个容器的关系 (two-containers-relation.cpp)

* `mismatch` 查找两个容器中第一个不匹配值的位置

* `includes` 有序容器是否包含第二个有序容器

* `equal` 容器是否相等

* `lexicographical_compare` 按字典序是否相等

* `is_permutation` 第二个容器是否是第一个容器值的排列组合之一

## 查找距离 (search-range.cpp)

* `find_end` 查找模式在容器中出现的最后一次的起始位置

* `search` 查找模式在容器中出现的第一次的起始位置

* `search_n` 查找值M连续出现N次的位置，相当于`search`连续N个M

* `lower_bound | upper_bound` 返回指定范围

* `equal_range` 返回连续出现的某值的起始和结束位置

## 相邻关系 (adjacent.cpp)

* `adjacent_find` 寻找第一段相邻‘相等’的数据段，返回数据段开头

* `accumulate` 相邻数据统统‘相加’，返回总结果

* `adjacent_difference` 从第‘二’个数据开始，和前面的项目‘相减’

* `partial_sum` 每个值都和前面所有值（包含）‘累加’

## 其它

* `for_each | for_each_n` 需要介绍吗？

* `iter_swap` 交换两个iter指向的值

* `swap_ranges` 交换两个范围内的所有值

* `clamp` 将给予的值N限制在区间内

