# [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/)


## Description

Given an array of integers `nums` and an integer `k`, return *the total number of subarrays whose sum equals to* `k`.

A subarray is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**

```
Input: nums = [1,1,1], k = 2
Output: 2

```

**Example 2:**

```
Input: nums = [1,2,3], k = 3
Output: 2

```

**Constraints:**

- `1 <= nums.length <= 2 * 104`
- `1000 <= nums[i] <= 1000`
- `107 <= k <= 107`


## Solution

```python
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = collections.Counter({0: 1})
        res = pre = 0
        for num in nums:
            pre += num
            res += count[pre - k]
            count[pre] += 1
        return res
```

OR

```python
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sum_counts = {0: 1}
        curr_sum = 0
        res = 0
        
        for num in nums:
            curr_sum += num
            res += sum_counts.get(curr_sum - k, 0)
            sum_counts[curr_sum] = sum_counts.get(curr_sum, 0) + 1
        
        return res
```

```python
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_sum = 0
        prefix_count = defaultdict(int)
        prefix_count[0] = 1  # Initialize for the case where a prefix sum itself equals k
        ans = 0

        for num in nums:
            prefix_sum += num
            
            # If (prefix_sum - k) exists in the map, it means there is a subarray
            # ending at the current index with sum equal to k.
            if (prefix_sum - k) in prefix_count:
                ans += prefix_count[prefix_sum - k]
            
            # Increment the count of the current prefix sum in the map.
            prefix_count[prefix_sum] += 1
        
        return ans
```