# [1717. Maximum Score From Removing Substrings](https://leetcode.com/problems/maximum-score-from-removing-substrings/description/?envType=daily-question&envId=2025-07-23)

## Description

You are given a string `s` and two integers `x` and `y`. You can perform two types of operations any number of times.

- Remove substring `"ab"` and gain `x` points.
    - For example, when removing `"ab"` from `"cabxbae"` it becomes `"cxbae"`.
- Remove substring `"ba"` and gain `y` points.
    - For example, when removing `"ba"` from `"cabxbae"` it becomes `"cabxe"`.

Return *the maximum points you can gain after applying the above operations on* `s`.

**Example 1:**

```
Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
```

**Example 2:**

```
Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20

```

**Constraints:**

- `1 <= s.length <= 105`
- `1 <= x, y <= 104`
- `s` consists of lowercase English letters.


## Solution

```python
class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        if x > y:
            sub1, sub2, max_p, min_p = "a", "b", x, y
        else:
            sub1, sub2, max_p, min_p = "b", "a", y, x

        stack = []
        ans = 0
        for i in range(len(s)):
            if stack and stack[-1] == sub1 and s[i] == sub2:
                stack.pop()
                ans += max_p
            else:
                stack.append(s[i])
        #     print(stack)
        #     print(ans)
        # print(stack)
        stack2 = []
        for i in range(len(stack)):
            if stack2 and stack2[-1] == sub2 and stack[i] == sub1:
                stack2.pop()
                ans += min_p
            else:
                stack2.append(stack[i])
            # print(stack2)
        return ans
```