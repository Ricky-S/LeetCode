You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



example 1\

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

example 2\
```
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
```


constraints:
```
1 <= nums.length <= 100
0 <= nums[i] <= 400
```

Idea:\
```cpp
dp[i]

nums = [2,7,9,3,1]

dp[0] = max(dp[1], 2 + dp[0+2]), which means we need to find dp[1] and dp[2].
dp[1] = max(dp[2], 7 + dp[1+2]), which means we need to find dp[2] and dp[3].
dp[2] = max(dp[3], 9 + dp[2+2]), which means we need to find dp[3] and dp[4].
dp[3] = max(dp[4], 3 + dp[3+2]), which means we need to find dp[4] and dp[5], but dp[5] is out of range, dp[>vector.size-1] = 0.
dp[i] = max(dp[i+1], nums[i] + dp[i+2], i and i+2 are < vector.size.
explanation: dp[i] means the max amount of money we can rob from house i to the end of the street.
we can choose to rob house i or skip house i, if we choose to rob house i, we can only rob house i+2 or skip house i+2, because we cannot rob adjacent houses.
```


```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2, 0);
        for (int i = nums.size()-1; i>=0; i--) {
            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
        }
        return dp[0];
    }
};
```











