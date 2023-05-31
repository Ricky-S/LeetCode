# 55. [Jump Game](https://leetcode.com/problems/jump-game/description/) (medium)

## Description

Given an array of non-negative integers `nums`, you are initially positioned at the **first index** of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the **last index**.



**Example 1:**

```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

```



**Constraints:**

- `1 <= nums.length <= 3 * 10^4`
- `0 <= nums[i][j] <= 10^5`

## Solution

### Dynamic Programming

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (dp[i]) {
                for (int j = 1; j <= nums[i]; j++) {
                    if (i + j < n) {
                        dp[i + j] = true;
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
```

### Greedy

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxPos = 0;
        for (int i = 0; i < n; i++) {
            if (i <= maxPos) {
                maxPos = max(maxPos, i + nums[i]);
                if (maxPos >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

Mine

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        if (dp[0] == 0) {
            if (nums.size() == 1) return true;
            return false;
        }
        else {
            for (int i = 1; i < nums.size(); i++) {
                dp[i] = max(dp[i-1]-1, nums[i]);
                // cout << i << ", " << dp[i] << endl;
                if (dp[i] == 0 && i != nums.size()-1) return false;
            }
        }
        return true;
    }
};
```

reduce space:

```cpp

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = 0;
        int dp = nums[0];
        if (dp == 0) {
            if (nums.size() == 1) return true;
            return false;
        }
        else {
            for (int i = 1; i < nums.size(); i++) {
                dp = max(dp-1, nums[i]);
                // cout << i << ", " << dp[i] << endl;
                if (dp == 0 && i != nums.size()-1) return false;
            }
        }
        return true;
    }
};
```