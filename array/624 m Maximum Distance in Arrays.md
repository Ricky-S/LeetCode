# [624. Maximum Distance in Arrays](https://leetcode.com/problems/maximum-distance-in-arrays/description/?envType=daily-question&envId=2024-08-16)

## Description

You are given `m` `arrays`, where each array is sorted in **ascending order**.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers `a` and `b` to be their absolute difference `|a - b|`.

Return *the maximum distance*.

**Example 1:**

```
Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.

```

**Example 2:**

```
Input: arrays = [[1],[1]]
Output: 0

```

**Constraints:**

- `m == arrays.length`
- `2 <= m <= 105`
- `1 <= arrays[i].length <= 500`
- `104 <= arrays[i][j] <= 104`
- `arrays[i]` is sorted in **ascending order**.
- There will be at most `105` integers in all the arrays.

## Solution

```python
class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        min1 = min2 = 99999
        max1 = max2 = -99999
        for i in range(len(arrays)):
            if arrays[i][0] < min1:
                min1 = arrays[i][0]
                min1_index = i
            if arrays[i][-1] > max1:
                max1 = arrays[i][-1]
                max1_index = i

        for i in range(len(arrays)):
            if arrays[i][0] < min2 and i != min1_index:
                min2 = arrays[i][0]
            if arrays[i][-1] > max2 and i != max1_index:
                max2 = arrays[i][-1]

        if min1_index != max1_index:
            return max1 - min1
        else:
            return max(max2-min1, max1-min2)

        
```