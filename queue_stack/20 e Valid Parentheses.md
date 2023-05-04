# 20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.

Open brackets must be closed in the correct order.

Every close bracket has a corresponding open bracket of the same type.

ex1
```cpp
Input: s = "()"
Output: true
```

ex2
```cpp
Input: s = "()[]{}"
Output: true
```
ex3
```cpp
Input: s = "(]"
Output: false
```


Constraints
```cpp
1 <= s.length <= 10^4
s consists of parentheses only '()[]{}'.
```

idea:

string must start with '([{', if next char is one of ')]}', it must be a pair with top of stack.


```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> parenthese;

        for (auto ch : s) {
            if (ch == '(') parenthese.push(')');
            else if (ch == '{') parenthese.push('}');
            else if (ch == '[') parenthese.push(']');
            else if (parenthese.empty()) return false; // to solve "]"
            else if (ch == parenthese.top()) parenthese.pop();
            else return false;   // to slove "(])"
        }
        return parenthese.empty();

    }
};
```
OR ([same method](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0020.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.md))
```cpp
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false; // odd length must be false.
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');

            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); 
        }
        return st.empty();
    }
};
```










