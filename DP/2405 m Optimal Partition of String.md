# [2405. Optimal Partition of String](https://www.lintcode.com/problem/optimal-partition-of-string/description)

## Description

Given a string s, partition the string into one or more substrings such that the characters in each substring are **unique**. That is, no letter in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

Example 1:

```
Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
```

Example 2:

```
Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").
```

Constraints:

- 1 <= s.length <= 10^5
- s contains only lowercase English letters.


Ideas:

use unordered set to check whether a character is unique or not.

```cpp
class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> uset;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (uset.find(s[i]) != uset.end()) {
                res++;
                uset.clear();
            }
            uset.insert(s[i]);
        }
        return res+1;
    }
};
```