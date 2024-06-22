# [396. Rotate Function](https://leetcode.com/problems/rotate-function/)

You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].

Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.

ex1
```cpp
Input: nums = [4,3,2,6]
Output: 26
Explanation:
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
```

ex2
```cpp
Input: nums = [100]
Output: 0
```


Constraints\
```cpp
n == nums.length
1 <= n <= 10^5
-100 <= nums[i] <= 100
```

idea:\

f(0) = 0 * a + 1 * b + 2 * c + 3 * d

f(1) = 1 * a + 2 * b + 3 * c + 0 * d = f(0) + (a + b + c + d) - 4 * d; 

f(2) = 2 * a + 3 * b + 0 * c + 1 * d = f(1) + (a + b + c + d) - 4 * c; 

f(3) = 3 * a + 0 * b + 1 * c + 2 * d = f(2) + (a + b + c + d) - 4 * b; 


```cpp
// Runtime 165 ms
// Memory 95.8 MB
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // f(0) = 0 * a + 1 * b + 2 * c + 3 * d
        // f(1) = 1 * a + 2 * b + 3 * c + 0 * d = f(0) + (a + b + c + d) - 4 * d; 
        // f(2) = 2 * a + 3 * b + 0 * c + 1 * d = f(1) + (a + b + c + d) - 4 * c; 
        // f(3) = 3 * a + 0 * b + 1 * c + 2 * d = f(2) + (a + b + c + d) - 4 * b; 
        int result {0};
        int resultTmp { 0 };
        int resultTmpPre { 0 };
        int totalSum {0};
        const int numsSize = nums.size();
        for (int i = 0; i < numsSize; i++) {
            resultTmp += i * nums[i];
            totalSum += nums[i];
        }
        result = resultTmpPre = resultTmp;
        for (int i = 1; i < numsSize; i++) {
            resultTmp = resultTmpPre + totalSum - nums[numsSize-i] * numsSize;
            if (resultTmp > result) result = resultTmp;
            resultTmpPre = resultTmp;
        }
        // return *max_element(resultTmp.begin(), resultTmp.end());
        return result;
    }
};
```
OR
```cpp
// Runtime 187 ms
// Memory 100.4 MB
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // f(0) = 0 * a + 1 * b + 2 * c + 3 * d
        // f(1) = 1 * a + 2 * b + 3 * c + 0 * d = f(0) + (a + b + c + d) - 4 * d; 
        // f(2) = 2 * a + 3 * b + 0 * c + 1 * d = f(1) + (a + b + c + d) - 4 * c; 
        // f(3) = 3 * a + 0 * b + 1 * c + 2 * d = f(2) + (a + b + c + d) - 4 * b; 
        int result {0};
        vector<int> resultTmp(nums.size(), 0);
        int totalSum {0};
        for (int i = 0; i < nums.size(); i++) {
            resultTmp[0] += i * nums[i];
            totalSum += nums[i];
        }
        // cout << resultTmp[0] << endl;
        for (int i = 1; i < nums.size(); i++) {
            resultTmp[i] = resultTmp[i-1] + totalSum - nums[nums.size()-i] * nums.size();
            // cout << i << ": " << resultTmp[i] << endl;
        }
        return *max_element(resultTmp.begin(), resultTmp.end());
    }
};
```









