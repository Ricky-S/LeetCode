# 58. Length of Last Word

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:
``` 
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
```

Example 2:
```
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
```

Example 3:
```
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
```

Constraints:
1 <= s.length <= 10^4
s consists of only English letters and spaces ' '.
There will be at least one word in s.

Idea:
```
1. find the last space in the string.
2. return the length of the last word.
```

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        while (i >= 0 && s[i] == ' ') i--;
        int j = i;
        while (j >= 0 && s[j] != ' ') j--;
        return i-j;
    }
};
```
OR
```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int check = 0;
        for(int i = 0; i < s.size(); i++){
            if (s[i] ==' ') {
                len = 0;
                check++;
            }else {
                len++;
                check = 0;
            }
        }
        if (check == 0) { // last is the word
            return len;
        } else { //last is not the word
            for(int i = 0; i < s.size()-check; i++){
                if (s[i] ==' ') {
                    len = 0;
                }else {
                    len++;
                }
            }   
                     
        }
        return len;
    }
};
```
