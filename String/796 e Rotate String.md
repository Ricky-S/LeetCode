# [796. Rotate String](https://leetcode.com/problems/rotate-string/description/?envType=daily-question&envId=2024-11-03)


## Description

Easy

Topics

Companies

Given two strings `s` and `goal`, return `true` *if and only if* `s` *can become* `goal` *after some number of **shifts** on* `s`.

A **shift** on `s` consists of moving the leftmost character of `s` to the rightmost position.

- For example, if `s = "abcde"`, then it will be `"bcdea"` after one shift.

**Example 1:**

```
Input: s = "abcde", goal = "cdeab"
Output: true

```

**Example 2:**

```
Input: s = "abcde", goal = "abced"
Output: false

```

**Constraints:**

- `1 <= s.length, goal.length <= 100`
- `s` and `goal` consist of lowercase English letters.

## Solution

```python
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        return len(s) == len(goal) and goal in s + s
```

```python
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        for i in range(len(s)):
            if s[i:] + s[:i] == goal:
                return True
        return False
```

```python
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        return goal in s + s
```

```python
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        if goal in s+s:
            return True
        else:
            return False
```
