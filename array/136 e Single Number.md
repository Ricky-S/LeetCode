# 136. Single Number

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

ex1
```
Input: nums = [2,2,1]
Output: 1
```

ex2
```
Input: nums = [4,1,2,1,2]
Output: 4
```

ex3
```
Input: nums = [1]
Output: 1
```

Constraints:
```
1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
```

Idea:
```
use XOR to solve this problem
```

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};
```
OR
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (auto num : nums) {
            a ^= num;
        }
        return a;
        }    
};
```
OR
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       if (nums.size() == 1) return nums[0];
       else {
            sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size();i+=2)
            {
                if(nums[i]!=nums[i+1])
                    return nums[i];
            }
       }
       return 0;
    }    
};
```


