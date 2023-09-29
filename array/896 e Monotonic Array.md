# [896. Monotonic Array](https://leetcode.com/problems/monotonic-array/)

## Description

An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j].  An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Return true if and only if the given array nums is monotonic.

Example 1:

```
Input: nums = [1,2,2,3]
Output: true
```

Example 2:

```
Input: nums = [6,5,4,4]
Output: true
```

Example 3:

```
Input: nums = [1,3,2]
Output: false
```

## Constraints

- 1 <= nums.length <= 50000

- -100000 <= nums[i] <= 100000

## Solution

```cpp
class Solution {
    public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true, dec = true;
        for (int i = 1; i < nums.size(); i++) {
            inc &= nums[i - 1] <= nums[i];
            dec &= nums[i - 1] >= nums[i];
        }
        return inc || dec;
    }
};
```

OR

```cpp
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc = 0, dec = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            if (nums[i] <= nums[i+1]) inc++;
            if (nums[i] >= nums[i+1]) dec++;
        }
        if (inc == nums.size()-1) return true;
        else if (dec == nums.size()-1) return true;
        else return false;
        
    }
};
```
