# [96. Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)

## Description

Given an integer `n`, return *the number of structurally unique **BST'**s (binary search trees) which has exactly* `n` *nodes of unique values from* `1` *to* `n` *inclusive*.

### Example 1:

![image](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

```
Input: n = 3
Output: 5
```

### Example 2:

```
Input: n = 1
Output: 1
```

### Constraints:

- `1 <= n <= 19`


## Idea:

DP

- if n = 0, f(n) = 1
- if n = 1, f(n) = 1
- if n = 2, f(n) = f(0) * f(1) + f(1) * f(0) = 2
- if n = 3, f(n) = f(0) * f(2) + f(1) * f(1) + f(2) * f(0) = 5
- if n = 4, f(n) = f(0) * f(3) + f(1) * f(2) + f(2) * f(1) + f(3) * f(0) = 14
- if n = 5, f(n) = f(0) * f(4) + f(1) * f(3) + f(2) * f(2) + f(3) * f(1) + f(4) * f(0) = 42

- f(n) = f(0) * f(n - 1) + f(1) * f(n - 2) + ... + f(n - 1) * f(0)

```cpp

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};

```

My solution:

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> depestLevel(n+1, 0);
        depestLevel[0] = 1;
        for (int i = 1; i <= n; i++) {
            int half = i / 2;
            for (int j = 0; j < half; j++) {
                depestLevel[i] += 2 * depestLevel[j] * depestLevel[(i-1)-j];
            }
            if(i % 2 == 1) {
                depestLevel[i] += depestLevel[i/2] * depestLevel[i/2];
            }
        }
        return depestLevel[n];
    }
};