# [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)


## description

Given a string `s`, find the length of the **longest substring** without repeating characters.

**Example 1:**

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

**Example 2:**

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
```

Constraints:

- `0 <= s.length <= 5 * 10^4`


- `s` consists of English letters, digits, symbols and spaces.


Idea:

1. Sliding Window


## solution

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int res = 0;
        unordered_map<char, int> m;
        while (r < n) {
            m[s[r]]++;
            while (m[s[r]] > 1) {
                m[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
```

My solution:

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int length = 0;
        int res = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if(umap.find(s[i]) == umap.end()) {
                length++;
                umap[s[i]] = i;
            } else {
                if(i - umap[s[i]] > length) length++;
                else length = i - umap[s[i]];
                umap[s[i]] = i;
            }
            // cout << length << endl;
            res = max(res, length);
        }
        return res;
    }
};
```

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char = {}
        res = 0
        length = 0
        for i in range(len(s)):
            if s[i] not in char:
                length += 1
            else:
                if i -char[s[i]] > length:
                    length += 1
                else:
                    length = i - char[s[i]]
            char[s[i]] = i      
            res = max(res, length)
        return res 