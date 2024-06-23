# [1248. Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/description/?envType=daily-question&envId=2024-06-22)

## Description

Given an array of integers `nums` and an integer `k`. A continuous subarray is called **nice** if there are `k` odd numbers on it.

Return *the number of **nice** sub-arrays*.

**Example 1:**

```
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

```

**Example 2:**

```
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

```

**Example 3:**

```
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

```

**Constraints:**

- `1 <= nums.length <= 50000`
- `1 <= nums[i] <= 10^5`
- `1 <= k <= nums.length`


## Solution

```python
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        count = 0
        odd = [-1]
        for i in range(len(nums)):
            if nums[i] % 2 == 1:
                odd.append(i)
        odd.append(len(nums))
        for i in range(1, len(odd) - k):
            count += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1])
        return count
```

```python
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        nums = [num%2 for num in nums]

        res = 0
        prefix = [0] * ( len(nums) + 1)
        prefix[0] = 1
        start = 0
        for num in nums:
            start += num
            if start >= k:
                res += prefix[start-k]
            prefix[start] += 1

        return res
```