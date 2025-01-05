# [2381. Shifting Letters II](https://leetcode.com/problems/shifting-letters-ii/description/?envType=daily-question&envId=2025-01-05)

## Description

You are given a string `s` of lowercase English letters and a 2D integer array `shifts` where `shifts[i] = [starti, endi, directioni]`. For every `i`, **shift** the characters in `s` from the index `starti` to the index `endi` (**inclusive**) forward if `directioni = 1`, or shift the characters backward if `directioni = 0`.

Shifting a character **forward** means replacing it with the **next** letter in the alphabet (wrapping around so that `'z'` becomes `'a'`). Similarly, shifting a character **backward** means replacing it with the **previous** letter in the alphabet (wrapping around so that `'a'` becomes `'z'`).

Return *the final string after all such shifts to* `s` *are applied*.

**Example 1:**

```
Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
Output: "ace"
Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".
```

**Example 2:**

```
Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
Output: "catz"
Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".

```

**Constraints:**

- `1 <= s.length, shifts.length <= 5 * 104`
- `shifts[i].length == 3`
- `0 <= starti <= endi < s.length`
- `0 <= directioni <= 1`
- `s` consists of lowercase English letters.


## Solution


```python
class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        index = [0 for _ in range(n+1)]

        for shift in shifts:
            if shift[2] == 1:
                index[shift[0]] += 1
                # if shift[1]+1 < n:
                index[shift[1]+1] -= 1
                # for i in range(shift[0], shift[1]+1):
                #     index[i] += 25
            else:
                index[shift[0]] -= 1
                # if shift[1]+1 < n:
                index[shift[1]+1] += 1
                # for i in range(shift[0], shift[1]+1):
                #     index[i] += 1  
            # print(index)
        ans = ""
        for i in range(1, len(index)):
            index[i] = index[i-1] + index[i]
        # print(index)
        
        for i in range(len(s)):
            ans += chr((ord(s[i])-97+index[i]%26+26)%26+97)
        return ans
```