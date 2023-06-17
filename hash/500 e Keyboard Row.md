# [500. Keyboard Row](https://leetcode.com/problems/keyboard-row/)

Description:

Given an array of strings `words`, return *the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below*.

In the **American keyboard**:

- the first row consists of the characters `"qwertyuiop"`,

- the second row consists of the characters `"asdfghjkl"`, and


- the third row consists of the characters `"zxcvbnm"`.


**Example 1:**

```text
Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
```

**Example 2:**

```text
Input: words = ["omk"]
Output: []
```

**Example 3:**

```text

Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]
```

**Constraints:**

- `1 <= words.length <= 20`
- `1 <= words[i].length <= 100`
- `words[i] consists of English letters (both lowercase and uppercase). `

Idea:

1. hash

Solution:

```cpp
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for (auto& word : words) {
            if (isOneRow(word)) res.push_back(word);
        }
        return res;
    }
private:
    bool isOneRow(string& word) {
        unordered_set<char> row1{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> row2{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> row3{'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        int row = 0;
        for (auto& c : word) {
            if (row1.count(tolower(c))) row |= 1;
            if (row2.count(tolower(c))) row |= 2;
            if (row3.count(tolower(c))) row |= 4;
            if (row > 1) return false;
        }
        return true;
    }
};
```

My solution:

```cpp
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_map<char, int> umap;
        for (char ch : "qwertyuiopQWERTYUIOP") {
            umap[ch] = 1;
        }
        for (char ch : "asdfghjklASDFGHJKL") {
            umap[ch] = 2;
        }
        for (char ch : "zxcvbnmZXCVBNM") {
            umap[ch] = 3;
        }
        for(string st : words) {
            if (st.size() == 1) res.push_back(st);
            int ans = umap[st[0]];
            // cout << ans << endl;
            for (int i = 1; i < st.size(); i++) {
                if (umap[st[i]] != ans) break;
                else {
                    // cout << st<< endl;
                    if(i == st.size()-1) res.push_back(st);
                }

            }
            
        }
        return res;
    }
};