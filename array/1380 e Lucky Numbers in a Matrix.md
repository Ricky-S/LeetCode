# [1380. Lucky Numbers in a Matrix](https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=daily-question&envId=2024-07-19)

## Description

Given an `m x n` matrix of **distinct** numbers, return *all **lucky numbers** in the matrix in **any** order*.

A **lucky number** is an element of the matrix such that it is the minimum element in its row and maximum in its column.

**Example 1:**

```
Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.

```

**Example 2:**

```
Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.

```

**Example 3:**

```
Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.

```

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= n, m <= 50`
- `1 <= matrix[i][j] <= 105`.
- All elements in the matrix are distinct.


## Solution

```python
class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        row = len(matrix)
        col = len(matrix[0])
        res = []

        for i in range(row):
            # Find the minimum element in the row
            min_val = min(matrix[i])
            min_col_index = matrix[i].index(min_val)

            # Check if this minimum element is the maximum in its column
            is_lucky = True
            for k in range(row):
                if matrix[k][min_col_index] > min_val:
                    is_lucky = False
                    break

            if is_lucky:
                res.append(min_val)

        return res
```

```python
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        col = len(matrix[0])
        row = len(matrix)
        res = []
        for i in range(row):
            index = 0
            val = 100000

            for j in range(col):
                if matrix[i][j] <= val:
                    index = j
                    val = matrix[i][j]
            flag = 0
            for k in range(row):
                if val >= matrix[k][index]:
                    flag += 1
                else:
                    break                    
            if flag == row:
                res.append(matrix[i][index])
        return res
```