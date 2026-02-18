# [693. Binary Number with Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/description/?envType=daily-question&envId=2026-02-18)

## Description

Given a positive integer `n`, return `true` if the binary representation of `n` has alternating bits, or `false` otherwise.

Alternating bits means that two adjacent bits in the binary representation of `n` are never the same.

**Example 1:**

```
Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101
```

**Example 2:**

```
Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111
```

**Example 3:**

```
Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011
```

**Constraints:**

- `1 <= n <= 2^31 - 1`

## Solution

```python
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        temp = str(bin(n))

        for i in range(len(temp)-1):
            if temp[i] == temp[i+1]:
                return False
        return True
```

