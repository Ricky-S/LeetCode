# 1572. Matrix Diagonal Sum

Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

ex1
![image](https://assets.leetcode.com/uploads/2020/08/14/sample_1911.png)

```cpp
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
```

ex2
```cpp
Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
```

ex3
```cpp
Input: mat = [[5]]
Output: 5
```

Constraints\
```cpp
n == mat.length == mat[i].length
1 <= n <= 100
1 <= mat[i][j] <= 100
```

```cpp
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        const int len = mat.size();
        int sum = 0;
        if (len % 2 == 0) {
            for (int i = 0; i< len; i++) {
                for (int j = 0; j< len; j++) {
                    if ((i == j) || (i + j == len-1)) {
                        sum += mat[i][j];
                        // cout << "i: " << i << ", j: " << j << endl;
                    }
                }
            }
        }else {
            for (int i = 0; i< len; i++) {
                for (int j = 0; j< len; j++) {
                    if ((i == j) || (i + j == len-1)) {
                        sum += mat[i][j];
                        // cout << "i: " << i << ", j: " << j << endl;
                    }
                }
            }
        }
        return sum;
    }
};
```
OR
```cpp
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        const int len = mat.size();
        int sum = 0;
        for (int i = 0; i< len; i++) {
            for (int j = 0; j< len; j++) {
                if ((i == j) || (i + j == len-1)) {
                    sum += mat[i][j];
                    // cout << "i: " << i << ", j: " << j << endl;
                }
            }
        }
        return sum;
    }
};
```










