# 1456. Maximum Number of Vowels in a Substring of Given Length

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

ex1
```cpp
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
```

ex2
```cpp
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
```

ex3
```cpp
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
```

Constraints\
```cpp
1 <= s.length <= 10^5
s consists of lowercase English letters.
1 <= k <= s.length
```

idea:

calculate "count" in first k elements.

then pop first and push last element.

```cpp
class Solution {
public:
    int maxVowels(string s, int k) {
        int index1 {0};
        int count = 0;
        int countMax = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i < k) {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                    count++;
                }
            } else {
                if (s[index1] == 'a' || s[index1] == 'e' || s[index1] == 'i' || s[index1] == 'o' || s[index1] == 'u') count--;
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') count++;
                index1++;
            }
            if (count > countMax) countMax = count;
        }
        return countMax;
    }
};
```











