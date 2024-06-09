# [974. Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/description/?envType=daily-question&envId=2024-06-09)


Given an integer array `nums` and an integer `k`, return *the number of non-empty **subarrays** that have a sum divisible by* `k`.

A **subarray** is a **contiguous** part of an array.

**Example 1:**

```
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

```

**Example 2:**

```
Input: nums = [5], k = 9
Output: 0

```

**Constraints:**

- `1 <= nums.length <= 3 * 104`
- `104 <= nums[i] <= 104`
- `2 <= k <= 104`


## Solution

```python
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        nums_sum = 0
        div_dict = defaultdict(list)
        ans = 0

        for i in range(len(nums)):
            nums_sum += nums[i]
            if nums_sum % k == 0:
                ans += 1
            
            if nums_sum % k in div_dict:
                div_dict[nums_sum % k].append(i)
                ans += len(div_dict[nums_sum % k]) - 1
            else:
                div_dict[nums_sum % k]=[i]

        return ans
```

OR

```python
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        count = collections.Counter({0: 1})
        res = pre = 0
        for num in nums:
            pre += num
            res += count[pre % k]
            count[pre % k] += 1
        return res
```

```python
from typing import List
from collections import defaultdict

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefix_sum = 0
        mod_count = defaultdict(int)
        mod_count[0] = 1  # Initialize for the case where prefix sum itself is divisible by k
        ans = 0

        for num in nums:
            prefix_sum += num
            mod = prefix_sum % k
            
            if mod in mod_count:
                ans += mod_count[mod]
            
            mod_count[mod] += 1
        
        return ans
```



