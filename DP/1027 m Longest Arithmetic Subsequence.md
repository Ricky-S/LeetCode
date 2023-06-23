# [1027. Longest Arithmetic Subsequence](https://leetcode.com/problems/longest-arithmetic-subsequence/description/)

## Description

Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.


Note that: 

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).


Example 1:

```
Input: nums = [3,6,9,12]
Output: 4
Explanation:
The whole array is an arithmetic sequence with steps of length = 3.
```

Example 2:

```
Input: nums = [9,4,7,2,10]
Output: 3
Explanation:
The longest arithmetic subsequence is [4,7,10].
```

Example 3:

```
Input: nums = [20,1,15,3,10,5,8]
Output: 4
Explanation:
The longest arithmetic subsequence is [20,15,10,5].
```

Constraints:

- 2 <= nums.length <= 1000


- 0 <= nums[i] <= 500

Idea:

- DP


Solution:

```cpp
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int res = 0;
        vector<unordered_map<int, int> > dp(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                res = max(res, dp[i][diff]);
            }
        }
        return res + 1;
    }
};
```

My solution:

```cpp
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i]-nums[j];
                if (dp[j].count(diff) != 0) dp[i][diff] = dp[j][diff] + 1;
                else dp[i][diff] = 2;
                res = res > dp[i][diff] ? res : dp[i][diff];
            }
        }
        return res;
    }
};
```