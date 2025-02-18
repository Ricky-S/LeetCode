# [257. Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/description/?envType=problem-list-v2&envId=backtracking)

## Description


Given the `root` of a binary tree, return *all root-to-leaf paths in **any order***.

A **leaf** is a node with no children.

**Example 1:**

!https://assets.leetcode.com/uploads/2021/03/12/paths-tree.jpg

```
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

```

**Example 2:**

```
Input: root = [1]
Output: ["1"]

```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 100]`.
- `100 <= Node.val <= 100`


## Solution

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        def dfs(node, path):
            if not node:
                return 0
            current_p = path + '->' + str(node.val) if path else str(node.val)
            if not node.left and not node.right:
                res.append(current_p)
                return
            dfs(node.left, current_p)
            dfs(node.right, current_p)
        
        res = []
        if root:
            dfs(root, "")
        return res

```

