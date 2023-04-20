A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.


Example 1:\
```cpp
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
```

Example 2:\
```cpp
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
```

example 3
```cpp
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
```

Idea:\
find isalnum and add to a new string with all lower cases.
then check whether the new string is a palindrome.

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        string combine{""};

        for (int i = 0; i<s.size(); i++) {
            if (isalnum(s[i])) combine.push_back(tolower(s[i]));
        }
        cout << combine << endl;
        for (int i = 0; i<combine.size()/2; i++) {
            if (combine[i] != combine[combine.size()-i-1]) return false;
        }
        return true;
    }
};
```








