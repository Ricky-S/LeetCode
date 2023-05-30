# [219. Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

example 1:

```
Input: nums = [1,2,3,1], k = 3
Output: true
```

example 2:

```

Input: nums = [1,0,1,1], k = 1
Output: true
```

example 3:

```
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
```

Constraints:

- 1 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9
- 0 <= k <= 10^5

idea:

use hash table to record the index of the number, and compare the distance between two same numbers.

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++) {
            if (record.find(nums[i]) != record.end() && i - record[nums[i]] <= k) {
                return true;
            } else {
                record[nums[i]] = i;
            }
        }
        return false;
    }
};
```

or 

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(nums[i]) == umap.end()) {
                umap[nums[i]] = i;
            } else {
                if (i - umap[nums[i]] <= k) {
                    return true;
                } else {
                    umap[nums[i]] = i;
                }
            }
            
        }
        return false;
    }
};
```

