# [997. Find the Town Judge](https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22)

## Description

In a town, there are `N` people. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

1. The town judge trusts nobody.

2. Everybody (except for the town judge) trusts the town judge.

3. There is exactly one person that satisfies properties 1 and 2.

You are given `trust`, an array of pairs `trust[i] = [a, b]` representing that the person labelled `a` trusts the person labelled `b`.

If the town judge exists and can be identified, return the label of the town judge. Otherwise, return `-1`.

### Example 1:

```
Input: N = 2, trust = [[1,2]]
Output: 2
```

### Example 2:

```
Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
```

### Example 3:

```
Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
```

## Constraints:

* `1 <= N <= 1000`
* `0 <= trust.length <= 10^4`
* `trust[i].length == 2`
* `trust[i]` are all different
* `trust[i][0] != trust[i][1]`
* `1 <= trust[i][0], trust[i][1] <= N`

## Solution

```python
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        if N == 1:
            return 1
        dic = {}
        for i in trust:
            dic[i[0]] = dic.get(i[0], 0) - 1
            dic[i[1]] = dic.get(i[1], 0) + 1
        for i in dic:
            if dic[i] == N - 1:
                return i
        return -1
```

```python
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        count = [0] * (n + 1)
        for i, j in trust:
            count[i] -= 1
            count[j] += 1
        for i in range(1, n + 1):
            if count[i] == n - 1:
                return i
        return -1     
```