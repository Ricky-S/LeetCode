# [2364. Count Number of Bad Pairs](https://leetcode.com/problems/count-number-of-bad-pairs/description/?envType=daily-question&envId=2025-02-09)

## Description


You are given a **0-indexed** integer array `nums`. A pair of indices `(i, j)` is a **bad pair** if `i < j` and `j - i != nums[j] - nums[i]`.

Return *the total number of **bad pairs** in* `nums`.

**Example 1:**

```
Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.

```

**Example 2:**

```
Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.

```

**Constraints:**

- `1 <= nums.length <= 105`
- `1 <= nums[i] <= 109`


## Solution

```python
class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        total = n * (n - 1) // 2
        count = Counter(nums[j] - j for j in range(n))
        return total - sum(c * (c - 1) // 2 for c in count.values())
```





```python
class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        # for i in range(n):
        #     for j in range(i+1, n):
        #         if nums[j] - nums[i] != j - i:
        #             ans += 1
        # return ans
        nums1 = [value-index for index, value in enumerate(nums)]
        for value in dict(Counter(nums1)).values():
            if value > 1:
                ans += value * (value-1) / 2
        # print(dict(Counter(nums1))) 
        return int(n*(n-1)/2-ans)
```





