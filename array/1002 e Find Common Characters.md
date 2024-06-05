# [1002. Find Common Characters](https://leetcode.com/problems/find-common-characters/description/?envType=daily-question&envId=2024-06-05)

## Description

Given a string array `words`, return *an array of all characters that show up in all strings within the* `words` *(including duplicates)*. You may return the answer in **any order**.

**Example 1:**

```
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

```

**Example 2:**

```
Input: words = ["cool","lock","cook"]
Output: ["c","o"]

```

**Constraints:**

- `1 <= words.length <= 100`
- `1 <= words[i].length <= 100`
- `words[i]` consists of lowercase English letters.



## Solution

```python
class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        res = []
        for ch in set(words[0]):
            count = min([word.count(ch) for word in words])
            res.extend([ch] * count)
        return res
```

```python
class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        merged_dic = defaultdict(list)
        res = []
        
        for word in words:
            dic = Counter(word)
            for key, value in dic.items():
                merged_dic[key].append(value)

        for key, value in merged_dic.items():
            if len(value) == len(words):
                res.extend([key] * min(value))

        return res
```