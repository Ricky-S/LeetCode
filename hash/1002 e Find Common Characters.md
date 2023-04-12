Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

example 1\
```
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
```

example 2\
```
Input: words = ["cool","lock","cook"]
Output: ["c","o"]
```


idea:\
an array contains 26 number.

```cpp
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int characters[26] = {0};
        int characters_tmp[26] = {0};
        int size = words.size();
        for  (int i = 0; i < words[0].size(); i++) {
            characters[words[0][i] - 'a']++;
        }
        for  (int i = 1; i < words.size(); i++) {
            for  (int j = 0; j < words[i].size(); j++) {
                characters_tmp[words[i][j] - 'a']++;
            }
            for  (int k = 0; k < 26; k++) {
                characters[k] = min(characters[k], characters_tmp[k]);
            }
            for  (int k = 0; k < 26; k++) {
                characters_tmp[k] = 0;
            }                     
        }       

        vector<string> output;
        for  (int k = 0; k < 26; k++) {
            while(characters[k]--) {
                string s(1, k + 'a');
                output.push_back(s);
                cout << s << endl;
            }
        }        
        return output;

    }
};
```






















