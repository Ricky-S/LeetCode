# [884. Uncommon Words from Two Sentences](https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=daily-question&envId=2024-09-17)

## Description

A **sentence** is a string of single-space separated words where each word consists only of lowercase letters.

A word is **uncommon** if it appears exactly once in one of the sentences, and **does not appear** in the other sentence.

Given two **sentences** `s1` and `s2`, return *a list of all the **uncommon words***. You may return the answer in **any order**.

**Example 1:**

**Input:** s1 = "this apple is sweet", s2 = "this apple is sour"

**Output:** ["sweet","sour"]

**Explanation:**

The word `"sweet"` appears only in `s1`, while the word `"sour"` appears only in `s2`.

**Example 2:**

**Input:** s1 = "apple apple", s2 = "banana"

**Output:** ["banana"]

**Constraints:**

- `1 <= s1.length, s2.length <= 200`
- `s1` and `s2` consist of lowercase English letters and spaces.
- `s1` and `s2` do not have leading or trailing spaces.
- All the words in `s1` and `s2` are separated by a single space.


## Solution

```python
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        words = s1.split() + s2.split()
        counter = collections.Counter(words)
        return [word for word, count in counter.items() if count == 1]
```

```python
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        s1_list = s1.split(" ")
        s2_list = s2.split(" ")
        s1_dict = Counter(s1_list)
        s2_dict = Counter(s2_list)
        res = []
        for key, value in s1_dict.items():
            if value == 1:
                if key not in s2_dict:
                    res.append(key)
        for key, value in s2_dict.items():
            if value == 1:
                if key not in s1_dict:
                    res.append(key)        

        return res
```