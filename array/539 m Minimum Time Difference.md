# [539. Minimum Time Difference](https://leetcode.com/problems/minimum-time-difference/description/?envType=daily-question&envId=2024-09-16)

## Description

Given a list of 24-hour clock time points in

**"HH:MM"**

format, return

*the minimum **minutes** difference between any two time-points in the list*

.

**Example 1:**

```
Input: timePoints = ["23:59","00:00"]
Output: 1

```

**Example 2:**

```
Input: timePoints = ["00:00","23:59","00:00"]
Output: 0

```

**Constraints:**

- `2 <= timePoints.length <= 2 * 104`
- `timePoints[i]` is in the format **"HH:MM"**.

## Solution

```python
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        timePoints.sort()
        time = 99999
        for i in range(len(timePoints)-1):
            h = int(timePoints[i+1][:2])-int(timePoints[i][:2])
            m = int(timePoints[i+1][-2:])-int(timePoints[i][-2:])
            time = min(time, h*60+m)
            # print(f"{time}")

        time = min(time, int(timePoints[0][:2])*60+int(timePoints[0][-2:])+(24-int(timePoints[-1][:2]))*60-int(timePoints[-1][-2:]))

        return time
```
