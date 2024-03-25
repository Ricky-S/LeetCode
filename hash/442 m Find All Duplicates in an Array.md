# [442. Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/)

## Description

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.



Example 1:

```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
```

Example 2:

```
Input: nums = [1,1,2]
Output: [1]
```

Example 3:

```
Input: nums = [1]
Output: []
```

Constraints:

- n == nums.length


- 1 <= n <= 10^5


- 1 <= nums[i] <= n


- Each element in nums appears once or twice.


## Solution

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) res.push_back(idx + 1);
            nums[idx] = -nums[idx];
        }
        return res;
    }
};
```

My Solution:

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> uset;
        for (int num : nums) {
            if (uset.find(num) != uset.end()) {
                res.push_back(num);
            } else uset.insert(num);
        }
        return res;
    }
};
```

```python
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        nums_dict = {}
        res = []
        for i in nums:
            if i in nums_dict:
                res.append(i)
            else:
                nums_dict[i] = 1
        return res
```