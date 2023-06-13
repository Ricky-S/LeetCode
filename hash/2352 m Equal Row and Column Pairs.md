# [2352. Equal Row and Column Pairs](https://leetcode.com/problems/equal-row-and-column-pairs/)

## description

Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).


### Example 1:
![image](https://assets.leetcode.com/uploads/2022/06/01/ex1.jpg)

```text
Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
```

### Example 2:

![image](https://assets.leetcode.com/uploads/2022/06/01/ex2.jpg)

```text
Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
```

### Constraints:

```text
n == grid.length
n == grid[i].length
1 <= n <= 1000
1 <= grid[i][j] <= 10000
```

## idea:

use unordered_map to store the row and column pairs.

```cpp
class Solution {
public:
    int countEqualRowsAndColumns(vector<vector<int>>& grid) {
        int result = 0;
        unordered_map<string, int> map;
        for (auto row : grid) {
            string rowStr = "";
            for (auto num : row) {
                rowStr += to_string(num);
            }
            map[rowStr]++;
        }
        for (int i = 0; i < grid.size(); i++) {
            string colStr = "";
            for (int j = 0; j < grid.size(); j++) {
                colStr += to_string(grid[j][i]);
            }
            result += map[colStr];
        }
        return result;
    }
};
```

OR 

```cpp
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0;
        int size = grid.size();
        map<vector<int>, int> umap;
        for (int i = 0; i < size; i++) {
            umap[grid[i]]++;
        }
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < size; j++) {
                temp.push_back(grid[j][i]);
            }
            if(umap.find(temp)!= umap.end()) count+=umap[temp];
        }
        return count;
    }
};
```