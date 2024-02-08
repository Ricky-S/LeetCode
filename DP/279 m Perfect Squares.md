# [279. Perfect Squares](https://leetcode.com/problems/perfect-squares/description/?envType=daily-question&envId=2024-02-08)


## Description

Given an integer `n`, return the least number of perfect square numbers that sum to `n`.

A **perfect square** is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, `1`, `4`, `9`, and `16` are perfect squares while `3` and `11` are not.

**Example 1:**

```
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
```

**Example 2:**

```
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

**Constraints:**

- `1 <= n <= 10^4`

## Solution

```python
class Solution:
    def numSquares(self, n: int) -> int:
        # Step 1: Generate all the perfect squares that are less than or equal to n
        squares = [i * i for i in range(1, int(n ** 0.5) + 1)]
        # Step 2: DP
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            for square in squares:
                if i < square:
                    break
                dp[i] = min(dp[i], dp[i - square] + 1)
        return dp[n]
```

```python
class Solution:
    def numSquares(self, n: int) -> int:
        res = [float('inf')] * (n + 1)
        res[0] = 0  # Base case
        
        for i in range(1, n + 1):
            for j in range(1, int(sqrt(i)) + 1):
                res[i] = min(res[i], 1 + res[i - j * j])
                
        return res[n]
```