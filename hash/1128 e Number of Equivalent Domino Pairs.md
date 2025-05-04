# [1128. Number of Equivalent Domino Pairs](https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/?envType=daily-question&envId=2025-05-04)

## Description

Given a list of `dominoes`, `dominoes[i] = [a, b]` is **equivalent to** `dominoes[j] = [c, d]` if and only if either (`a == c` and `b == d`), or (`a == d` and `b == c`) - that is, one domino can be rotated to be equal to another domino.

Return *the number of pairs* `(i, j)` *for which* `0 <= i < j < dominoes.length`*, and* `dominoes[i]` *is **equivalent to*** `dominoes[j]`.

**Example 1:**

```
Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1

```

**Example 2:**

```
Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
Output: 3

```

**Constraints:**

- `1 <= dominoes.length <= 4 * 104`
- `dominoes[i].length == 2`
- `1 <= dominoes[i][j] <= 9`

## Solution

```python
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        d = {}
        for i in dominoes:
            if i[0] > i[1]:
                i[0], i[1] = i[1], i[0]
            if (i[0], i[1]) not in d:
                d[(i[0], i[1])] = 0
            d[(i[0], i[1])] += 1
        # print(d)
        cnt = 0
        for value in d.values():
            if value > 1:
                cnt += value * (value - 1) / 2
        return int(cnt)
```
