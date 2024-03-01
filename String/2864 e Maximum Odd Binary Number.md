# [2864. Maximum Odd Binary Number](https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01)

## Description

You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.

Note that the resulting string can have leading zeros.

**Example 1:**

```text
Input: s = "010"
Output: "001"
Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".
```

**Example 2:**

```text
Input: s = "0101"
Output: "1001"
Explanation: One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100". So the answer is "1001".
```

### Constraints:

- 1 <= s.length <= 100
- s[i] is either '0' or '1'.
- s contains at least one '1'.


## Solution

```python
class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        bits = s.count("1")
        res = ""
        lens = len(s)
        
        while bits > 1:
            res += "1"
            bits -= 1
            lens -= 1
        while lens > 1:
            res = res+"0"
            lens -= 1
        return res + "1"
```


```python
class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        bits1 = s.count("1")
        bits0 = len(s) - bits1

        return (bits1-1)*"1" + bits0*"0" + "1"
```
