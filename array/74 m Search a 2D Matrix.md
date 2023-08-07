# [74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/description/)

## Description

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:

![img](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)

```txt
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

Example 2:

![img](https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg)

```txt
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

Constraints:

- m == matrix.length


- n == matrix[i].length


- 1 <= m, n <= 100


- -104 <= matrix[i][j], target <= 104


## Solution

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = m * n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (matrix[mid / n][mid % n] == target) return true;
        else if (matrix[mid / n][mid % n] < target) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}
```

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid;            
        }
        return matrix[r / m][r % m] == target;

    }
};
```