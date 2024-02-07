# [451. Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/description/)

## Description

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

### Example 1:

```
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once. So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
```

### Example 2:

```
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'a' and 'c' appear three times, so "aaaccc" is also a valid answer. Note that "cacaca" is incorrect, as the same characters must be together.
```

### Example 3:

```
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect. Note that 'A' and 'a' are treated as two different characters.
```

### Constraints:

* 1 <= s.length <= 5 * 10^5
* s consists of uppercase and lowercase English letters and digits.

## Solution

```python
class Solution:
    def frequencySort(self, s: str) -> str:
        # Step 1: Count the frequency of each character
        # freq_dict = {}
        # for char in s:
        #     freq_dict[char] = freq_dict.get(char, 0) + 1
        freq_dict = Counter(s)
        # Step 2: Sort the characters by frequency
        sorted_chars = sorted(freq_dict, key=lambda x: freq_dict[x], reverse=True)

        # Step 3: Construct the result string
        result = ""
        for char in sorted_chars:
            result += char * freq_dict[char]

        return result
```

```python
class Solution:
    def frequencySort(self, s: str) -> str:
        return ''.join([i[0]*i[1] for i in sorted(Counter(s).items(), key=lambda x: -x[1])])
```