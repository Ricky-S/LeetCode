You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



example 1\

```
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
```

example 2\
```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```
ex3
```
Input: nums = [1,2,3]
Output: 3
```

constraints:
```
1 <= nums.length <= 100
0 <= nums[i] <= 1000
```

Idea:\
```
dp[i]

nums = [1,2,3,1]

dp[0] = max(dp[1], 1 + dp[0+2]), 0+2 should <= vector.size()-2, because size()-1 is adjacent to 0.
dp[1] = max(dp[2], 2 + dp[1+2]), 1+2 should <= vector.size()-1.

if the range is 0~vector.size()-2, it is similiar to the problem 198, which is house robber I.
we can find two results, the first is from 0 to vector.size()-2, the second is from 1 to vector.size()-1.
and return the larger one.
```


```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return nums[0] > nums[1] ? nums[0]: nums[1];
        else if (nums.size() == 3) return max(max(nums[0], nums[1]), nums[2]);
        vector<int> dp(nums.size()+2, 0);
        int result;
        for (int i = nums.size()-1; i>=1; i--) {
            dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
            // cout << "i: " << i << ", " << dp[i] << endl;
        }
        result = dp[1];
        dp[nums.size()-1] = 0;
        for (int i = nums.size()-2; i>=0; i--) {
            dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
        }        
        return dp[0] > result ? dp[0] : result;
    }
};
```











