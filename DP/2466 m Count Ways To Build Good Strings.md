Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.



example 1\

```
Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation: 
One possible valid good string is "011". 
It can be constructed as follows: "" -> "0" -> "01" -> "011". 
All binary strings from "000" to "111" are good strings in this example.
```

example 2\
```
Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".
```


constraints:
```
1 <= low <= high <= 10^5
1 <= zero, one <= low
```

Idea:\
```cpp
dp[i] means the number of good strings we can construct with length i.

Input: low = 2, high = 3, zero = 1, one = 2

dp[0] = 0, because we cannot construct a good string with length 0.
dp[1] = 1, because we can construct "0" for 1 time.
dp[2] = 2, because we can construct "00" for 1 time, and "11" for 1 time.
dp[3] = 3, because we can construct "00" and "11" with "0", and "0" with "11", which means dp[2]+dp[1], which also means dp[i] = dp[i-zeros] + dp[i-ones].
```


```cpp
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int result {0};
        vector<long long> dp(high+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= high; ++i) {
            if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % 1000000007;
            if (i >= one) dp[i] = (dp[i] + dp[i - one]) % 1000000007;
            if (i >= low) result = (result + dp[i]) % 1000000007;
        }
        return result;

    }
};
```











