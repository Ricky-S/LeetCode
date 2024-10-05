# [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/description/?envType=daily-question&envId=2024-10-05)

## Description

Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation
of```s1```, or ```false``` otherwise.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.

**Example 1:**

```
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

```

**Example 2:**

```
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

```

**Constraints:**

- `1 <= s1.length, s2.length <= 104`
- `s1` and `s2` consist of lowercase English letters.

## Solution

```python
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n, m = len(s1), len(s2)
        if n > m:
            return False
        cnt1 = [0] * 26
        cnt2 = [0] * 26
        for i in range(n):
            cnt1[ord(s1[i]) - ord('a')] += 1
            cnt2[ord(s2[i]) - ord('a')] += 1
        if cnt1 == cnt2:
            return True
        for i in range(n, m):
            cnt2[ord(s2[i]) - ord('a')] += 1
            cnt2[ord(s2[i - n]) - ord('a')] -= 1
            if cnt1 == cnt2:
                return True
        return False
```

```python
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        dic = {}
        for i in range(26):
            dic[chr(ord('a') + i)] = 0
        for i in s1:
            dic[i] += 1
        for i in range(len(s1)):
            dic[s2[i]] -= 1
        if all(value == 0 for value in dic.values()):
            return True
        for i in range(len(s1), len(s2)):
            dic[s2[i-len(s1)]] += 1
            dic[s2[i]] -= 1
            if all(value == 0 for value in dic.values()):
                return True            
        return False
```

