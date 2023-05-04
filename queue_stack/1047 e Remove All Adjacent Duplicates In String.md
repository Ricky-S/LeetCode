# 1047. Remove All Adjacent Duplicates In String

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

ex1
```cpp
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
```

ex2
```cpp
Input: s = "azxxzy"
Output: "ay"
```



Constraints
```cpp
1 <= s.length <= 10^5
s consists of lowercase English letters.
```

idea:

if stack is empty, push one char.

else check whether the new char is the same as top char.



```cpp
// TC: O(n)
// SC: O(n)
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for (auto ch : s) {
            if (!st.empty()) {
                if (ch == st.top()) st.pop();
                else st.push(ch);
            } else st.push(ch);
        }
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result; 
    }
};
```
OR [a simple method](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/1047.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89%E7%9B%B8%E9%82%BB%E9%87%8D%E5%A4%8D%E9%A1%B9.md)

```cpp
// TC: O(n)
// SC: O(1)
class Solution {
public:
    string removeDuplicates(string S) {
        string result;
        for(char s : S) {
            if(result.empty() || result.back() != s) {
                result.push_back(s);
            }
            else {
                result.pop_back();
            }
        }
        return result;
    }
};
```








