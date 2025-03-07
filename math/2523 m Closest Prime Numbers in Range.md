# [2523. Closest Prime Numbers in Range](https://leetcode.com/problems/closest-prime-numbers-in-range/description/?envType=daily-question&envId=2025-03-07)

## Description


Given two positive integers `left` and `right`, find the two integers `num1` and `num2` such that:

- `left <= num1 < num2 <= right` .
- Both `num1` and `num2` are .
    
    prime numbers
    
- `num2 - num1` is the **minimum** amongst all other pairs satisfying the above conditions.

Return the positive integer array `ans = [num1, num2]`. If there are multiple pairs satisfying these conditions, return the one with the **smallest** `num1` value. If no such numbers exist, return `[-1, -1]`*.*

**Example 1:**

```
Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.

```

**Example 2:**

```
Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.

```

**Constraints:**

- `1 <= left <= right <= 106`


## Solution

```python
class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        s = [True] * (right+1)

        s[0] = s[1] = False

        for i in range(2, right+1):
            if s[i]:
                for k in range(i*i, right+1, i):
                    s[k] = False
        # print(s)
        prime = [i for i in range(left, right+1) if s[i]]
        # print(prime)
        if len(prime) < 2:
            return [-1, -1]
        min_value = right - left + 1    
        for i in range(len(prime)-1):
            if prime[i+1] - prime[i] < min_value:
                min_value = prime[i+1] - prime[i]
                ans = [prime[i], prime[i+1]]
        return ans
```







