Given a binary array nums, return the maximum number of consecutive 1's in the array.

example 1\
```
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
```

example 2\
```
Input: nums = [1,0,1,1,0,1]
Output: 2
```

Idea:\
go through every int, if it is 1, count++, if count > result, update result to count.\
if it is 0, set count to 0.

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum1{0};
        int result{0};

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                sum1++;
                if (result < sum1) {
                    result = sum1;
                }
            } else {
                sum1 = 0;
            }
        }
        return result;
    }
};
```










