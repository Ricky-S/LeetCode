# [15. 3Sum](https://leetcode.com/problems/3sum/)

## Description:

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

**Example 1:**

```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: B
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
```


**Example 2:**

```
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
```

**Example 3:**

```
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
```

**Constraints:**

- `0 <= nums.length <= 3000`


- `-10^5 <= nums[i] <= 10^5`


## Idea:

1. Sort + Two Pointers

   Sort the array, and use two pointers to find the answer.

   - Time Complexity: O(n^2)
   - Space Complexity: O(1)


## Solution:

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int sum = -nums[i];
            int start = i+1;
            int end = nums.size()-1;
            while(start < end) {
                // cout << start << " " << end << endl;
                if(nums[start] + nums[end] > sum) {
                    end--;
                    while (start < end && nums[end] == nums[end+1]) end--;
                } else if (nums[start] + nums[end] < sum) {
                    start++;
                    while (start < end && nums[start] == nums[start-1]) start++;
                } else {
                    res.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    while (start < end && nums[end] == nums[end+1]) end--;
                    while (start < end && nums[start] == nums[start-1]) start++;
                }
                while (i < nums.size()-1 && nums[i] == nums[i+1]) i++;
            }
        }
        return res;
    }
};
```

