# [633. Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/description/?envType=daily-question&envId=2024-06-17)

## Description

Given a non-negative integer `c`, decide whether there're two integers `a` and `b` such that `a2 + b2 = c`.

**Example 1:**

```
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

```

**Example 2:**

```
Input: c = 3
Output: false

```

**Constraints:**

- `0 <= c <= 231 - 1`

## Solution

```python
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        left, right = 0, int(c ** 0.5)
        while left <= right:
            cur = left * left + right * right
            if cur == c:
                return True
            elif cur < c:
                left += 1
            else:
                right -= 1
        return False
```

```python
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        b = int(sqrt(c))
        
        while a <= b:
            if a*a + b*b < c:
                a += 1
            elif  a*a + b*b > c:
                b -= 1
            else:
                return True
        return False
```

