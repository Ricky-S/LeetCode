# [231. Power of Two](https://leetcode.com/problems/power-of-two/description/?envType=daily-question&envId=2024-02-19)

## Description

Given an integer `n`, return `true` if it is a power of two. Otherwise, return `false`.

An integer `n` is a power of two, if there exists an integer `x` such that `n == 2^x`.

**Example 1:**

```
Input: n = 1
Output: true
Explanation: 2^0 = 1
```

**Example 2:**

```
Input: n = 16
Output: true
Explanation: 2^4 = 16
```

**Example 3:**

```
Input: n = 3
Output: false
```

## Constraints

- `-2^31 <= n <= 2^31 - 1`

## Solution

```python
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and (n & (n - 1)) == 0
```

```python
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 1:
            return True
        elif n <= 0:
            return False
        else:
            while n > 1:
                if n % 2 != 0:
                    return False
                n = n/2
        return True     
```

```python
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        dic = set()
        for i in range(31):
            dic.add(2**i)
        if n in dic:
            return True
        else:
            return False
```