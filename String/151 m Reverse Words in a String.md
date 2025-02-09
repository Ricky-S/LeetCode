# [151. Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/description/)

## Description

Given an input string s, reverse the order of the **words**.

A **word** is defined as a sequence of non-space characters. The **words** in s will be separated by at least one space.

Return *a string of the words in reverse order concatenated by a single space*.

**Note** that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.


Example 1:

```
Input: s = "the sky is blue"
Output: "blue is sky the"
```

Example 2:

```
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

Example 3:

```
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

Constraints:

- 1 <= s.length <= 10^4


- s contains English letters (upper-case and lower-case), digits, and spaces ' '.


- There is at least one word in s.


Idea:

find the first non-space character, then find the first space character, then reverse the substring, then repeat the process until the end of the string.


Time Complexity: O(n)

Space Complexity: O(n)

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int i = 0;
        while (i < s.size()) {
            while (i < s.size() && s[i] == ' ') {
                i++;
            }
            if (i >= s.size()) {
                break;
            }
            int j = i + 1;
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            string sub = s.substr(i, j - i);
            if (res.size() == 0) {
                res = sub;
            } else {
                res = sub + " " + res;
            }
            i = j + 1;
        }
        return res;
    }
};
```

My Solution:

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int start = 0;
        int end = 0;
        // vector<string> temp;
        string res;
        while (i < s.size()) {
            if(s[i] == ' ') i++;
            else {
                start = i;
                while(s[i] != ' ' && i < s.size() ) {
                    i++;
                }
                end = i-1;
                res = s.substr(start, end-start+1) + ' ' + res;
                // temp.push_back(s.substr(start, end-start+1));
                // cout << s.substr(start, end-start+1) << endl;
            }
        }
        // reverse(temp.begin(), temp.end());
        // for (string str : temp) {
        //     res += str + ' ';
        // }
        res.pop_back();
        return res;
    }
};
```

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        l = s.split(' ')
        l2 = []
        for i in l:
            if i != "":
                l2.append(i)
                # l2.append(" ")
        # print(" ".join(l2[::-1]))
        return " ".join(l2[::-1])
```

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.split()[::-1])
```



