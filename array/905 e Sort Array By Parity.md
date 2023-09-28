# [905. Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity/)

## Description

Given an array nums of non-negative integers, return an array consisting of all the even elements of nums, followed by all the odd elements of nums.

You may return any answer array that satisfies this condition.

Example 1:

```
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
```

Constraints:

- 1 <= nums.length <= 5000


- 0 <= nums[i] <= 5000


## Solution

[explanation](https://leetcode.com/problems/sort-array-by-parity/solutions/170734/c-java-in-place-swap/?envType=daily-question&envId=2023-09-28)


```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int i = 0, j = 0; j < nums.size(); j++)
            if (nums[j] % 2 == 0) swap(nums[i++], nums[j]);
        return nums;
    }
};
```