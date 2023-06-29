# [189. Rotate Array](https://leetcode.com/problems/rotate-array/)

## 1. Problem:

Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:
```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

Example 2:
```
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

Constraints:

- `1 <= nums.length <= 10^5`


- `-2^31 <= nums[i] <= 2^31 - 1`


- `0 <= k <= 10^5`


Follow up:

- Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.


- Could you do it in-place with O(1) extra space?


Idea:

- use a new array to store the rotated array.


```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            res[(i+k)%nums.size()] = nums[i];
        }
        nums = res;
    }
};
```

My solution:

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % nums.size();
        vector<int> after;
        for (int i = n-k; i < n; i++) {
            after.push_back(nums[i]);
        }
        // for (int num : after) cout << num << endl;

        for (int i = n-1; i >= k; i--) {
            nums[i] = nums[i-k];
            // cout << i << " " << nums[i] << endl;
        }

        for (int i = 0; i < after.size(); i++) {
            nums[i] = after[i];
            // cout << i << " " << nums[i] << endl;
        }       
    }
};
```

[Summary of C++ solutions](https://leetcode.com/problems/rotate-array/solutions/54277/summary-of-c-solutions/)

```cpp
    class Solution 
    {
    public:
        void rotate(int nums[], int n, int k) 
        {
            k = k%n;
    
            // Reverse the first n - k numbers.
            // Index i (0 <= i < n - k) becomes n - k - i.
            reverse(nums, nums + n - k);
            
            // Reverse tha last k numbers.
            // Index n - k + i (0 <= i < k) becomes n - i.
            reverse(nums + n - k, nums + n);
            
            // Reverse all the numbers.
            // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
            // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
            reverse(nums, nums + n);
        }
    };
```




