# 290. Word Pattern

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

**Example 1:**

```
Input: pattern = "abba", str = "dog cat cat dog"
Output: true
```

**Example 2:**

```
Input:pattern = "abba", str = "dog cat cat fish"
Output: false
```

**Example 3:**

```

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
```


Constraints:

- `1 <= pattern.length <= 300`

- `pattern` contains only lower-case English letters.

- `1 <= str.length <= 3000`

- `str` contains only lower-case English letters and spaces `' '`.

- `str` does not contain any leading or trailing spaces.

- All the words in `str` are separated by a single space.


Idea:

unordered map to check the mapping.

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> umap1;
        unordered_map<string, char> umap2;
        stringstream ss(str);
        string word;
        int i = 0;
        while (ss >> word) {
            if (i >= pattern.size()) return false;
            if (umap1[pattern[i]]) {
                if (umap1[pattern[i]] != word) return false;
            } else {
                if (umap2[word] == 'T') return false;
                umap1[pattern[i]] = word;
                umap2[word] = 'T';
            }
            i++;
        }
        if (i != pattern.size()) return false;
        return true;
    }
};
```

OR 

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> umap1;
        unordered_map<string, int> umap2;
        stringstream ss(str);
        string word;
        int i = 0;
        while (ss >> word) {
            if (i >= pattern.size()) return false;
            if (umap1[pattern[i]] != umap2[word]) return false;
            umap1[pattern[i]] = i + 1;
            umap2[word] = i + 1;
            i++;
        }
        if (i != pattern.size()) return false;
        return true;
    }
};
```

Mine:

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> umap;
        vector<string> v;
        stringstream ss(s);
        string word;
        while(ss >> word) v.push_back(word);
        
        if (pattern.size() != v.size()) return false;

        set<string> S;
        for (int i = 0; i < pattern.size(); i++) {
            if (umap.find(pattern[i]) == umap.end()) {
                if (S.count(v[i]) != 0) return false;
                umap[pattern[i]] = v[i];
                S.insert(v[i]);
            }
            else {
                if(umap[pattern[i]] != v[i]) return false;
            }
        }
        return true;
    }
};
```