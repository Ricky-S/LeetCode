# [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/description/?envType=daily-question&envId=2024-02-06)

## Description

Given an array of strings, group anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

## Example 1

```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```



## Example 2

```
Input: strs = [""]
Output: [[""]]
```

## Example 3

```
Input: strs = ["a"]
Output: [["a"]]
```

## Constraints

- 1 <= strs.length <= 10^4
- 0 <= strs[i].length <= 100
- strs[i] consists of lower-case English letters.

## Solution

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for s in strs:
            key = ''.join(sorted(s))
            if key not in d:
                d[key] = [s]
            else:
                d[key].append(s)
        return list(d.values())
```

