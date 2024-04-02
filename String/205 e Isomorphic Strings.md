# [205. Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/description/?envType=daily-question&envId=2024-04-02)

## Description

Given two strings `s` and `t`, determine if they are isomorphic.

Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


### Example 1:

```
Input: s = "egg", t = "add"
Output: true
```

### Example 2:

```
Input: s = "foo", t = "bar"
Output: false
```

### Example 3:

```
Input: s = "paper", t = "title"
Output: true
```

### Constraints:

- `1 <= s.length <= 5 * 10^4`
- `t.length == s.length`
- `s` and `t` consist of any valid ascii character.

## Solution

```python
def isIsomorphic(s: str, t: str) -> bool:
    s_dict = {}
    t_dict = {}
    for i in range(len(s)):
        if s[i] not in s_dict:
            s_dict[s[i]] = t[i]
        if t[i] not in t_dict:
            t_dict[t[i]] = s[i]
        if s_dict[s[i]] != t[i] or t_dict[t[i]] != s[i]:
            return False
    return True
```

```python
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        # Maps for character mapping from s to t and t to s
        map_st = {}
        map_ts = {}
        
        for char_s, char_t in zip(s, t):
            if (char_s in map_st and map_st[char_s] != char_t) or \
               (char_t in map_ts and map_ts[char_t] != char_s):
                return False

            map_st[char_s] = char_t
            map_ts[char_t] = char_s
        
        return True
```