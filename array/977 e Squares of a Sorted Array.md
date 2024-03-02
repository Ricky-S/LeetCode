Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.

example 1\
```
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
```

example 2\
```
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

Idea:\
1 calculate the square and then sort it. **O(n + nlogn), O(nlogn)**
```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end()); 
        return nums;        
    }
};
```

2 the array is sorted by non decreasing. the max number will be either first or last num.\
two pointers, compare the first and the last, if first's square is larger, then result[last] should be the first squared, else be the last squared. then move first or last pointer. **O($n$)**
```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int first = 0;
        int last = nums.size()-1;
        vector<int> result(nums.size(), 0);

        for (int i = nums.size() - 1; i >= 0; i--){
            if (nums[first] * nums[first] >= nums[last] * nums[last]) {
                result[i] = nums[first] * nums[first];
                first++;
            }
            else {
                result[i] = nums[last] * nums[last];
                last--;
            }
        }
        return result;
    }
};
```


```python
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0] * n 
        left, right = 0, n - 1 

        while left <= right:
            left_square = nums[left] ** 2
            right_square = nums[right] ** 2
            if left_square > right_square:
                result[n - 1] = left_square
                left += 1
            else:
                result[n - 1] = right_square
                right -= 1
            n -= 1  

        return result
```

```python
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        return sorted([i*i for i in nums])
```









