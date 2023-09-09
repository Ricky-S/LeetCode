# [258. Add Digits](https://leetcode.com/problems/add-digits/)

## Description

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

ex1
```cpp
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
```

ex2
```cpp
Input: num = 0
Output: 0
```

Constraints\
```cpp
0 <= num <= 2^31 - 1
```


## Solution


idea:\
if it is less than 10, return itself.\
otherwise add every last digit to sum.

Another solution:

if num = ABCD = 1000A + 100B + 10C + D = A+B+C+D+9*(111A + 11B + C)

which means num%9 = A+B+C+D;
```cpp
class Solution {
public:
    int addDigits(int num) {
        if (num < 10) return num;
        else {
            int sum {num};
            while (sum >= 10) {
                num = sum;
                sum = 0;
                while (num > 0) {
                    sum = sum + num%10;
                    num = num / 10;
                }
            }                       
            return sum;
        }
    }
};
```
Second solution:
```cpp
class Solution {
public:
    int addDigits(int num) {
        return num < 10 ? num: (num % 9 == 0 ? 9: num % 9);
    //     if (num < 10) return num;
    //     else {
    //         int sum {num};
    //         while (sum >= 10) {
    //             num = sum;
    //             sum = 0;
    //             while (num > 0) {
    //                 sum = sum + num%10;
    //                 num = num / 10;
    //             }
    //         }                       
    //         return sum;
    //     }
    // }
};
```












