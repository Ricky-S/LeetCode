# [2490. Circular Sentence](https://leetcode.com/problems/circular-sentence/description/?envType=daily-question&envId=2024-11-02)

## Description

A **sentence** is a list of words that are separated by a **single** space with no leading or trailing spaces.

- For example, `"Hello World"`, `"HELLO"`, `"hello world hello world"` are all sentences.

Words consist of **only** uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.

A sentence is **circular** if:

- The last character of a word is equal to the first character of the next word.
- The last character of the last word is equal to the first character of the first word.

For example, `"leetcode exercises sound delightful"`, `"eetcode"`, `"leetcode eats soul"` are all circular sentences. However, `"Leetcode is cool"`, `"happy Leetcode"`, `"Leetcode"` and `"I like Leetcode"` are **not** circular sentences.

Given a string `sentence`, return `true` *if it is circular*. Otherwise, return `false`.

**Example 1:**

```
Input: sentence = "leetcode exercises sound delightful"
Output: true
Explanation: The words in sentence are ["leetcode", "exercises", "sound", "delightful"].
- leetcode's last character is equal toexercises's first character.
- exercises's last character is equal tosound's first character.
- sound's last character is equal todelightful's first character.
- delightful's last character is equal toleetcode's first character.
The sentence is circular.
```

**Example 2:**

```
Input: sentence = "eetcode"
Output: true
Explanation: The words in sentence are ["eetcode"].
- eetcode's last character is equal toeetcode's first character.
The sentence is circular.
```

**Example 3:**

```
Input: sentence = "Leetcode is cool"
Output: false
Explanation: The words in sentence are ["Leetcode", "is", "cool"].
- Leetcode's last character isnot equal tois's first character.
The sentence isnot circular.
```

**Constraints:**

- `1 <= sentence.length <= 500`
- `sentence` consist of only lowercase and uppercase English letters and spaces.
- The words in `sentence` are separated by a single space.
- There are no leading or trailing spaces.


## Solution

```python
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        li = sentence.split(" ")
        li.append(li[0])

        for i in range(len(li)-1):
            if li[i][-1] == li[i+1][0]:
                pass
            else:
                return False
        return True
```

