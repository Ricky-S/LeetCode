You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to $2 * 10^9$.



```
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```

example 1\
![image](https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg)

```
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
```

example 2\
![image](https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg)
```
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
```

Idea:\
```cpp
// first row and first column should be all 1.
set dp[obstacle] = 0;
dp[i][j] = dp[i-1][j] + dp[i][j-1];
```
```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // or
        // for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        // for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
       for (int i = 0; i < m; i++) {
           if (obstacleGrid[i][0] == 1) {
               dp[i][0] = 0;
               break;
           } else   dp[i][0] = 1;
       }    
        for (int j = 0; j < n; j++) {
           if (obstacleGrid[0][j] == 1) {
               dp[0][j] = 0;
               break;
           } else   dp[0][j] = 1;
        }
       for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else   dp[i][j] = dp[i-1][j] + dp[i][j-1];
               cout << "i: "<< i << "j" << j << " " <<dp[i][j] << endl;
            }
       }
       return dp[m-1][n-1];        
    }
};
```

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // or
        // for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        // for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
       for (int i = 0; i < m; i++) {
           if (obstacleGrid[i][0] == 1) {
               dp[i][0] = 0;
               break;
           } else   dp[i][0] = 1;
       }    
        for (int j = 0; j < n; j++) {
           if (obstacleGrid[0][j] == 1) {
               dp[0][j] = 0;
               break;
           } else   dp[0][j] = 1;
        }
       for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // if (obstacleGrid[i][j] == 1) {
                //     dp[i][j] = 0;
                // } else   dp[i][j] = dp[i-1][j] + dp[i][j-1];
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];   
                }              
            //    cout << "i: "<< i << "j" << j << " " <<dp[i][j] << endl;
            }
       }
       return dp[m-1][n-1];        
    }
};
```









