# 598. Range Addition II
Easy

You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

Count and return the number of maximum integers in the matrix after performing all the operations.

example 1
![](https://assets.leetcode.com/uploads/2020/10/02/ex1.jpg)
```
Input: m = 3, n = 3, ops = [[2,2],[3,3]]
Output: 4
Explanation: The maximum integer in M is 2, and there are four of it in M. So return 4.
```

example 2
```
Input: m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
Output: 4
```

example 3
```
Input: m = 3, n = 3, ops = []
Output: 9
```

idea:

use two variables to record the minimum row and column.

```cpp
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minRow = m;
        int minCol = n;
        for (auto &op : ops) {
            minRow = min(minRow, op[0]);
            minCol = min(minCol, op[1]);
        }
        return minRow * minCol;
    }
};
```
My solution:
```cpp
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {

        if (ops.size() == 0) return m*n;

        int height = INT_MAX, len = INT_MAX;

        for (int i = 0; i < ops.size(); i++) {
            height = min(height, min(m, ops[i][0]));
            len = min(len, min(n, ops[i][1]));
        }
        return height*len;
    }
};
```
