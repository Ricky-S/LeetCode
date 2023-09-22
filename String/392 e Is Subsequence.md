# [392. Is Subsequence](https://leetcode.com/problems/is-subsequence/)

## Description

Given two strings `s` and `t`, return `true` *if `s` is a **subsequence** of `t`*, or `false` otherwise.


A **subsequence** of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., `"ace"` is a subsequence of `"abcde"` while `"aec"` is not).


Example 1:

```
Input: s = "abc", t = "ahbgdc"
Output: true
```

Example 2:

```
Input: s = "axc", t = "ahbgdc"
Output: false
```

Constraints:

- `0 <= s.length <= 100`

- `0 <= t.length <= 104`

- `s` and `t` consist only of lowercase English letters.

## Solution

idea:\

use two pointers to compare the two strings.

```cpp

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == s.size();
    }
};

```

OR
    
```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        if (s.size() == 0 && t.size() == 0) return true;
        for (i = 0; i < t.size(); i++) {
            if(t[i] == s[j]) {
                j++;
            }
            if (j == s.size()) return true;
        }   
        return false;
    }
};
```