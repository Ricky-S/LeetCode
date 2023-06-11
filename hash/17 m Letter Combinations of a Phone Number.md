# [17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

## description

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![phone](https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

```text

2: abc
3: def
4: ghi
5: jkl
6: mno
7: pqrs
8: tuv
9: wxyz

```

Example1:

```text

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

```

example2:

```text

Input: ""

Output: []

```

Example3:

```text

Input: "2"

Output: ["a", "b", "c"]

```

Constraints:

```text

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

```

Idea:


## solution

```cpp

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        vector<string> dict = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        res.push_back("");
        for(int i=0;i<digits.size();i++){
            vector<string> tmp;
            string chars = dict[digits[i]-'2'];
            for(int j=0;j<chars.size();j++){
                for(int k=0;k<res.size();k++){
                    tmp.push_back(res[k]+chars[j]);
                }
            }
            res = tmp;
        }
        return res;
    }
};

```

OR 

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
        };
        if (digits.size() == 0) return {};
        vector<string> res;
        res.push_back("");
        for (char digit :digits) {
            vector<string> temp;
            for (auto ch : pad[digit-'0']) {
                
                for (string s : res) {
                    temp.push_back(s+ch);
                }
            }
            res.swap(temp);
        }
        
        return res;
    }
};
```