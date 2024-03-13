# [50. Pow(x, n)](https://leetcode.com/problems/powx-n/description/)

## Description

Implement [pow(*x*, *n*)](http://www.cplusplus.com/reference/valarray/pow/), which calculates *x* raised to the power *n* (x^n).

**Example 1:**

```

Input: 2.00000, 10
Output: 1024.00000

```

**Example 2:**

```

Input: 2.10000, 3
Output: 9.26100

```

**Example 3:**

```

Input: 2.00000, -2

Output: 0.25000

Explanation: 2-2 = 1/22 = 1/4 = 0.25

```

Constraints:

- -100.0 < *x* < 100.0


- *n* is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]


- Either x is not zero or n > 0.
- -10^4 <= xn <= 10^4

## Solution

```cpp
class Solution {
    public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1 / x;
        double half = myPow(x, n / 2);
        double rest = myPow(x, n % 2);
        return half * half * rest;
    }
};
```

My solution:
```cpp
class Solution {
public:
    double powXN(double x, int n) {
        double result {1};
        while (n > 0) {
            result = result*x;
            n--;
            if (result == 0) return 0;
            // if (x == 1) return 1;
        }
        return result;
    }
    double myPow(double x, int n) {
        
        if (n == 0) return 1;
        if (x == 1) return 1;
        if (x == -1) return (n%2 == 0) ? 1 : -1;
        if (n == INT_MIN) return powXN(1/x, INT_MAX)*1/x;
        if (n < 0) {
            n = -n;
            x = 1/x;
        }
        return powXN(x, n);
    }
};
```