# [80. Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)

## Description

Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the **first part** of the array `nums`. More formally, if there are `k` elements after removing the duplicates, then the first `k` elements of `nums` should hold the final result. It does not matter what you leave beyond the first `k` elements.

Return `k` *after placing the final result in the first* `k` *slots of* `nums`.

Do **not** allocate extra space for another array. You must do this by **modifying the input array** in-place with O(1) extra memory.

**Custom Judge:**

The judge will test your solution with the following code:

```
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

If all assertions pass, then your solution will be **accepted**.

**Example 1:**

```
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Example 2:**

```
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It does not matter what values are set beyond the returned k (hence they are underscores).
```

**Constraints:**

- `1 <= nums.length <= 3 * 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted in **non-decreasing** order.


## Idea

### Solution 1: Two Pointers

use slow and fast pointers to traverse the array, and use a counter to count the number of duplicates. 

```cpp
// twoPointers\80 m Remove Duplicates from Sorted Array II.cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        return slow;
    }
};
```

My solution:

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fast = 1, slow = 0, dupCount = 0;
        int n = nums.size();
        if (n <= 2) return n;
        else {
            while (fast < n) {
                if(nums[slow] != nums[fast]) {
                    slow=fast;
                    fast++; 
                    dupCount = 0;
                } else {
                    dupCount++;
                    if (dupCount >= 2) {
                        for (int ii = fast; ii < n-1; ii++) {
                            nums[ii] = nums[ii+1];
                        }
                        n--;
                    } else {
                        fast++;
                    }
                }
                // cout << slow << " " << fast << " " << dupCount << " " << n << endl;
            }
        }
        return n;
    }
};
```

```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slow = 0
        d = {}
        ans = 0
        for i in range(len(nums)):
            if nums[i] not in d:
                nums[slow] = nums[i]
                d[nums[i]] = 1
                slow += 1
                ans += 1
            elif nums[i] in d and d[nums[i]] == 1:
                nums[slow] = nums[i]
                d[nums[i]] = 2
                slow += 1
                ans += 1
        return ans
```





