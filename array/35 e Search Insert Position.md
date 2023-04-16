Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.



Example 1:
```
Input: nums = [1,3,5,6], target = 5
Output: 2
```

Example 2:
```
Input: nums = [1,3,5,6], target = 2
Output: 1
```
Example 3:
```
Input: nums = [1,3,5,6], target = 7
Output: 4
```

idea:
assume correct was between leftIndex and rightIndex, narrower the gap between index to 1.

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int centerIndex = nums.size()/2;
        int leftIndex = 0, rightIndex = nums.size();
        if (centerIndex == 0) {
            if (nums[centerIndex] < target) return 1;
            else return 0; //if (nums[centerIndex] > target) return 0; or == target return 0;
        }
        cout << "L" << leftIndex << "R" << rightIndex << "C" << centerIndex << " " <<  nums[centerIndex] <<  " " <<target << endl;
        while(centerIndex != 0 && centerIndex != nums.size() && (rightIndex-leftIndex) != 1 ) {
            
            if (target > nums[centerIndex]) {
                leftIndex = centerIndex;
            } else if (target < nums[centerIndex]) {
                rightIndex = centerIndex;
                // if (target > nums[centerIndex-1]) return centerIndex-1;
                // centerIndex = ( centerIndex ) / 2;
            } else {
                return centerIndex;
            }
            centerIndex = (leftIndex+rightIndex) / 2;
            cout << "L" << leftIndex << "R" << rightIndex << "C" << centerIndex << " " <<  nums[centerIndex] <<  " " <<target << endl;
            
        }
        if (centerIndex == 0) {
            if (nums[centerIndex] < target) return 1;
            else return 0; //if (nums[centerIndex] > target) return 0; or == target return 0;
        } else if(centerIndex == nums.size()-1) {
            if (nums[centerIndex] < target) return nums.size();
            else return nums.size()-1;          
        } else return centerIndex+1;

    }
};
```
