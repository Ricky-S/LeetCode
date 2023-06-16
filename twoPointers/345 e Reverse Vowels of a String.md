# [345. Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/description/)


## description

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

**Example 1:**

```text
Input: s = "hello"
Output: "holle"
```

**Example 2:**

```text
Input: s = "leetcode"
Output: "leotcede"
```

**Constraints:**

- 1 <= s.length <= 3 * 10^5
- s consist of printable ASCII characters.


## Idea:

1. two pointers


## Solution:

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isVowel(s[i])) i++;
            while (i < j && !isVowel(s[j])) j--;
            swap(s[i++], s[j--]);
        }
        return s;
    }
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};
```

My solution:

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size();
        vector<char> Vowels = { 'a', 'e', 'i', 'o', 'u' };
        while (i<j) {
            while(i<j && !count(Vowels.begin(), Vowels.end(), tolower(s[i]))) {
                i++;
            }
            while(i<j && !count(Vowels.begin(), Vowels.end(), tolower(s[j]))) {
                j--;
            }
            // cout << i << j << endl;
            swap(s[i++], s[j--]);      
        }
        return s;
    }
};

