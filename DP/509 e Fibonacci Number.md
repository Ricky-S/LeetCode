The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

```
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```

example 1\
```
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
```

example 2\
```
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```

Idea:\
**f(n) = f(n-1) + f(n-2)**
```cpp
// time O(n^2), space (n)
class Solution {
public:
    int fib(int n) {
        int result = 0;
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            result = fib(n-2) + fib(n-1); 
        }
        return result;
    }
};
```
OR
```cpp
class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            vector<int> dp(n + 1);
            dp[0] = 0;
            dp[1] = 1;
            for (int i = 2; i < n+1; i++) {
                dp[i] = dp[i-2] + dp[i-1];
            }
            return dp[n];       
        }
    }        
};
```











