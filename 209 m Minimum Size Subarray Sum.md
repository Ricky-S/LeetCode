Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


Example 1:
```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
```

Example 2:
```
Input: target = 4, nums = [1,4,4]
Output: 1
```

Example 3:
```
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
```

Idea:\
sliding window, pay attention to ```while```\
$O(2n), O(n)$
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int subLen = INT32_MAX;
        int subLenTemp = 0;
        int i = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            sum = sum + nums[j];
            
            while(sum >= target) {
                subLenTemp = j - i + 1;
                subLen = subLen < subLenTemp ? subLen:subLenTemp;
                sum = sum - nums[i];
                i++;
            }
        }
        return subLen != INT32_MAX ? subLen:0;
    }
};
```

























