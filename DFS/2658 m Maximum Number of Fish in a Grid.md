# [2658. Maximum Number of Fish in a Grid](https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/?envType=daily-question&envId=2025-01-28)

## Description

You are given a **0-indexed** 2D matrix `grid` of size `m x n`, where `(r, c)` represents:

- A **land** cell if `grid[r][c] = 0`, or
- A **water** cell containing `grid[r][c]` fish, if `grid[r][c] > 0`.

A fisher can start at any **water** cell `(r, c)` and can do the following operations any number of times:

- Catch all the fish at cell `(r, c)`, or
- Move to any adjacent **water** cell.

Return *the **maximum** number of fish the fisher can catch if he chooses his starting cell optimally, or* `0` if no water cell exists.

An **adjacent** cell of the cell `(r, c)`, is one of the cells `(r, c + 1)`, `(r, c - 1)`, `(r + 1, c)` or `(r - 1, c)` if it exists.

**Example 1:**

!https://assets.leetcode.com/uploads/2023/03/29/example.png

```
Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
Output: 7
Explanation: The fisher can start at cell(1,3) and collect 3 fish, then move to cell(2,3) and collect 4 fish.

```

**Example 2:**

!https://assets.leetcode.com/uploads/2023/03/29/example2.png

```
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
Output: 1
Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish.

```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 10`
- `0 <= grid[i][j] <= 10`

## Solution

```python

from typing import List

# class Solution:
#     def getMaximumGold(self, grid: List[List[int]]) -> int:
#         m, n = len(grid), len(grid[0])
#         def dfs(i, j):
#             if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
#                 return 0
#             gold = grid[i][j]
#             grid[i][j] = 0
#             max_gold = 0
#             for x, y in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
#                 max_gold = max(max_gold, gold + dfs(i + x, j + y))
#             grid[i][j] = gold
#             return max_gold
#         return max(dfs(i, j) for i in range(m) for j in range(n))
```


```python
class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        vis = [[0] * n for _ in range(m)]

        directions = [[-1, 0], [1, 0], [0, 1], [0, -1]]

        ans = 0

        def bfs(i, j):
            q = []
            q.append((i, j))
            vis[i][j] = 1
            fish = grid[i][j]

            while q:
                r, c = q.pop(0)

                for dr, dc in directions:
                    nr, nc = r+dr, c+dc

                    if 0 <=nr<m and 0<=nc<n and not vis[nr][nc] and grid[nr][nc] > 0:
                        vis[nr][nc] = 1
                        fish += grid[nr][nc]
                        q.append((nr, nc))
            return fish
        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0 and not vis[i][j]:
                    ans = max(ans, bfs(i, j))
        return ans
```
