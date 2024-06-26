# [1137. N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=daily-question&envId=2024-04-24)

## Description

The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn = Tn-1 + Tn-2 + Tn-3 for n > 2.

Given n, return the value of Tn.

### Example 1:

```
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
```

### Example 2:

```
Input: n = 25
Output: 1389537
```

### Constraints:

* 0 <= n <= 37
* The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

## Solution

```python
class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        a, b, c = 0, 1, 1
        for i in range(3, n+1):
            a, b, c = b, c, a+b+c
        return c
```

```cpp
