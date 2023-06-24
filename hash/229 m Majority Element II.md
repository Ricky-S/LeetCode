# [229. Majority Element II](https://leetcode.com/problems/majority-element-ii/)

Description:

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

Example 1:

```
Input: nums = [3,2,3]
Output: [3]
```


Example 2:

```
Input: nums = [1]
Output: [1]
```

Example 3:

```
Input: nums = [1,2]
Output: [1,2]
```

Constraints:

- 1 <= nums.length <= 5 * 10^4


- -10^9 <= nums[i] <= 10^9


Idea:

Use hash table to record the number of each element, and then check if the number of the element is greater than n/3.

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> record;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            record[nums[i]]++;
        }
        for (auto it = record.begin(); it != record.end(); it++) {
            if (it->second > nums.size() / 3) {
                res.push_back(it->first);
            }
        }
        return res;
    }
};
```

My solution:

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        vector<int> res;
        for (int num : nums) {
            umap[num]++;
            
        }
        for (auto&[k, v] : umap) {
            if ( v > nums.size()/3) res.push_back(k);
        }
        return res;
    }
};
```

O(1) space solution:

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1++;
            } else if (count2 == 0) {
                candidate2 = num;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            }
        }
        vector<int> res;
        if (count1 > n / 3) {
            res.push_back(candidate1);
        }
        if (count2 > n / 3) {
            res.push_back(candidate2);
        }
        return res;
    }
};
```