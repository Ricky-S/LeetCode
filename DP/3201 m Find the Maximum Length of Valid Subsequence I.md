# [3201. Find the Maximum Length of Valid Subsequence I](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/?envType=daily-question&envId=2025-07-16)

## Description

You are given an integer array```nums```.

A subsequence `sub` of `nums` with length `x` is called **valid** if it satisfies:

- `(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.`

Return the length of the **longest** **valid** subsequence of `nums`.

A **subsequence** is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

**Example 1:**

**Input:** nums = [1,2,3,4]

**Output:** 4

**Explanation:**

The longest valid subsequence is `[1, 2, 3, 4]`.

**Example 2:**

**Input:** nums = [1,2,1,1,2,1,2]

**Output:** 6

**Explanation:**

The longest valid subsequence is `[1, 2, 1, 2, 1, 2]`.

**Example 3:**

**Input:** nums = [1,3]

**Output:** 2

**Explanation:**

The longest valid subsequence is `[1, 3]`.

**Constraints:**

- `2 <= nums.length <= 2 * 105`
- `1 <= nums[i] <= 107`


## Solution

```python
class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = 0
        even_flag = odd_flag = False
        odd = even = -1
        for i in range(n):
            if nums[i] % 2 == 0 and not even_flag:
                even = i
                even_flag = True
            elif nums[i] % 2 == 1 and not odd_flag:
                odd = i
                odd_flag = True
            if even_flag == True and odd_flag == True:
                break
        cnt1 = 1
        cnt2 = 1
        # print(odd, even)
        if even_flag:
            for i in range(even+1, n):
                if (nums[i]+nums[even]) % 2 == 0:
                    cnt1 += 1
                if (nums[i]+nums[i-1]) % 2 == 1:
                    cnt2 += 1 
        cnt3 = cnt4 = 1
        if odd_flag:
            for i in range(odd+1, n):
                if (nums[i]+nums[odd]) % 2 == 0:
                    cnt3 += 1
                if (nums[i]+nums[i-1]) % 2 == 1:
                    cnt4 += 1   
        return max(cnt1, cnt2, cnt3, cnt4)
```