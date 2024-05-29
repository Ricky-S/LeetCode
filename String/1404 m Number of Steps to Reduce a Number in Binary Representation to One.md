# [1404. Number of Steps to Reduce a Number in Binary Representation to One](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2024-05-29)

## Description

Given the binary representation of an integer as a string `s`, return *the number of steps to reduce it to* `1` *under the following rules*:

- If the current number is even, you have to divide it by `2`.
- If the current number is odd, you have to add `1` to it.

It is guaranteed that you can always reach one for all test cases.

**Example 1:**

```
Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14.
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.
Step 5) 4 is even, divide by 2 and obtain 2.
Step 6) 2 is even, divide by 2 and obtain 1.

```

**Example 2:**

```
Input: s = "10"
Output: 1
Explanation: "10" corressponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.

```

**Example 3:**

```
Input: s = "1"
Output: 0

```

**Constraints:**

- `1 <= s.length <= 500`
- `s` consists of characters '0' or '1'
- `s[0] == '1'`

## Solution

```python
class Solution:
    def cal(self, number: int) -> int:
        if number % 2 == 0:
            return number // 2
        else:
            return number + 1

    def numSteps(self, s: str) -> int:
        number = int(s, 2)
        count = 0
        while number != 1:
            count += 1
            number = self.cal(number)
        return count

```

```python
class Solution:
    def numSteps(self, s: str) -> int:
        num = int(s, 2)
        steps = 0
        while num != 1:
            if num % 2 == 0:
                num //= 2
            else:
                num += 1
            steps += 1
        return steps
```