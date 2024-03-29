# [12. Integer to Roman](https://leetcode.com/problems/integer-to-roman/)

## description

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

```text
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

```

For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX.There are six instances where subtraction is used:

- I can be placed before V (5) and X (10) to make 4 and 9.
- X can be placed before L (50) and C (100) to make 40 and 90.
- C can be placed before D (500) and M (1000) to make 400 and 900.
- Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

```text
Input: 3
Output: "III"

```

Example 2:

```text
Input: 4
Output: "IV"

```

Example 3:

```text
Input: 9
Output: "IX"

```

Constraints:

```text
1 <= num <= 3999

```

## solution

```c++
class Solution {
public:
    string intToRoman(int num) {
        string res;
        vector<int> nums = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> romans = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i=0;i<nums.size();i++){
            while(num>=nums[i]){
                num-=nums[i];
                res+=romans[i];
            }
        }
        return res;
    }
};
```

OR

```c++
class Solution {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];        
    }
};
```