# [8. String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)

Description:

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.

Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.


Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.

Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).

If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.

Return the integer as the final result.

Note:

Only the space character ' ' is considered a whitespace character.

Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.


Example 1:

```cpp
Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.

Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')

Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.

Since 42 is in the range [-2^31, 2^31 - 1], the final result is 42.
```

Example 2:

```cpp
Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.

Since -42 is in the range [-2^31, 2^31 - 1], the final result is -42.
```

Example 3:

```cpp
Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')

Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.

Since 4193 is in the range [-2^31, 2^31 - 1], the final result is 4193.
```

Constraints:

0 <= s.length <= 200

s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

## Idea

process the string from left to right, and use a variable to store the result.

## Solution

```cpp
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        int res = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '+') ? 1 : -1;
        }
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            res = res * 10 + (s[i++] - '0');
        }
        return res * sign;
    }
};
```

My solution:

```cpp
class Solution {
public:
    int myAtoi(string s) {

        bool spaceFlag = true;
        bool negRes = false;
        bool numFinish = false;
        bool firstTime = true;
        char firstChar = s[0];
        long long res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' && spaceFlag) {
                firstChar = s[i+1];
            }
            else if ( !numFinish ) {
                // cout << firstChar << ", " << negRes << ", " << s[i] << endl;
                if (firstChar != '-' && firstChar != '+'  && (firstChar -'0' < 0 || firstChar -'9' > 0 )) return 0;
                spaceFlag = false;
                if (firstChar == '-' && firstTime) {
                    firstTime = false;
                    negRes = true;
                    i++;
                }
                else if (firstChar == '+' && firstTime) {
                    i++;
                    firstTime = false;
                    negRes = false;
                }
                // cout << firstChar << ", " << negRes << ", " << s[i] << endl;
                if (s[i]-'0' >= 0 && s[i]-'0' <= 9) {
                    res = res*10 + s[i]-'0';
                    if (negRes) {
                        if(-res < -pow(2, 31)) return -pow(2, 31);
                    } else {
                        if (res > pow(2, 31)-1) return pow(2, 31)-1;
                    }
                    
                } else {
                    numFinish = true;
                }               
            } 
        }
        if (negRes) return -res;
        else return res;        
        // cout << pow(2, 8) << endl;
        // cout << negRes << res << -res;
        // if (negRes) {
        //     if (res > pow(2, 31)) return -pow(2, 31);
        //     else return -res;
        // }
        // if (negRes) return -res > -pow(2, 31) ? -res : -pow(2, 31);
        // else return res < pow(2, 31)-1 ? res :  pow(2, 31)-1;
    }
};
```

My updated solution:

```cpp
class Solution {
public:
    int myAtoi(string s) {

        // bool spaceFlag = true;
        // bool negRes = false;
        // bool numFinish = false;
        // bool firstTime = true;
        // char firstChar = s[0];
        // long long res = 0;
        int result = 0;
        int index = 0;
        while (s[index] == ' ') index++;

        if (s[index] != '-' && s[index] != '+'  && (s[index] -'0' < 0 || s[index] -'9' > 0 )) return 0;

        if (s[index] == '-') {
            index++;
            while(s[index]-'0' >= 0 && s[index]-'0' <= 9) {
                // cout << result << ", " << s[index] << ", " << s[index] - '0' << endl;
                if (result < INT_MIN/10 || ((result == INT_MIN / 10 && s[index] - '0' > 8))) return INT_MIN;
                else result = result*10 - (s[index] -'0');
                index++;
            }
            return result;
        } else  {
            if (s[index] == '+') index++;
            while(s[index]-'0' >= 0 && s[index]-'0' <= 9) {
                if (result > INT_MAX/10 || ((result == INT_MAX / 10 && s[index] - '0' > 7))) return INT_MAX;
                else result = result*10 -'0' + s[index];
                index++;
            }
            return result;        
        }
        return 0;
    }
};
```