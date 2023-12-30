# [1897. Redistribute Characters to Make All Strings Equal](https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/?envType=daily-question&envId=2023-12-30)

## Description

You are given an array of strings `words` (0-indexed).

In one operation, pick two **distinct** indices `i` and `j`, where `words[i]` is a non-empty string, and move **any** character from `words[i]` to **any** position in `words[j]`.

Return `true` *if you can make **every** string in* `words` *equal using **any** number of operations*, *and* `false` *otherwise*.

### Example 1:

```
Input: words = ["abc","aabc","bc"]
Output: true
Explanation: Move the first 'a' in words[1] to the front of words[2],
to make words[1] = "abc" and words[2] = "abc".
All the strings are now equal to "abc", so return true.
```

### Example 2:

```
Input: words = ["ab","a"]
Output: false
Explanation: It is impossible to make all the strings equal using the operation.
```

### Constraints:

- `1 <= words.length <= 100`
- `1 <= words[i].length <= 100`
- `words[i]` consists of lowercase English letters.

## Solution:

```python
class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        n = len(words)
        if n == 1:
            return True
        dic = {}
        for word in words:
            for char in word:
                if char not in dic:
                    dic[char] = 1
                else:
                    dic[char] += 1
        for key in dic:
            if dic[key] % n != 0:
                return False
        return True
```

```python
class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        if len(words) == 1:
            return True
        
        array = [0] * 26
        for word in words:
            for ch in word:
                array[ord(ch) - ord('a')] += 1
        
        count = -1
        for ch in array:
            if ch !=0 and count == -1:
                count = ch
                # if count == 1:
                #     return False
            if ch != 0 and (ch % len(words)) != 0:
                return False
        return True
```