# [1277. Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/?envType=daily-question&envId=2024-10-27)

## Description

Given a `m * n` matrix of ones and zeros, return how many **square** submatrices have all ones.

**Example 1:**

```
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation:
There are10 squares of side 1.
There are4 squares of side 2.
There is1 square of side 3.
Total number of squares = 10 + 4 + 1 =15.

```

**Example 2:**

```
Input: matrix =
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation:
There are6 squares of side 1.
There is1 square of side 2.
Total number of squares = 6 + 1 =7.

```

**Constraints:**

- `1 <= arr.length <= 300`
- `1 <= arr[0].length <= 300`
- `0 <= arr[i][j] <= 1`

## Solution

```python
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        dp = [[0] * n for _ in range(m)]
        res = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 1:
                    if i == 0 or j == 0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                    res += dp[i][j]
        return res
```


```python
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        ans = sum(matrix[0])

        for i in range(1, len(matrix)):
            ans += matrix[i][0]
            for j in range(1, len(matrix[0])):
                if matrix[i][j]:
                    matrix[i][j] += min(matrix[i][j-1], matrix[i-1][j-1], matrix[i-1][j])
                    ans += matrix[i][j]
        
        return ans
```