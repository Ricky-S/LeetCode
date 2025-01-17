# [137. Single Number II](https://leetcode.com/problems/single-number-ii/description/) (Medium)

## Description


Given an integer array `nums` where every element appears **three times** except for one, which appears **exactly once**. *Find the single element and return it*.

You must implement a solution with a linear runtime complexity and use only constant extra space.

**Example 1:**

```
Input: nums = [2,2,3,2]
Output: 3
```

**Example 2:**

```
Input: nums = [0,1,0,1,0,1,99]
Output: 99
```

**Constraints:**

- `1 <= nums.length <= 3 * 10^4`


- `-2^31 <= nums[i] <= 2^31 - 1`


- Each element in `nums` appears exactly **three times** except for one element which appears **once**.


## Idea:

1. Bit Manipulation

## Solution:

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; ++i) {
            int sum = 0;
            for(int num : nums) {
                sum += (num >> i) & 1;
            }
            res |= (sum % 3) << i;
        }
        return res;
    }
};
```

another solution:

[Detailed explanation and generalization of the bitwise operation method for single numbers](https://leetcode.com/problems/single-number-ii/solutions/43295/detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers/)

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0, mask = 0;
        for(int num : nums) {
            x2 = x2 ^ (x1 & num);
            x1 = x1 ^ num;
            mask = ~(x2 & x1);  // k=3, '11'
            x2 = x2 & mask;
            x1 = x1 & mask;
        }
        return x1;
    }
};
```