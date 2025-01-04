# [1930. Unique Length-3 Palindromic Subsequences](https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-01-04)

## Description

Given a string `s`, return *the number of **unique palindromes of length three** that are a **subsequence** of* `s`.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted **once**.

A **palindrome** is a string that reads the same forwards and backwards.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

- For example, `"ace"` is a subsequence of `"abcde"`.

**Example 1:**

```
Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")

```

**Example 2:**

```
Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".

```

**Example 3:**

```
Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")

```

**Constraints:**

- `3 <= s.length <= 105`
- `s` consists of only lowercase English letters.


## Solution

```python
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        res = 0
        for c in string.ascii_lowercase:
            i, j = s.find(c), s.rfind(c)
            if i != -1:
                res += len(set(s[i + 1:j]))
        return res
```

```python
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        letters = set()
        len3 = set()
        ans = 0
        for i in range(len(s)):
            if s[i] not in letters:
                letters.add(s[i])
                last = len(s)-1
                while s[last] != s[i]:
                    last -= 1
                for j in range(i+1, last):
                    sub = s[i] + s[j] + s[last]
                    if sub not in len3:
                        # print(sub)
                        len3.add(sub)
                        ans += 1
        return ans
```