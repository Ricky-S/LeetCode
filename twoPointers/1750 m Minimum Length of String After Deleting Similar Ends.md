# [1750. Minimum Length of String After Deleting Similar Ends](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05)

## description

Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:

Pick a non-empty prefix from the string s where all the characters in the prefix are equal.

Pick a non-empty suffix from the string s where all the characters in this suffix are equal.

The prefix and the suffix should not intersect at any index.

The characters from the prefix and suffix must be the same.

Delete both the prefix and the suffix.

Return the minimum length of s after performing the above operation any number of times (possibly zero times).

### Example 1:

```text
Input: s = "ca"
Output: 2
Explanation: You can't remove any characters, so the string stays as is.
```

### Example 2:

```text
Input: s = "cabaabac"
Output: 0
Explanation: An optimal sequence of operations is:

- Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
- Take prefix = "a" and suffix = "a" and remove them, s = "baab".
- Take prefix = "b" and suffix = "b" and remove them, s = "aa".
- Take prefix = "a" and suffix = "a" and remove them, s = "".
```

### Example 3:

```text
Input: s = "aabccabba"
Output: 3

Explanation: An optimal sequence of operations is:

- Take prefix = "aa" and suffix = "a" and remove them, s = "bccabb".
- Take prefix = "b" and suffix = "bb" and remove them, s = "cca".
```

### Constraints:

- 1 <= s.length <= 10^5
- s only consists of characters 'a', 'b', and 'c'.


### Solution:

```python
class Solution:
    def minimumLength(self, s: str) -> int:
        l, r = 0, len(s) - 1
        while l < r and s[l] == s[r]:
            c = s[l]
            while l <= r and s[l] == c:
                l += 1
            while l <= r and s[r] == c:
                r -= 1
        return r - l + 1
```

```python
class Solution:
    def minimumLength(self, s: str) -> int:
        left = 0
        right = len(s)-1
        # res = s
        while left < right and s[left] == s[right]:
            current = s[left]
            while left <= right and current == s[left]:
                left += 1
            while left <= right and current == s[right]:
                right -= 1
        # print(f"left: {left}, right: {right}")
        return right-left+1 if left <= right else 0

```