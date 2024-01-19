# [931. Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19)

## Description

Given an `n x n` array of integers `matrix`, return *the **minimum sum** of any **falling path** through* `matrix`.

A **falling path** starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position `(row, col)` will be `(row + 1, col - 1)`, `(row + 1, col)`, or `(row + 1, col + 1)`.


### Example 1:
![](https://assets.leetcode.com/uploads/2021/11/03/failing1-grid.jpg)

```
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
```

### Example 2:
![](https://assets.leetcode.com/uploads/2021/11/03/failing2-grid.jpg)

```
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
```

## Constraints:

- `n == matrix.length == matrix[i].length`
- `1 <= n <= 100`
- `-100 <= matrix[i][j] <= 100`


## Solution:

```python
class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        dp = [[0] * n for _ in range(n)]
        for i in range(n):
            dp[0][i] = matrix[0][i]
        for i in range(1, n):
            for j in range(n):
                dp[i][j] = dp[i - 1][j]
                if j > 0:
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1])
                if j < n - 1:
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1])
                dp[i][j] += matrix[i][j]
        return min(dp[-1])
```

```python
class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        dp = matrix[0]
        for i in range(1, n):
            dp = [matrix[i][j] + min(dp[max(0, j - 1): min(n, j + 2)]) for j in range(n)]
        return min(dp)
```

```python
class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        
        m, n = len(matrix), len(matrix[0])

        res = [[101] * n for _ in range(m)]
        res[0][:] = matrix[0][:]

        for i in range(1, m):
            for j in range(n):
                if j == 0:
                    res[i][j] = matrix[i][j] + min(res[i-1][j], res[i-1][j+1])
                elif j == n-1:
                    res[i][j] = matrix[i][j] + min(res[i-1][j-1], res[i-1][j])
                else:
                    res[i][j] = matrix[i][j] + min(res[i-1][j-1], res[i-1][j], res[i-1][j+1])
        
        return min(res[-1][:])
```

```python