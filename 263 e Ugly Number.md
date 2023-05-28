# 263. Ugly Number

## 1. Description

Write a program to check whether a given number is an ugly number.

Ugly numbers are **positive numbers** whose prime factors only include `2, 3, 5`.

**Example 1:**

```
Input: 6
Output: true
Explanation: 6 = 2 × 3
```

**Example 2:**

```
Input: 8
Output: true
Explanation: 8 = 2 × 2 × 2
```

**Example 3:**

```
Input: 14
Output: false
Explanation: 14 is not ugly since it includes another prime factor 7.
```

**Note:**

- 1 is typically treated as an ugly number.
- Input is within the 32-bit signed integer range: [−2^31,  2^31 − 1].
- 2, 3, 5 are the only prime factors of an ugly number.
- 0 is not an ugly number.
- negative number is not an ugly number.

## 2. Solution

```cpp
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        for (int i = 2; i <= 5; i++) {
            while(n % i == 0) n /= i;
        }
        return n == 1;
    }
};
```


