# 45. Jump Game II

## Description

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and

i + j < n

Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

example 1:

```
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The optimal solution is to take 1 step from index 0 to 1, then 3 steps to the last index.
```

example 2:

```
Input: nums = [2,3,0,1,4]
Output: 2
```

Constraints:

- 1 <= nums.length <= $10^4$

- 0 <= nums[i] <= 1000

Idea:

use dynamic programming to record the minimum number of jumps to reach each index.

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < n) {
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};
```

OR

use greedy algorithm to record the maximum index that can be reached by the current step.

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxPos = 0;
        int end = 0;
        int step = 0;
        for (int i = 0; i < n - 1; i++) {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end) {
                end = maxPos;
                step++;
            }
        }
        return step;
    }
};
```

My solution:

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i; j < i+nums[i-1]; j++) {
                dp[j] = min(dp[j], dp[i-1]+1);
                // cout << j << "index, " << dp[j] << endl;
                if (j == nums.size()-1) return dp[j];
            } 
        }
        return 0;
    }
};
```



