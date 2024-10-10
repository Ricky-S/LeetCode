# [962. Maximum Width Ramp](https://leetcode.com/problems/maximum-width-ramp/description/?envType=daily-question&envId=2024-10-10)

## Description

A **ramp** in an integer array `nums` is a pair `(i, j)` for which `i < j` and `nums[i] <= nums[j]`. The **width** of such a ramp is `j - i`.

Given an integer array `nums`, return *the maximum width of a **ramp** in* `nums`. If there is no **ramp** in `nums`, return `0`.

**Example 1:**

```
Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.

```

**Example 2:**

```
Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.

```

**Constraints:**

- `2 <= nums.length <= 5 * 104`
- `0 <= nums[i] <= 5 * 104`


## Solution

```python
class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        stack = []
        for i, num in enumerate(nums):
            if not stack or nums[stack[-1]] > num:
                stack.append(i)
        res = 0
        for j in range(len(nums) - 1, -1, -1):
            while stack and nums[stack[-1]] <= nums[j]:
                res = max(res, j - stack.pop())
        return res
```

```python
class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        stack = []

        for i in range(len(nums)):
            if not stack or nums[stack[-1]] > nums[i]:
                stack.append(i)
        print(f"{stack}")
        res = 0
        for i in range(len(nums)-1, 0, -1):
            while stack and nums[stack[-1]] <= nums[i]:
                # print(f"{i}, {res}, {stack}")
                res = max(res, i-stack[-1])
                stack.pop()
        return res
```