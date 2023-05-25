# 643. Maximum Average Subarray I

You are given an integer array `nums` consisting of `n` elements, and an integer `k`.

Find a contiguous subarray whose **length is equal to** `k` that has the maximum average value and return *this value*. Any answer with a calculation error less than `10^-5` will be accepted.


example 1
```
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
```

example 2
```
Input: nums = [5], k = 1
Output: 5.00000
```

Constraints
```
n == nums.length
1 <= k <= n <= 10^5
-10^4 <= nums[i] <= 10^4
```

idea:
1. sliding window
2. calculate the sum of the first k elements
3. move the window to the right by one step
4. calculate the sum of the new window
5. update maxSum
6. return maxSum / k

```cpp
// Runtime: 200 ms, faster than 98.78% of C++ online submissions for Maximum Average Subarray I.
// Memory Usage: 109.9 MB, less than 5.01% of C++ online submissions for Maximum Average Subarray I.
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int maxSum = sum;
        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        return (double) maxSum / k;
    }
};
```



