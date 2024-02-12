# [169 Majority Element](https://leetcode.com/problems/majority-element/description/?envType=daily-question&envId=2024-02-12)

Given an array of size n, find the majority element. The majority element is the element that appears more than [n/2] times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
```
Input: [3,2,3]
Output: 3
```

Example 2:
```
Input: [2,2,1,1,1,2,2]
Output: 2
```

Constraints:

- `n == nums.length`
- `1 <= n <= 5 * 10^4`

Follow-up: Could you solve the problem in linear time and in O(1) space?

Idea:

use hash table to record the number of each element, and return the element with the largest number.

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
            if (umap[nums[i]] > nums.size()/2) return nums[i];
        }
        return 0;
    }
};
```

```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counts = Counter(nums)
        return max(counts.keys(), key=counts.get)
```

Other idea:

sort the array, and return the middle element.

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
```

Other idea:

Boyer-Moore Voting Algorithm

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
            }
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};
```
