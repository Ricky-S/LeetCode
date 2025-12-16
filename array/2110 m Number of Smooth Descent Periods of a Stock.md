# [2110. Number of Smooth Descent Periods of a Stock](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/?envType=daily-question&envId=2025-12-15)

## Description

You are given an integer array `prices` representing the daily price history of a stock, where `prices[i]` is the stock price on the `ith` day.

A **smooth descent period** of a stock consists of **one or more contiguous** days such that the price on each day is **lower** than the price on the **preceding day** by **exactly** `1`. The first day of the period is exempted from this rule.

Return *the number of **smooth descent periods***.

**Example 1:**

```
Input: prices = [3,2,1,4]
Output: 7
Explanation: There are 7 smooth descent periods:
[3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
Note that a period with one day is a smooth descent period by the definition.

```

**Example 2:**

```
Input: prices = [8,6,7,7]
Output: 4
Explanation: There are 4 smooth descent periods: [8], [6], [7], and [7]
Note that [8,6] is not a smooth descent period as 8 - 6 ≠ 1.

```

**Example 3:**

```
Input: prices = [1]
Output: 1
Explanation: There is 1 smooth descent period: [1]

```

**Constraints:**

- `1 <= prices.length <= 105`
- `1 <= prices[i] <= 105`


## Solution (Python)

We can solve this problem efficiently with a simple linear scan. We count, for each day, the length of the current smooth descent period ending at that day and add it to our answer. Every single day is at least a descent period of 1.

Let `count` be the length of current descent, reset to 1 whenever the descent rule breaks.

```python
class Solution:
    def getDescentPeriods(self, prices):
        n = len(prices)
        ans = 0
        count = 1
        for i in range(n):
            if i == 0:
                ans += 1
                continue
            if prices[i-1] - prices[i] == 1:
                count += 1
            else:
                count = 1
            ans += count
        return ans
```

### Explanation

- Each single day is its own "smooth descent period".
- If the current price is exactly 1 less than the previous, the descent extends. Otherwise, we start a new descent.
- For each day, we add the current descent length to the total; this captures all descent periods ending on this day.

### Example

For `prices = [3,2,1,4]`:
- day 0: `[3]` → count=1, ans=1
- day 1: `[2]`, `[3,2]` → count=2, ans=3
- day 2: `[1]`, `[2,1]`, `[3,2,1]` → count=3, ans=6
- day 3: `[4]` → count=1, ans=7

Total = 7 descent periods.

---

```python
class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        if len(prices) == 0: return 0
        cnt = 1
        current = 1
        for i in range(1,len(prices)):
            if prices[i-1] - prices[i] == 1:
                current += 1
            else:
                current = 1
            cnt += current
        return cnt
```