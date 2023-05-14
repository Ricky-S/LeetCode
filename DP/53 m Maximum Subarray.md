# 53. Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.




example 1\
```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```

example 2\
```
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
```

ex3
```
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```

Idea:\
```cpp
1.
dp[i] = max(dp[i-1]+nums[i],nums[i])
find the largest dp[i] in dp
2.
use dp0 and dp1 to store dp[i-1] and dp[i], will decrease the space complexity to O(1).
```

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
        }
        int result=dp[0];
        for (int i = 1; i < nums.size(); i++) {
            result = max(result, dp[i]);
        }       
        return result;
    }
};
```
OR 
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // vector<int> dp(nums.size(), 0);
        // dp[0] = nums[0];
        int dp0 = nums[0], dp1;
        int result=nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp1 = max(dp0+nums[i],nums[i]);
            result = max(result, dp1);
            dp0 = dp1;
        }    
        return result;
    }
};
```










