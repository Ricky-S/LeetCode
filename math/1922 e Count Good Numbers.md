# [1922. Count Good Numbers](https://leetcode.com/problems/count-good-numbers/description/?envType=daily-question&envId=2025-04-13)

## Description


A digit string is **good** if the digits **(0-indexed)** at **even** indices are **even** and the digits at **odd** indices are **prime** (`2`, `3`, `5`, or `7`).

- For example, `"2582"` is good because the digits (`2` and `8`) at even positions are even and the digits (`5` and `2`) at odd positions are prime. However, `"3245"` is **not** good because `3` is at an even index but is not even.

Given an integer `n`, return *the **total** number of good digit strings of length* `n`. Since the answer may be large, **return it modulo** `109 + 7`.

A **digit string** is a string consisting of digits `0` through `9` that may contain leading zeros.

**Example 1:**

```
Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

```

**Example 2:**

```
Input: n = 4
Output: 400

```

**Example 3:**

```
Input: n = 50
Output: 564908303

```

**Constraints:**

- `1 <= n <= 1015`

## Solution

```python
class Solution:
    def countGoodNumbers(self, n: int) -> int:
        MOD = 10**9 + 7
        even_digits = "02468"
        prime_digits = "2357"
        even_count = n // 2
        prime_count = n // 2
        if n % 2 == 1:
            prime_count += 1
        result = (pow(len(even_digits), even_count, MOD) * pow(len(prime_digits), prime_count, MOD)) % MOD
        return result
```


```python
class Solution:
    def countGoodNumbers(self, n: int) -> int:
        mod = 10**9 + 7
        even = (n + 1) // 2
        odd = n // 2
        return (pow(5, even, mod) * pow(4, odd, mod)) % mod
```














