# [1658. Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)

## Description

You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this **modifies** the array for future operations.

Return *the **minimum number** of operations to reduce* `x` *to **exactly*** `0` *if it's possible**, otherwise, return* `-1`.

Example 1:

```
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
```

Example 2:

```
Input: nums = [5,6,7,8,9], x = 4
Output: -1
```

Example 3:

```
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
```

Constraints:

- `1 <= nums.length <= 105`

- `1 <= nums[i] <= 104`

- `1 <= x <= 109`

## Idea:

[explanation](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/solutions/1080880/are-you-stuck-once-read-this-logic-explained-clearly-easy-to-understand/?envType=daily-question&envId=2023-09-20)

This is a sliding window problem. We can find the longest subarray with sum `sum(nums) - x`. If we can find such a subarray, then the minimum number of operations is `len(nums) - len(subarray)`. Otherwise, return `-1`.

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target == 0) return nums.size();
        if (target < 0) return -1;
        int left = 0, right = 0, sum = 0, res = -1;
        while (right < nums.size()) {
            sum += nums[right++];
            while (sum > target) sum -= nums[left++];
            if (sum == target) res = max(res, right - left);
        }
        return res == -1 ? -1 : nums.size() - res;
    }
};
```