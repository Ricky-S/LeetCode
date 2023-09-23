# 383. [Ransom Note](https://leetcode.com/problems/ransom-note/)

## 1. Description

Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:

```
Input: ransomNote = "a", magazine = "b"
Output: false
```

Example 2:

```
Input: ransomNote = "aa", magazine = "ab"
Output: false
```

Example 3:

```
Input: ransomNote = "aa", magazine = "aab"
Output: true
```

Constraints:

- 1 <= ransomNote.length, magazine.length <= 10^5

- ransomNote and magazine consist of lowercase English letters.

## 2. Solution

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (char c : magazine) {
            m[c]++;
        }
        for (char c : ransomNote) {
            if (m[c] == 0) return false;
            m[c]--;
        }
        return true;
    }
};
```

OR 

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m[26] = {0};
        for (char c : magazine) {
            m[c-'a']++;
        }
        for (char c : ransomNote) {
            if (m[c-'a'] == 0) return false;
            m[c-'a']--;
        }
        return true;
    }
};
```

or 

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap; 
        for (char c : magazine) {
            if (umap.find(c) == umap.end()) {
                umap[c] = 1;
            } else {
                umap[c]++;
            }
        }
        for (char c : ransomNote) {
            if (umap.find(c) == umap.end()) {
                return false;
            } else {
                umap[c]--;
                if (umap[c]<0) return false;
            }
        }
        return true;
    }
};
```