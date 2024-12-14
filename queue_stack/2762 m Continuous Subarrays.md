# [2762. Continuous Subarrays](https://leetcode.com/problems/continuous-subarrays/description/?envType=daily-question&envId=2024-12-14)

## Description

You are given a **0-indexed** integer array `nums`. A subarray of `nums` is called **continuous** if:

- Let `i`, `i + 1`, ..., `j`be the indices in the subarray. Then, for each pair of indices `i <= i1, i2 <= j`, `0 <= |nums[i1] - nums[i2]| <= 2`.

Return *the total number of **continuous** subarrays.*

A subarray is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**

```
Input: nums = [5,4,2,4]
Output: 8
Explanation:
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
Thereare no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.

```

**Example 2:**

```
Input: nums = [1,2,3]
Output: 6
Explanation:
Continuous subarray of size 1: [1], [2], [3].
Continuous subarray of size 2: [1,2], [2,3].
Continuous subarray of size 3: [1,2,3].
Total continuous subarrays = 3 + 2 + 1 = 6.

```

**Constraints:**

- `1 <= nums.length <= 105`
- `1 <= nums[i] <= 109`


## Solution

```python
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        # start = 0
        # count = 0
        # while start < len(nums):
        #     # print(f"{start}")
        #     maxv = float('-inf')
        #     minv = float('inf')
        #     for i in range(start, len(nums)):
        #         maxv = max(maxv, nums[i])
        #         minv = min(minv, nums[i])
        #         if maxv - minv > 2:
        #             count += i - start
        #             # print(f"{start}, {i}, {count}")
        #             break
        #     else:
        #         count += i-start+1
        #     start += 1
        # return count

        # count = 0
        # start = 0
        # maxv = float('-inf')
        # minv = float('inf')
        
        # for end in range(len(nums)):
        #     maxv = max(maxv, nums[end])
        #     minv = min(minv, nums[end])
            
        #     while maxv - minv > 2:
        #         if nums[start] == maxv:
        #             maxv = max(nums[start + 1:end + 1])
        #         if nums[start] == minv:
        #             minv = min(nums[start + 1:end + 1])
        #         start += 1
            
        #     count += end - start + 1
        
        # return count


        count = 0
        start = 0
        max_deque = []
        min_deque = []
        
        for end in range(len(nums)):
            while max_deque and nums[max_deque[-1]] <= nums[end]:
                max_deque.pop()
            max_deque.append(end)
            
            while min_deque and nums[min_deque[-1]] >= nums[end]:
                min_deque.pop()
            min_deque.append(end)
            
            while nums[max_deque[0]] - nums[min_deque[0]] > 2:
                if max_deque[0] == start:
                    max_deque.pop(0)
                if min_deque[0] == start:
                    min_deque.pop(0)
                start += 1
            
            count += end - start + 1
        
        return count
```