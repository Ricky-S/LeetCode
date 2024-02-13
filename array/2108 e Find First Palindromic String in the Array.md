# [2108. Find First Palindromic String in the Array](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=daily-question&envId=2024-02-13)

## Description

Given a list of strings `words`, return the first string that is a palindrome when read from right to left and left to right.

If there is no palindrome in `words`, return an empty string `""`.

A string `s` is a palindrome if it is the same when read forwards and backwards.

### Example 1:

```
Input: words = ["a","b","c"]
Output: "a"
```

### Example 2:

```
Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
```

### Example 3:

```
Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".
```


### Example 4:

```
Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.
```


## Constraints

- `1 <= words.length <= 100`

- `1 <= words[i].length <= 100`

- `words[i]` consists of lowercase English letters.

## Solution

```python
class Solution:
    def findFirstPalindromic(self, words: List[str]) -> str:
        for word in words:
            if word == word[::-1]:
                return word
        return ""
```

```python
class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            length = len(word)
            if length == 1:
                return word
            for i in range(length//2):
                if word[i] != word[length-1-i]:
                    break
                if i == length//2-1:
                    return word
        return ""
```

```python
class Solution:
    
    def is_palindromic(self, word):
        length = len(word)
        for i in range(length//2):
            if word[i] != word[length-1-i]:
                return False
        return True

    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            check = self.is_palindromic(word)
            if check:
                return word
        return ""
```