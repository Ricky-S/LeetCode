# [1493. Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/)

## Description:

Given a binary array `nums`, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array.

Return 0 if there is no such subarray.

**Example 1:**

```
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
```

**Example 2:**

```
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
```

**Example 3:**

```
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
```

Constraints:


- `1 <= nums.length <= 10^5`


- `nums[i]` is either `0` or `1`.


## Idea:

1. Sliding Window


## Solution:

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int res = 0;
        int cnt = 0;
        while (r < n) {
            if (nums[r] == 0) cnt++;
            while (cnt > 1) {
                if (nums[l] == 0) cnt--;
                l++;
            }
            res = max(res, r - l);
            r++;
        }
        return res;
    }
};
```

My solution:

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> index0;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) index0.push_back(i);
        }
        int n = index0.size();   
        int maxrange = 0;
        int i = 0;
        int sub = 0;
        if (n == 0 || n == 1) return nums.size()-1;
        else {
            while (i < n) {
                if (i == 0)             sub = index0[i+1]-1;
                else if (i < n - 1 )    sub = index0[i+1]-1-index0[i-1]-1;
                else                    sub = nums.size()-1-index0[i-1]-1;
                maxrange = max(maxrange, sub);
                i++;
            }
            return maxrange;
        } 
    }
};
```

