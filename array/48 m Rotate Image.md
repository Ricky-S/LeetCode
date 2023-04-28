# 48. Rotate Image

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

![image](https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg)\
Example 1:
```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
```
![ex2](https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg)\
Example 2:
```
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

Idea:\
reverse and swap
```cpp
1 2 3        7 8 9      7 4 1
4 5 6    ->  4 5 6  ->  8 5 2
7 8 9        1 2 3      9 6 3
```



```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse (matrix.begin(), matrix.end());

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i+1; j < matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
```

























