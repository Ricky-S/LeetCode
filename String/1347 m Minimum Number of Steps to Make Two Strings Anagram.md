# [1347. Minimum Number of Steps to Make Two Strings Anagram](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=daily-question&envId=2024-01-13)

## Description

Given two equal-size strings `s` and `t`. In one step you can choose **any character** of `t` and replace it with **another character**.

Return *the minimum number of steps* to make `t` an anagram of `s`.

An **Anagram** of a string is a string that contains the same characters with a different (or the same) ordering.


### Example 1:

```
Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
```

### Example 2:

```
Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
```

### Example 3:

```
Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams. 
```

## Constraints:

* `1 <= s.length <= 50000`
* `s.length == t.length`
* `s` and `t` contain lower-case English letters only.

## Solution

```python
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        count = 0
        for i in set(s):
            count += abs(s.count(i) - t.count(i))
        return count//2
```

```python
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        chara = {}
        for ch in s:
            if ch in chara:
                chara[ch] += 1
            else:
                chara[ch] = 1
        
        for ch in t:
            if ch in chara:
                chara[ch] -= 1
            else:
                chara[ch] = -1
        
        return int (sum(abs(value) for value in chara.values())/2)
        
```