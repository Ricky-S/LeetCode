# [3169. Count Days Without Meetings](https://leetcode.com/problems/count-days-without-meetings/description/?envType=daily-question&envId=2025-03-24)

## Description

You are given a positive integer `days` representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array `meetings` of size `n` where, `meetings[i] = [start_i, end_i]` represents the starting and ending days of meeting `i` (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

**Note:** The meetings may overlap.

**Example 1:**

**Input:** days = 10, meetings = [[5,7],[1,3],[9,10]]

**Output:** 2

**Explanation:**

There is no meeting scheduled on the 4th and 8th days.

**Example 2:**

**Input:** days = 5, meetings = [[2,4],[1,3]]

**Output:** 1

**Explanation:**

There is no meeting scheduled on the 5th day.

**Example 3:**

**Input:** days = 6, meetings = [[1,6]]

**Output:** 0

**Explanation:**

Meetings are scheduled for all working days.

**Constraints:**

- `1 <= days <= 109`
- `1 <= meetings.length <= 105`
- `meetings[i].length == 2`
- `1 <= meetings[i][0] <= meetings[i][1] <= days`

## Solution

```python
class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort(key=lambda x:(x[0], -x[1]))
        i = 0
        m2 = []
        for i in range(len(meetings)):
            if not m2 or meetings[i][0] > m2[-1][1]:
                m2.append(meetings[i])        
            else:
                m2[-1][1] = max(m2[-1][1], meetings[i][1])

        # print(m2)
        cnt = 0
        for start, end in m2:
            cnt += end - start + 1
        
        return days - cnt
```


