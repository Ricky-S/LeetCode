Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".


Example 1:\
```
Input: strs = ["flower","flow","flight"]
Output: "fl"
```

Example 2:\
```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

Idea:\
1. get the min number of string.
2. from index 0 to index minNumber, check whether every index is the same.

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int size = 300;
        for (int i = 0; i < strs.size(); i++) {
            if (size > strs[i].size()) size = strs[i].size();
        }

        for (int j = 0; j < size; j++) {
            for (int i = 0; i < strs.size(); i++) {
                if (strs[i][j]-strs[0][j] != 0) {
                    return result;
                }
                else {
                    if (i == strs.size()-1) result.push_back(strs[0][j]);
                }
            }
        }    
        return result;    
    }
};
```








