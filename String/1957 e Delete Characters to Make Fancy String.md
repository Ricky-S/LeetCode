# [1957. Delete Characters to Make Fancy String](https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2024-11-01)


## Description

A **fancy string** is a string where no **three** **consecutive** characters are equal.

Given a string `s`, delete the **minimum** possible number of characters from `s` to make it **fancy**.

Return *the final string after the deletion*. It can be shown that the answer will always be **unique**.

**Example 1:**

```
Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".

```

**Example 2:**

```
Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".

```

**Example 3:**

```
Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".

```

**Constraints:**

- `1 <= s.length <= 105`
- `s` consists only of lowercase English letters.


## Solution

```python
class Solution:
    def makeFancyString(self, s: str) -> str:
        res = []
        for c in s:
            if len(res) < 2 or c != res[-1] or c != res[-2]:
                res.append(c)
        return ''.join(res)
```

```python
class Solution:
    def makeFancyString(self, s: str) -> str:
        if len(s) <= 2:
            return s

        li = []
        li.append(s[0])
        li.append(s[1])

        for i in s[2:]:
            if i == li[-1] and i == li[-2]:
                pass
            else:
                li.append(i)

        return "".join(li)
```