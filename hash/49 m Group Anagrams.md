# 49. Group Anagrams

## Description

Given an array of strings `strs`, group **the anagrams** together. You can return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**

```

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

```

**Example 2:**

```
Input: strs = [""]
Output: [[""]]
```

**Example 3:**

```
Input: strs = ["a"]
Output: [["a"]]
```

**Constraints:**

- `1 <= strs.length <= 10^4`
- `0 <= strs[i].length <= 100`

Idea:

unordered map to check the mapping.

```cpp

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> res;
        for (string str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            umap[tmp].push_back(str);
        }
        for (auto it = umap.begin(); it != umap.end(); it++) {
            res.push_back(it->second);
        }
        // OR
        // for (auto& p : umap) { 
        //     result.push_back(p.second);
        // }   
        // OR
        // for (auto& [key, value] : umap) {
        //     result.push_back(value);
        // }
        return res;
    }
};

```