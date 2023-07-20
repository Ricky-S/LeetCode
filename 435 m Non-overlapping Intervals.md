# [435. Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)

## Description


Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.


Example 1:

```
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
```

Example 2:

```
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
```

Example 3:

```
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
```

Constraints:

* 1 <= intervals.length <= 2 * 10^4


* intervals[i].length == 2


* -2 * 10^4 <= starti < endi <= 2 * 10^4


## Solution


Idea:

* Sort the intervals by the end time.


* If the start time of the next interval is smaller than the end time of the previous interval, then we need to remove the next interval.


* If the start time of the next interval is larger than the end time of the previous interval, then we don't need to remove the next interval.


* If the start time of the next interval is equal to the end time of the previous interval, then we need to remove the next interval.



```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int res = 0, prev = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prev) ++res;
            else prev = intervals[i][1];
        }
        return res;
    }
};
```

My Solution:

[idea](https://leetcode.com/problems/non-overlapping-intervals/solutions/3785409/beat-s-100-c-java-python-beginner-friendly/)

```cpp
class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int count = 1;
        int pre = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[pre][1]) {
                count++;
                pre = i;
            }
            
        }
        return intervals.size() - count;
    }
};

