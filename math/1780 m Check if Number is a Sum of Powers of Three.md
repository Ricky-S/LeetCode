# [1780. Check if Number is a Sum of Powers of Three](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/?envType=daily-question&envId=2025-03-04)


## Description


Given an integer `n`, return `true` *if it is possible to represent* `n` *as the sum of distinct powers of three.* Otherwise, return `false`.

An integer `y` is a power of three if there exists an integer `x` such that `y == 3x`.

**Example 1:**

```
Input: n = 12
Output: true
Explanation: 12 = 31 + 32
```

**Example 2:**

```
Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34
```

**Example 3:**

```
Input: n = 21
Output: false

```

**Constraints:**

- `1 <= n <= 107`


## Solution

```python
class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        l3 = []
        for i in range(20):
            temp = 3 ** i
            if temp < 10000000:
                l3.append(temp)
        # print(l3)
        if n >= l3[-1]:
            n -= l3[-1]
            if n >= l3[-1]:
                return False
        # print(n)
        seen = set()
        while n > 0:
            for i in range(len(l3)-1):
                if n < l3[i+1]:
                    n -= l3[i]
                    # print(n)
                    if i in seen:
                        return False
                    else:
                        seen.add(i)
                    break
        return True
```


