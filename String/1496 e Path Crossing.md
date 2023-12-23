# [1496. Path Crossing](https://leetcode.com/problems/path-crossing/description/?envType=daily-question&envId=2023-12-23)

## Description

Given a string `path`, where `path[i] = 'N'`, `'S'`, `'E'` or `'W'`, each representing moving one unit north, south, east, or west, respectively. You start at the origin `(0, 0)` on a 2D plane and walk on the path specified by `path`.

Return `True` if the path crosses itself at any point, that is, if at any time you are on a location you've previously visited. Return `False` otherwise.


## Examples

Example 1:

![img](https://assets.leetcode.com/uploads/2020/06/10/screen-shot-2020-06-10-at-123929-pm.png)

```

Input: path = "NES"
Output: false
Explanation: Notice that the path doesn't cross any point more than once.

```

Example 2:

![img](https://assets.leetcode.com/uploads/2020/06/10/screen-shot-2020-06-10-at-123843-pm.png)

```

Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.

```

### Constraints

- `1 <= path.length <= 10^4`
- `path` will only consist of characters in `{'N', 'S', 'E', 'W}`

## Solution

```python
class Solution:
    def isPathCrossing(self, path: str) -> bool:
        current = [0, 0]
        route=[]
        route.append(current)
        for ch in path:
            if ch == 'N':
                current = [current[0], current[1]+1]
            elif ch == 'E':
                current = [current[0]+1, current[1]]
            elif ch == 'S':
                current = [current[0], current[1]-1]
            elif ch == 'W':
                current = [current[0]-1, current[1]]    
            if current in route:
                return True
            else:
                route.append(current)                            
        return False
```

```python
class Solution:
    def isPathCrossing(self, path: str) -> bool:
        current = (0, 0)
        route = {current}
        direction = {'N': (0, 1), 'E': (1, 0), 'S': (0, -1), 'W': (-1, 0)}
        for ch in path:
            current = (current[0] + direction[ch][0], current[1] + direction[ch][1])
            if current in route:
                return True
            route.add(current)
        return False
```




