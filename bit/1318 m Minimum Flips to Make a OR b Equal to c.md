# 1318. Minimum Flips to Make a OR b Equal to c
[Leetcode link](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/)

## Problem:

Given 3 positives numbers `a`, `b` and `c`. Return the minimum flips required in some bits of `a` and `b` to make ( `a` OR `b` == `c` ). (bitwise OR operation).

Flip operation consists of change **any** single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

**Example 1:**

```
Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
```

**Example 2:**

```
Input: a = 4, b = 2, c = 7
Output: 1
```

**Example 3:**

```

Input: a = 1, b = 2, c = 3
Output: 0
```

**Constraints:**

- `1 <= a <= 10^9`
- `1 <= b <= 10^9`
- `1 <= c <= 10^9`

Ideas:


Solution:

My code:

```cpp
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while (a || b || c) {
            if ((c & 1) == 1) {
                if(((a & 1) == 0) && ((b & 1) == 0)) count++;
            } else {
                if(((a & 1) != 0) || ((b & 1) != 0)) count = count + (a & 1) + (b & 1);
            }
            // cout << a << ", " <<  b << ", " << c << ", " << count <<endl;
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return count;
    }
};
```



```cpp
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            int bit_c = (c >> i) & 1;
            if (bit_c == 0) {
                res += bit_a + bit_b;
            } else {
                res += (bit_a + bit_b == 0);
            }
        }
        return res;
    }
};
```