You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.


Example 1:\
```
Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
```

Example 2:\
```
Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
```

Idea:\
set a new empty string. go through s, if not *, push_back this char, else pop_back last char.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int count = 0;
        string result = "";
        vector<int> index(s.size(), -1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                count++;
                index[i] = i;
            } else {
                // result.push_back(s[i]);
            }
        }
        int i = 0, jStar = 0, sIndex = 0;
        for (sIndex = 0; sIndex < s.size(); sIndex++) {
            if (s[sIndex] == '*') {
                // jStar++;
                result.pop_back();
            } else {
                result.push_back(s[sIndex]);
            }
        }
        for (int i = 0, j = 0; i < s.size(); i++) 
            cout << "indexi" << index[i] << endl;
        cout << count << endl;
        cout << result << endl;

        return s;
    }
};

int main() {
    string s1 = "leet**cod*e";
    string s2 = "erase*****";
    string s3 = "abcdefghijklmnopqrstuvwxabcdefghijklmnopqrstuvwxabcdefghijklmnopqrstuvwxabcdefghijklmnopqrstuvwxabcdefghijklmnopqrstuvwxabcdefghijklmnopqrstuvwxz*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*z*";
    Solution solution;
    solution.removeStars(s3);
}
```








