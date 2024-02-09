# [368. Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2024-02-09)

## Description

Given a set of **distinct** positive integers `nums`, return the largest subset `answer` such that every pair `(answer[i], answer[j])` of elements in this subset satisfies:

- `answer[i] % answer[j] == 0`, or
- `answer[j] % answer[i] == 0`
- If there are multiple solutions, return any of them.

**Example 1:**

```
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
```

**Example 2:**

```
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 2 * 10^9`
- All the integers in `nums` are **unique**.

## Solution

```python
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        
        nums.sort()
        n = len(nums)
        dp = [[num] for num in nums]  # Initialize DP table with each number as a starting subset
        # print(dp)
        for i in range(1, n):
            for j in range(i):
                if nums[i] % nums[j] == 0 and len(dp[i]) < len(dp[j]) + 1:
                    # If nums[i] is divisible by nums[j] and adding nums[i] to the subset ending with nums[j]
                    # would make it larger, update dp[i] to the new larger subset
                    dp[i] = dp[j] + [nums[i]]
            # print(dp)
        # print(dp)
        # Find and return the longest subset from dp
        return max(dp, key=len)
```










