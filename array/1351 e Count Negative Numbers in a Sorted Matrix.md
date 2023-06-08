# [1351. Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/)

## Problem:

Given a `m * n` matrix `grid` which is sorted in non-increasing order both row-wise and column-wise.

Return the number of **negative** numbers in `grid`.

**Example 1:**

```
Input: grid = [
  [4,3,2,-1],
  [3,2,1,-1],
  [1,1,-1,-2],
  [-1,-1,-2,-3]
]
Output: 8
Explanation: There are 8 negatives number in the matrix.
```

**Example 2:**

```
Input: grid = [[3,2],[1,0]]
Output: 0
```

**Example 3:**

```
Input: grid = [[1,-1],[-1,-1]]
Output: 3
```

**Example 4:**

```
Input: grid = [[-1]]
Output: 1
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 100`
- `-100 <= grid[i][j] <= 100`
- **Follow up:** Could you find an `O(n + m)` solution?

## Ideas:

1. Brute force: O(nm)
2. Binary search: O(nlogm)
3. O(n + m) solution: O(n + m)

## Solutions:

### Brute force: O(nm)

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] < 0) count++;
            }
        }
        return count;
    }
};
```

### Binary search: O(nlogm)

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            int left = 0;
            int right = grid[i].size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (grid[i][mid] < 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            count += grid[i].size() - left;
        }
        return count;
    }
};
```

### O(n + m) solution: O(n + m)

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size(), n = 0;
        while (m>0) {
            // cout << grid[m-1][n] << endl;
            if (grid[m-1][n] >= 0) {
                n++;
                if (n == grid[0].size()) break;
            } else {
                count += grid[0].size()-n;
                m--;
            }
            // cout << m << "m, n" << n << ", count" << count << endl;
        }
        return count;
    }
};
```








