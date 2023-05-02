# 1822. Sign of the Product of an Array

There is a function signFunc(x) that returns:

1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).

example 1\
```
Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1
```

example 2\
```
Input: nums = [1,5,0,2,-3]
Output: 0
Explanation: The product of all values in the array is 0, and signFunc(0) = 0
```

ex3
```cpp
Input: nums = [-1,1,-1,1,-1]
Output: -1
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1
```

Constraints:
```
1 <= nums.length <= 1000
-100 <= nums[i] <= 100
```

Idea:\
we don't need the actual number just the sign. So if the element is 0, just return 0;\
if it is greater than 0, product will be the same as previous one.\
if it is less than 0, product will be the negative of previous one.

```cpp
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) return 0;
            else if (nums[i] < 0) product = -product;
        }
        return product;
    }
};
```









