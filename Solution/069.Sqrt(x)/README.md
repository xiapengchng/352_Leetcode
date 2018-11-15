Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
<<<<<<< HEAD
solution3.cpp
采用二分查找，待查找元素v，返回数组中大于或等于v元素的最小的一个，若v=4,16,25等可以开方的数，那么返回值为2,4,5等；若v=5,6,7，返回值为3，因为3是大于或等于v的元素中最小的，但5的开方下取整为2，所以最终返回值应为3-1=2.
更一般来说，若返回值^2==v，则直接返回，否则减1后再返回
idea:
1.binary search
2.netwon method
3.recursive
>>>>>>> upstream/master
