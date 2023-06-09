# [2148. Count Elements With Strictly Smaller and Greater Elements](https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/)


## Problem:

Given an integer array nums, return the number of elements that have both a strictly smaller and a strictly greater element appear in nums.

Example 1:

```
Input: nums = [11,7,2,15]
Output: 2
Explanation: The element 7 has the element 2 strictly smaller than it and the element 11 strictly greater than it.
Element 11 has element 7 strictly smaller than it and element 15 strictly greater than it.
In total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.
```

Example 2:

```
Input: nums = [-3,3,3,90]
Output: 2
Explanation: The element 3 has the element -3 strictly smaller than it and the element 90 strictly greater than it.
Since there are two elements with the value 3, in total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.
```

Constraints:

- 1 <= nums.length <= 100
- -100000 <= nums[i] <= 100000

Ideas:

1. Sort: O(nlogn)
2. find max and min: O(n)

Solutions:

### Sort: O(nlogn)

```cpp
class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] > nums[0] && nums[i] < nums[n - 1]) ++count;
        }
        return count;
    }
};
```

### find max and min: O(n)

```cpp
class Solution {
public:
    int countElements(vector<int>& nums) {
        int max = INT_MIN;
        int min = INT_MAX;
        for (int num : nums) {
            if (num < min) min = num;
            if (num > max) max = num;
        }
        int count = 0;
        for (int num : nums) {
            if ((num > min) && (num <max)) count++;
        }
        return count;
    }
};
```



