Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.



```
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```

example 1\
```
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
```

example 2\
```
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
```

Idea:\
size = 4;
|  | size-4=0    | size-3=1    | size-2=2    | size-1=3  |
| :--------: | :--------: | :-------: | :-------: | :-------: |
|  | c         | b         | b         | d       |
| size-4=0, c  | 1         | dp[0][1]          | dp[0][2]         | dp[0][3]       |
| size-3=1, b  | 0         | 1         | dp[1][2]          | dp[1][3]       |
| size-2=2, b  | 0         | 0         | 1         | dp[size-2][size-1]=dp[2][3]       |
| size-1=3, d  | 0         | 0         | dp[3][2]=0         | 1       |

if(s[1] == s[2] ) dp[1][2] = dp[2][1]+2 = 2
if(s[1] != s[2] ) dp[1][2] = max(dp[1][1], dp[2][2])



```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }

        for (int i = s.size()-2; i >= 0; i--) {
            for (int j = i+1; j <=s.size()-1; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
                // cout <<"(i,j)" << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        return dp[0][s.size()-1];
    }
};
```











