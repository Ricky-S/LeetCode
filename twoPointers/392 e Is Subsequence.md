# 392. Is Subsequence

## Description

<p>Given two strings <code>s</code> and <code>t</code>, return <em>true</em> <em>if</em> <code>s</code> <em>is a <strong>subsequence</strong> of</em> <code>t</code><em>, or</em> <code>false</code> <em>otherwise</em>.</p>

<p>A <strong>subsequence</strong> of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., <code>&quot;ace&quot;</code> is a subsequence of <code>&quot;abcde&quot;</code> while <code>&quot;aec&quot;</code> is not).</p>

<p>&nbsp;</p>

example 1
```
Input: s = "abc", t = "ahbgdc"
Output: true
```

example 2
```
Input: s = "axc", t = "ahbgdc"
Output: false
```

Constraints:
```
0 <= s.length <= 100
0 <= t.length <= 10^4
s and t consist only of lowercase English letters.
```

## Idea:
1. two pointers
2. if the current character in s is equal to the current character in t, move both pointers forward.
3. if not, move the pointer in t forward.
4. return true if the pointer in s reaches the end.
5. return false if the pointer in t reaches the end.
6. time O(n), space O(1)


## Solution:

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        if (s.size() == 0) return true;
        while (j < t.size()) {
            if (t[j] == s[i]) {
                i++;
                j++;
            } else {
                j++;
            }
            if (i == s.size()) return true;
        }
        return false;
    }
};
```




```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i == s.size()) return true;
        else return false;
    }
};
```