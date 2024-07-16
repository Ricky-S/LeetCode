# [2096. Step-By-Step Directions From a Binary Tree Node to Another](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/?envType=daily-question&envId=2024-07-16)

## Description

You are given the `root` of a **binary tree** with `n` nodes. Each node is uniquely assigned a value from `1` to `n`. You are also given an integer `startValue` representing the value of the start node `s`, and a different integer `destValue` representing the value of the destination node `t`.

Find the **shortest path** starting from node `s` and ending at node `t`. Generate step-by-step directions of such path as a string consisting of only the **uppercase** letters `'L'`, `'R'`, and `'U'`. Each letter indicates a specific direction:

- `'L'` means to go from a node to its **left child** node.
- `'R'` means to go from a node to its **right child** node.
- `'U'` means to go from a node to its **parent** node.

Return *the step-by-step directions of the **shortest path** from node* `s` *to node* `t`.

**Example 1:**

!https://assets.leetcode.com/uploads/2021/11/15/eg1.png

```
Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

```

**Example 2:**

!https://assets.leetcode.com/uploads/2021/11/15/eg2.png

```
Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.

```

**Constraints:**

- The number of nodes in the tree is `n`.
- `2 <= n <= 105`
- `1 <= Node.val <= n`
- All the values in the tree are **unique**.
- `1 <= startValue, destValue <= n`
- `startValue != destValue`


## Solution

```python
# Definition for a binary tree node.
# class TreeNode:

#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def findPath(self, root: TreeNode, startValue: int, destValue: int) -> str:
        def dfs(node, target):
            if not node:
                return []
            if node.val == target:
                return [node.val]
            left = dfs(node.left, target)
            if left:
                return [node.val] + left
            right = dfs(node.right, target)
            if right:
                return [node.val] + right
            return []
        path1 = dfs(root, startValue)
        path2 = dfs(root, destValue)
        i = 0
        while i < len(path1) and i < len(path2) and path1[i] == path2[i]:
            i += 1
        return ''.join(['L' if i < len(path1) and path1[i] == path1[i - 1] else 'R' for i in range(i, len(path1))] + ['U' for _ in range(i, len(path2))])
```


```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        def route(node: TreeNode, val, path):
            if node.val == val:
                return 1
            if node.left and route(node.left, val, path):
                path += 'L'
            elif node.right and route(node.right, val, path):
                path += 'R'
            return path
        start_route = []
        dest_route = []
        
        test = route(root, startValue, start_route)
        test = route(root, destValue, dest_route)
        while len(start_route) and len(dest_route) and start_route[-1] == dest_route[-1]:
            start_route.pop()
            dest_route.pop()
        return "".join("U" * len(start_route)) + "".join(reversed(dest_route))        
```