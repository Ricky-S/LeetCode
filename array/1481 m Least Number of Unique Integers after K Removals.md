# [1481. Least Number of Unique Integers after K Removals](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16)

## Description

Given an array of integers `arr` and an integer `k`. Find the least number of unique integers after removing exactly `k` elements.

### Example 1:

```
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
```

### Example 2:

```
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
```

### Constraints:

- `1 <= arr.length <= 10^5`

- `1 <= arr[i] <= 10^9`

- `0 <= k <= arr.length`

## Solution

```python
class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        value_count = Counter(arr)
        sort_value_count = sorted(value_count.items(), key=lambda x: x[1])
        while k > 0 and sort_value_count:
            freq = sort_value_count[0][1]
            if k >= freq:
                k -= freq
                sort_value_count.pop(0)
            else:
                break 

        return len(sort_value_count)
```