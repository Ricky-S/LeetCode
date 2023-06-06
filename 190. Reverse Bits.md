# 190. Reverse Bits

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

ex1
```cpp
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

ex2
```cpp
Input: nums = [2,0,1]
Output: [0,1,2]
```

Constraints\
```
n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
```

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

idea:\
2 0 2 1 1 0

0 1 2 3 4 5 Index

startIndex=0, endIndex = 5, midIndex = 0;



```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        /* 
        only three colors means only 0, 1, 2, in this array.
        if we find 0, it must in first part, 2 must in last (third) part.
        */
        int startIndex{0}, endIndex = nums.size()-1, midIndex{0};
        while (midIndex <= endIndex) {
            if (nums[midIndex] == 1) midIndex++;
            else if (nums[midIndex] == 0) {
                swap(nums[midIndex++], nums[startIndex++]);
            }else{
                swap(nums[midIndex], nums[endIndex--]);
            }
        }
        
    }
};
```










