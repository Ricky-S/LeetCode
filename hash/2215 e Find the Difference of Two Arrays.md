# 2215. Find the Difference of Two Arrays


Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.

answer[1] is a list of all distinct integers in nums2 which are not present in nums1.

Note that the integers in the lists may be returned in any order.

example 1\
```cpp
Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
```

example 2\
```cpp
Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
```

Constraints:
```cpp
1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000
```
idea:\

use unordered_set.

```cpp
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set1;
        unordered_set<int> result_set2;
        unordered_set<int> nums1Set(nums1.begin(), nums1.end());
        unordered_set<int> nums2Set(nums2.begin(), nums2.end());
        for (auto num : nums1) {
            if (nums2Set.find(num) == nums2Set.end()) {
                result_set1.insert(num);
                // cout << num<< endl;
            }
        }
        for (auto num : nums2) {
            if (nums1Set.find(num) == nums1Set.end()) {
                result_set2.insert(num);
            }
        }

        vector<vector<int>> result{};
        result.push_back (vector<int>(result_set1.begin(), result_set1.end()));
        result.push_back (vector<int>(result_set2.begin(), result_set2.end()));

        return result;
};
```
OR
```cpp
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result_set1;
        vector<int> result_set2;
        unordered_set<int> nums1Set(nums1.begin(), nums1.end());
        unordered_set<int> nums2Set(nums2.begin(), nums2.end());
        for (auto num : nums1Set) {
            if (nums2Set.find(num) == nums2Set.end()) {
                result_set1.push_back(num);
            }
        }
        for (auto num : nums2Set) {
            if (nums1Set.find(num) == nums1Set.end()) {
                result_set2.push_back(num);
            }
        }

        return {result_set1, result_set2};        
    }
};
```





















