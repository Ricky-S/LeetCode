# [1913. Maximum Product Difference Between Two Pairs](https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/?envType=daily-question&envId=2023-12-18)

## Description

The **product difference** between two pairs `(a, b)` and `(c, d)` is defined as `(a * b) - (c * d)`.

- For example, the product difference between `(5, 6)` and `(2, 7)` is `(5 * 6) - (2 * 7) = 16`.

Given an integer array `nums`, choose four **distinct** indices `w`, `x`, `y`, and `z` such that the **product difference** between pairs `(nums[w], nums[x])` and `(nums[y], nums[z])` is **maximized**.

Return *the **maximum** such product difference*.

### Example 1:

```
Input: nums = [5,6,2,7,4]
Output: 34
Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).

The product difference is (6 * 7) - (2 * 4) = 34.
```

### Example 2:

```
Input: nums = [4,2,5,9,7,4,8]
Output: 64
Explanation: We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the second pair (2, 4).

The product difference is (9 * 8) - (2 * 4) = 64.
```

### Constraints:

- `4 <= nums.length <= 10^4`
- `1 <= nums[i] <= 10^4`

## Solution:

```cpp
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-1]*nums[n-2] - nums[0]*nums[1];
    }
};
```

```python
class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        max1, max2 = -1, -1
        min1, min2 = 100000, 100000
        for i in range(len(nums)):
            if max1 <= nums[i]:
                max1 = nums[i]
                indexmax1 = i
            if min1 >= nums[i]:
                min1 = nums[i]
                indexmin1 = i
        for i in range(len(nums)):   
            if max2 <= nums[i] and i != indexmax1:
                max2 = nums[i]
            if min2 >= nums[i] and i != indexmin1:
                min2 = nums[i]

        return max1*max2-min1*min2 

```
