# [238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

## Description:

Given an integer array `nums`, return *an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`*.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.


**Example 1:**

```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```

**Example 2:**

```
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

**Constraints:**


- `2 <= nums.length <= 10^5`


- `-30 <= nums[i] <= 30`


- The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.


**Follow up:** Can you solve the problem in `O(1)` extra space complexity? (The output array **does not** count as extra space for space complexity analysis.)



## Idea:

1. Prefix and Suffix

   - Time Complexity: O(n)

   - Space Complexity: O(n)

2. Prefix and Suffix (Optimized)


    - Time Complexity: O(n)
    
    - Space Complexity: O(1)



## Solution:

### basic solution

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int times0 = -1;
        int temp = 1;
        for (int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                if (times0 == -1){
                    times0 = i;
                } else return res; // more than two 0's, return all 0;
            } else {
                temp *= nums[i];
            }
        }
        if(times0 != -1) {
            res[times0] = temp;
            return res; //one 0's, return all 0 except index of 0;
        }
        // no 0 in array
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            res[0] *= nums[i];        
        }
        for (int i = 1; i < n; i++) {
            res[i] = res[0]/nums[i]*nums[0];    
        }        
        return res;
    }
};
```

[idea](https://leetcode.com/problems/product-of-array-except-self/solutions/1342916/3-minute-read-mimicking-an-interview/)


Prefix and Suffix

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1]*nums[i];
        }
        suffix[n-1] = nums[n-1];
        for (int i = n-2; i > 0; i--) {
            suffix[i] = suffix[i+1]*nums[i];
        }
        res[0] = suffix[1];
        res[n-1] = prefix[n-2];
        for (int i = 1; i < n-1; i++) {
            res[i] = prefix[i-1]*suffix[i+1];
        }      
        return res;
    }
};
```