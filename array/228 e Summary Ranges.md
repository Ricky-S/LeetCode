# [228. Summary Ranges](https://leetcode.com/problems/summary-ranges/description/)

## description

You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

- "a->b" if a != b
- "a" if a == b

Example 1:

```text

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

```

Example 2:

```text

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

```

Example 3:

```text

Input: nums = []
Output: []

```

Constraints:

```text
0 <= nums.length <= 20
-2^31 <= nums[i] <= 2^31 - 1
All the values of nums are unique.
nums is sorted in ascending order.
```

Idea:

- use two pointers to record the start and end of a range.
- if the next number is not the next number of the current number, then we have a range.
- if the next number is the next number of the current number, then we don't have a range.
- if the next number is the next number of the current number, and it is the last number, then we have a range.

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 0) {
            return res;
        }
        int start = nums[0];
        int end = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == end + 1) {
                end = nums[i];
            } else {
                if (start == end) {
                    res.push_back(to_string(start));
                } else {
                    res.push_back(to_string(start) + "->" + to_string(end));
                }
                start = nums[i];
                end = nums[i];
            }
        }
        if (start == end) {
            res.push_back(to_string(start));
        } else {
            res.push_back(to_string(start) + "->" + to_string(end));
        }
        return res;
    }
    
};
```

Mine:

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {}; //solve testcase: []
        if (nums.size() == 1) return vector<string> {to_string(nums[0])}; //solve testcase: [-1]
        vector<string> res;
        int numsContinue = 0;
        int gap = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            // (nums[i+1] - nums[i] != 1 ), solve testcase: [-2147483648,-2147483647,2147483647]
            if (nums[i+1] != 1 + nums[i]) {
                // numsContinue = 0;
                gap = 1;
            } else {
                gap = 0;
                numsContinue++;
            }
            if (gap == 1) {
                if (numsContinue) {
                    res.push_back(to_string(nums[i]-numsContinue)+"->"+to_string(nums[i]));
                    numsContinue = 0;
                } else {
                    res.push_back(to_string(nums[i]));
                }
                if (i == nums.size()-2) {
                    res.push_back(to_string(nums[i+1]));
                }                
            } else {
                if (i == nums.size()-2) {
                    res.push_back(to_string(nums[i+1]-numsContinue)+"->"+to_string(nums[i+1]));
                }
            }
        }
        return res;
    }
};
```
    