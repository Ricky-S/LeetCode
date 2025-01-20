# [2661. First Completely Painted Row or Column](https://leetcode.com/problems/first-completely-painted-row-or-column/description/?envType=daily-question&envId=2025-01-20)

## Description

You are given a **0-indexed** integer array `arr`, and an `m x n` integer **matrix** `mat`. `arr` and `mat` both contain **all** the integers in the range `[1, m * n]`.

Go through each index `i` in `arr` starting from index `0` and paint the cell in `mat` containing the integer `arr[i]`.

Return *the smallest index* `i` *at which either a row or a column will be completely painted in* `mat`.

**Example 1:**

https://leetcode.com/problems/first-completely-painted-row-or-column/description/image%20explanation%20for%20example%201

!https://assets.leetcode.com/uploads/2023/01/18/grid1.jpg

```
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].

```

**Example 2:**

!https://assets.leetcode.com/uploads/2023/01/18/grid2.jpg

```
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].

```

**Constraints:**

- `m == mat.length`
- `n = mat[i].length`
- `arr.length == m * n`
- `1 <= m, n <= 105`
- `1 <= m * n <= 105`
- `1 <= arr[i], mat[r][c] <= m * n`
- All the integers of `arr` are **unique**.
- All the integers of `mat` are **unique**.


## Solution

```python
class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        rows = [0] * m
        cols = [0] * n
        for i, num in enumerate(arr):
            r, c = divmod(num - 1, n)
            rows[r] += 1
            cols[c] += 1
            if rows[r] == n or cols[c] == m:
                return i
        return -1
```

```python
class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])

        dic = {}
        for i in range(m):
            for j in range(n):
                dic[mat[i][j]] = [i, j]
        row = [0 for _ in range(m)]
        column = [0 for _ in range(n)]
        for i in range(len(arr)):
            r, c = dic[arr[i]]
            row[r] += 1
            column[c] += 1
            if row[r] == n or column[c] == m:
                return i
        return -1
```