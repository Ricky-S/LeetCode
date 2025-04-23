# [1399. Count Largest Group](https://leetcode.com/problems/count-largest-group/description/?envType=daily-question&envId=2025-04-23)

## Description

You are given an integer `n`.

Each number from `1` to `n` is grouped according to the sum of its digits.

Return *the number of groups that have the largest size*.

**Example 1:**

```
Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.

```

**Example 2:**

```
Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.

```

**Constraints:**

- `1 <= n <= 104`

## Solution

```python
class Solution:
    def countLargestGroup(self, n: int) -> int:
        d = defaultdict(int)
        for i in range(1, n+1):
            cnt = sum([int(k) for k in str(i)])
            # print(cnt, i)
            d[cnt] += 1
            
        cnt = 0
        for v in d.values():
            cnt = max(cnt, v)

        ans = 0
        for v in d.values():
            if v == cnt:
                ans += 1        
        return ans
```




