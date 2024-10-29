# [2684. Maximum Number of Moves in a Grid](https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/?envType=daily-question&envId=2024-10-29)

## Description

You are given a **0-indexed** `m x n` matrix `grid` consisting of **positive** integers.

You can start at **any** cell in the first column of the matrix, and traverse the grid in the following way:

- From a cell `(row, col)`, you can move to any of the cells: `(row - 1, col + 1)`, `(row, col + 1)` and `(row + 1, col + 1)` such that the value of the cell you move to, should be **strictly** bigger than the value of the current cell.

Return *the **maximum** number of **moves** that you can perform.*

**Example 1:**

!https://assets.leetcode.com/uploads/2023/04/11/yetgriddrawio-10.png

```
Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
Output: 3
Explanation: We can start at the cell (0, 0) and make the following moves:
- (0, 0) -> (0, 1).
- (0, 1) -> (1, 2).
- (1, 2) -> (2, 3).
It can be shown that it is the maximum number of moves that can be made.
```

**Example 2:**

```
Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
Output: 0
Explanation: Starting from any cell in the first column we cannot perform any moves.

```

!https://assets.leetcode.com/uploads/2023/04/12/yetgrid4drawio.png

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `2 <= m, n <= 1000`
- `4 <= m * n <= 105`
- `1 <= grid[i][j] <= 106`


## Solution

```python
class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        row, column = len(grid), len(grid[0])

        ans = [[0] * column for i in range(row)]

        for j in range(column-1):
            for i in range(row):
                if i == 0:
                    if grid[i][j] < grid[i][j+1]:
                        ans[i][j+1] = ans[i][j] + 1
                    if grid[i][j] < grid[i+1][j+1]:
                        ans[i+1][j+1] = ans[i][j] + 1
                # if i == 0:
                #     if grid[i][j] < grid[i][j+1]:
                #         ans[i][j+1] = max(ans[i][j+1], ans[i][j] + 1)
                #     if grid[i][j] < grid[i+1][j+1]:
                #         ans[i+1][j+1] = max(ans[i+1][j+1], ans[i][j] + 1)
                elif i == row - 1:
                    if grid[i][j] < grid[i][j+1]:
                        ans[i][j+1] = max(ans[i][j+1], ans[i][j] + 1)
                    if grid[i][j] < grid[i-1][j+1]:
                        ans[i-1][j+1] = max(ans[i-1][j+1], ans[i][j] + 1)     
                else:
                    if grid[i][j] < grid[i][j+1]:
                        ans[i][j+1] = max(ans[i][j+1], ans[i][j] + 1)
                    if grid[i][j] < grid[i-1][j+1]:
                        ans[i-1][j+1] = max(ans[i-1][j+1], ans[i][j] + 1)
                    if grid[i][j] < grid[i+1][j+1]:
                        ans[i+1][j+1] = max(ans[i+1][j+1], ans[i][j] + 1)
            # if max([row[j+1] for row in ans]) == 0:
            # print(ans)
            if max([ans[i][j + 1] for i in range(row)]) <= max([ans[i][j] for i in range(row)]):
                if j == 0:
                    return 0
                else:
                    return max([row[j] for row in ans])
                    # return max([ans[i][j] for i in range(row)])
        return max([row[-1] for row in ans])
        # return max([ans[i][-1] for i in range(row)])
```