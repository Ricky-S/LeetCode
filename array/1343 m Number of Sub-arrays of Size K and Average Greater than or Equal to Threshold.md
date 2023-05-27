# [1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/)

Given an array of integers arr and two integers k and threshold.

Return the number of sub-arrays of size k and average greater than or equal to threshold.

Example 1:
```
Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).
```

Example 2:
```
Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
Output: 6
Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.
```

Idea:
1. sliding window
2. calculate the sum of the first k elements
3. move the window to the right by one step
4. calculate the sum of the new window
5. update Sum

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        int res = 0;
        if (sum / k >= threshold) res++;
        for (int i = k; i < n; i++) {
            sum += arr[i] - arr[i - k];
            if (sum / k >= threshold) res++;
        }
        return res;
    }
};
```

