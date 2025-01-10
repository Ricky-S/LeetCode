# [916. Word Subsets](https://leetcode.com/problems/word-subsets/description/?envType=daily-question&envId=2025-01-10)

## Description


You are given two string arrays `words1` and `words2`.

A string `b` is a **subset** of string `a` if every letter in `b` occurs in `a` including multiplicity.

- For example, `"wrr"` is a subset of `"warrior"` but is not a subset of `"world"`.

A string `a` from `words1` is **universal** if for every string `b` in `words2`, `b` is a subset of `a`.

Return an array of all the **universal** strings in `words1`. You may return the answer in **any order**.

**Example 1:**

```
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]

```

**Example 2:**

```
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]

```

**Constraints:**

- `1 <= words1.length, words2.length <= 104`
- `1 <= words1[i].length, words2[i].length <= 10`
- `words1[i]` and `words2[i]` consist only of lowercase English letters.
- All the strings of `words1` are **unique**.


## Solution

```python
class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:

        dic = {}
        for w in words2:
            d = Counter(w)
            for key, value in d.items():
                if key in dic:
                    if value > dic[key]:
                        dic[key] = value
                else:
                    dic[key] = value

        ans = []
        for i in words1:
            d = Counter(i)
            for key, value in dic.items():
                if key not in d:
                    break
                if d[key] < value:
                    break
            else:
                ans.append(i)
        return ans
```
