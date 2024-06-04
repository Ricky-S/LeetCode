# [409. Longest Palindrome](https://leetcode.com/problems/longest-palindrome/description/?envType=daily-question&envId=2024-06-04)

## Description

Given a string `s` which consists of lowercase or uppercase letters, return the length of the **longest**

**palindrome**

that can be built with those letters.

Letters are **case sensitive**, for example, `"Aa"` is not considered a palindrome.

**Example 1:**

```
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

```

**Example 2:**

```
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

```

**Constraints:**

- `1 <= s.length <= 2000`
- `s` consists of lowercase **and/or** uppercase English letters only.

## Solution

```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        count = 0
        for v in collections.Counter(s).values():
            count += v // 2 * 2
            if count % 2 == 0 and v % 2 == 1:
                count += 1
        return count
```

```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        dic = {}
        res = 0
        for ch in s:
            if ch in dic:
                res += 2
                del dic[ch]
            else:
                dic[ch] = 1
        return res + (1 if len(dic) != 0 else 0)
```
