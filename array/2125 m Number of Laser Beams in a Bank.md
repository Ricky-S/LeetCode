# [2125. Number of Laser Beams in a Bank](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/?envType=daily-question&envId=2024-01-03)

https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/?envType=daily-question&envId=2025-10-27

## Description

Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.

There is one laser beam between any two security devices if both conditions are met:

The two devices are located on two different rows: r1 and r2, where r1 < r2.
For each row i where r1 < i < r2, there are no security devices in the ith row.
Laser beams are independent, i.e., one beam does not interfere nor join with another.

Return the total number of laser beams in the bank.



### Example 1:

![image](https://assets.leetcode.com/uploads/2021/12/24/laser1.jpg)

```
Input: bank = ["011001","000000","010100","001000"]
Output: 8
Explanation: Between each of the following device pairs, there is one beam. In total, there are 8 beams:
 * bank[0][1] -- bank[2][1]
 * bank[0][1] -- bank[2][3]
 * bank[0][2] -- bank[2][1]
 * bank[0][2] -- bank[2][3]
 * bank[0][5] -- bank[2][1]
 * bank[0][5] -- bank[2][3]
 * bank[2][1] -- bank[3][2]
 * bank[2][3] -- bank[3][2]
Note that there is no beam between any device on the 0th row with any on the 3rd row.
This is because the 2nd row contains security devices, which breaks the second condition.
```

### Example 2:

![image](https://assets.leetcode.com/uploads/2021/12/24/laser2.jpg)

```
Input: bank = ["000","111","000"]
Output: 0
Explanation: There does not exist two devices located on two different rows.
```

## Constraints

- `m == bank.length`
- `n == bank[i].length`
- `1 <= m, n <= 10^5`
- `bank[i][j] is either '0' or '1'.`

## Solution

```python
class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        count = []
        for i in range(len(bank)):
            count.append(bank[i].count('1'))
        # print(count)
        
        length = len(count)
        res = 0

        i, j = 0, 1

        while(i<length and j <length):
            if count[i] != 0 and count[j] != 0:
                res = res + count[i] * count[j]
                i = j
                j += 1
            elif count[i] == 0:
                i += 1
                j += 1
            elif count[j] == 0:
                j += 1



        return res
```

```python
class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        count = [row.count('1') for row in bank]
        
        length = len(count)
        res = 0

        i, j = 0, 1

        while j < length:
            if count[i] != 0 and count[j] != 0:
                res += count[i] * count[j]
                i = j
            j += 1
            if count[i] == 0 or i == j:
                i += 1

        return res


```

```python
class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        # l = [sum([int(i) for i in list(temp)]) for temp in bank]
        # l2 = [i for i in l if i != 0]
        # return sum(l2[i] * l2[i+1] for i in range(len(l2)-1))
        ans = 0
        pre = 0
        for i in bank:
            count = i.count('1') 
            if count != 0:
                ans += pre * count
                pre = count
        return ans
```