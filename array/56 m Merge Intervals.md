# [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/description/)

## Description

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

```
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
```

Example 2:

```
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

Constraints:

- 1 <= intervals.length <= 10^4


- intervals[i].length == 2
- 0 <= starti <= endi <= 10^4


## Solution

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] >= intervals[i][0]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
```

My Solution:

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        sort(intervals.begin(),intervals.end());
        int pre = 0;
        vector<vector<int>> res;
        // res.push_back(intervals[0]);
        int n = intervals.size();
        for (int i = 0; i < intervals.size(); i++) {
            if(i==n-1)
                res.push_back(intervals[i]);
            else if(intervals[i][1]>=intervals[i+1][0])
            {   
                intervals[i+1][0]=intervals[i][0];
                intervals[i+1][1]=max(intervals[i][1],intervals[i+1][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
```

```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans = []

        intervals.sort(key=lambda x:x[0])
        # print(intervals)
        pre = intervals[0]

        for interval in intervals[1:]:
            if interval[0] <= pre[1]:
                pre[1] = max(pre[1], interval[1])
            else:
                ans.append(pre)
                pre = interval
        ans.append(pre)
        return ans
```