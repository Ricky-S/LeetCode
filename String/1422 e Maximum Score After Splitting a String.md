# [1422. Maximum Score After Splitting a String](https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2023-12-22)

## Description

Given a string `s` of zeros and ones, *return the **maximum score** after splitting the string into **two **non-empty substrings* (i.e. **left** substring and **right** substring).

The **score** after splitting a string is the number of **zeros** in the **left** substring plus the number of **ones** in the **right** substring.


### Examples

Example 1:

```

Input: s = "011101"
Output: 5
Explanation:
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5
left = "01" and right = "1101", score = 1 + 3 = 4
left = "011" and right = "101", score = 1 + 2 = 3
left = "0111" and right = "01", score = 1 + 1 = 2
left = "01110" and right = "1", score = 2 + 1 = 3

```

Example 2:

```

Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5

```

Example 3:

```

Input: s = "1111"
Output: 3

```

### Constraints

- `2 <= s.length <= 500`

- The string `s` consists of characters '0' and '1' only.

## Solution

```python
class Solution:
    def maxScore(self, s: str) -> int:
        max_score = 0
        for i in range(1, len(s)):
            left = s[:i]
            right = s[i:]
            score = left.count('0') + right.count('1')
            if score > max_score:
                max_score = score
        return max_score
```

```python
class Solution:
    def maxScore(self, s: str) -> int:
        if s[0] == '0':
            left_ans = 1
        else:
            left_ans = 0
        
        right_ans = 0
        for ch in s[1:]:
            if ch == '1':
                right_ans += 1
        
        ans = left_ans + right_ans
        for ch in s[1:-1]:
            if ch == '0':
                left_ans += 1
            else:
                right_ans -= 1
            ans = max(ans, left_ans + right_ans)
        # print(left_ans)
        # print(right_ans)
        return ans

```

```python
def solution(s):
	zeros = 1 if s[0] == '0' else 0
	ones = s.count('1', 1)  # count 1s in s[1:]
	score = zeros + ones
	for i in xrange(1, len(s) - 1):
		if s[i] == '0':
			zeros += 1
		else:
			ones -= 1
		score = max(zeros + ones,  score)
	return score
```