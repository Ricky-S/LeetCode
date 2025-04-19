# [2563. Count the Number of Fair Pairs](https://leetcode.com/problems/count-the-number-of-fair-pairs/description/?envType=daily-question&envId=2025-04-19)

## Description

Given a **0-indexed** integer array `nums` of size `n` and two integers `lower` and `upper`, return *the number of fair pairs*.

A pair `(i, j)` is **fair** if:

- `0 <= i < j < n`, and
- `lower <= nums[i] + nums[j] <= upper`

**Example 1:**

```
Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

```

**Example 2:**

```
Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).

```

**Constraints:**

- `1 <= nums.length <= 105`
- `nums.length == n`
- `109 <= nums[i] <= 109`
- `109 <= lower <= upper <= 109`


## Solution

```python
class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        # count = 0
        # for i in range(len(nums)):
        #     left, right = i, len(nums) - 1
        #     while nums[left]+nums[right]
        #     # for j in range(i+1, len(nums)):
        #     #     val = nums[i]+nums[j]
        #     #     if val < lower:
        #     #         pass
        #     #     elif val > upper:
        #     #         break
        #     #     else:
        #     #         count += 1
        l = 0
        r = len(nums) - 1
        cnt_upper = 0
        while l < r:
            if nums[l] + nums[r] <= upper:
                cnt_upper += r - l
                l += 1
            else:
                r -= 1
        l = 0
        r = len(nums) - 1
        cnt_l = 0
        while l < r:
            if nums[l] + nums[r] < lower:
                cnt_l += r - l
                l += 1
            else:
                r -= 1
        
        return cnt_upper - cnt_l
```