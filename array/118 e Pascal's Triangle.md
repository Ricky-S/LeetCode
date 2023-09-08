
# [118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)

## Description

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

![figure](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)



Example 1:
```
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```

Example 2:
```
Input: numRows = 1
Output: [[1]]
```

Constraints:

* 1 <= numRows <= 30

idea:
for rows larger than 3, every number[i] = previous_row[i-1]+previous_row[i].

## Solution

```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int row = 1;
        vector<vector<int>> result;
        while( row <= numRows ) {
            vector<int> rowNumber(row, 1);
            if (row >= 3) {
                for(int i = 1; i < row-1; i++) {
                    rowNumber[i] = result[row-2][i-1] + result[row-2][i];
                }
            }
            result.push_back(rowNumber);
            if (row == numRows) {
                return result;
            }
            else {
                row++;
            }
        }
        return result;
    }
};
```
```c++
class Solution {
    public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 0; i < numRows; i++) {
            vector<int> row(i+1, 1);
            for(int j = 1; j < i; j++) {
                row[j] = result[i-1][j-1] + result[i-1][j];
            }
            result.push_back(row);
        }
        return result;
    }
};
```