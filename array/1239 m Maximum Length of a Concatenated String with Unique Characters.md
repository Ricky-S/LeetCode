# [1239. Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23)

## Description

You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

## Examples

Example 1:

```
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
- "unique" ("un" + "iq" + "ue")
Maximum length is 4.
```

Example 2:

```
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
```

Example 3:

```
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
```

## Constraints

- 1 <= arr.length <= 16
- 1 <= arr[i].length <= 26
- arr[i] contains only lower case English letters.

## Solution

```python
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        dp = [set()]

        for a in arr:
            if len(set(a)) != len(a):
                continue
            a = set(a)
            for c in dp:
                if a & c:
                    continue
                else:
                    dp.append(a | c)
        return max(len(a) for a in dp)

```