# [1079. Letter Tile Possibilities](https://leetcode.com/problems/letter-tile-possibilities/description/?envType=daily-question&envId=2025-02-17)


## Description


You have `n`  `tiles`, where each tile has one letter `tiles[i]` printed on it.

Return *the number of possible non-empty sequences of letters* you can make using the letters printed on those `tiles`.

**Example 1:**

```
Input: tiles = "AAB"
Output: 8
Explanation:The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

```

**Example 2:**

```
Input: tiles = "AAABBC"
Output: 188

```

**Example 3:**

```
Input: tiles = "V"
Output: 1

```

**Constraints:**

- `1 <= tiles.length <= 7`
- `tiles` consists of uppercase English letters.

## Solution

```python
from collections import Counter

class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        freq_map = Counter(tiles)

        def dfs(i):
            s = 1
            for k, v in freq_map.items():
                if v == 0:
                    continue
                
                freq_map[k] -= 1
                s += dfs(i + 1)
                freq_map[k] += 1
            
            return s
        
        return dfs(0) - 1

# Example usage
solution = Solution()
print(solution.numTilePossibilities("AAB"))  # Output: 8
```




