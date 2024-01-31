# [739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31)

## Description

Given a list of daily temperatures `T`, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put `0` instead.


### Example 1:

```
Input: T = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```

### Example 2:

```
Input: T = [30,40,50,60]
Output: [1,1,1,0]
```

### Example 3:

```
Input: T = [30,60,90]
Output: [1,1,0]
```

### Constraints:

- `1 <= T.length <= 10^5`
- `30 <= T[i] <= 100`


## Solution

```python
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        answer = [0] * n
        stack = []  # Stack to store pairs of (temperature, index)

        for i in range(n - 1, -1, -1):
            # Pop elements from the stack until the top element is warmer
            while stack and temperatures[i] >= stack[-1][0]:
                stack.pop()

            # If stack is not empty, the top element is the next warmer temperature
            if stack:
                answer[i] = stack[-1][1] - i

            # Push the current temperature with its index onto the stack
            stack.append((temperatures[i], i))

        return answer
```