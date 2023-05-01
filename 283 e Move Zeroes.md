# 283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

ex1
```cpp
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```

ex2
```cpp
Input: nums = [0]
Output: [0]
```

Constraints\
```cpp
1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1
```

idea:

go through from last one to first one. if find 0, move all following elemnets to previous position and set last element to 0.

method 2

Use two pointers i and j. i go through from first one to last one. if element is 0, skip. if not, set element[j++] = element[i]

...


```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = nums.size()-1; i >=0; i--) {
            if (nums[i] == 0) {
                // cout << nums[i] << endl;
                // cout << int(nums.size())-2 << endl;
                for (int j = i; j <=int(nums.size())-2; j++) {
                    // cout << "i" << i <<"j" << j << endl;
                    nums[j] = nums[j+1];
                }
                nums[nums.size()-1] = 0;
            }
        }
    }
};
```
OR 
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i <=nums.size()-1; i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        while (j < nums.size()) {
            nums[j++] = 0;
        }
    }
};
```









