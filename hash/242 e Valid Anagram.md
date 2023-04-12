Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

example 1\
```
Input: s = "anagram", t = "nagaram"
Output: true
```

example 2\
```
Input: s = "rat", t = "car"
Output: false
```

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

idea:\
count every character's amount, and compare two strings.

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};

        for (int i = 0; i < s.size(); i++){
            record[s[i] - 'a']++;
        }
        for(int j = 0; j < t.size(); j++) {
            record[t[j] - 'a']--;
        }
        for (int k = 0; k < 26; k++) {
            if (record[k] != 0) return false;
        }
        return true;
    //     string newt = t;
    //     string tempt;
    //     int flag = 1;
    //     int count = t.size() == s.size() ? t.size(): -1;
    //     for (int i = 0; i < s.size(); i++) {
    //         for (int j = 0; j < newt.size(); j++) {
    //             tempt += newt[j];
    //             if (newt[j] == s[i] && flag == 1) {
    //                 count--;
    //                 tempt.pop_back();
    //                 flag = 0;
    //             }
    //         }
    //         newt = tempt;
    //         tempt = "";
    //         flag = 1;
    //         // cout << newt << endl;
    //     }

    //     return count == 0 ? true : false;

    }
};
```






















