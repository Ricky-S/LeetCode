# [543. Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/description/?envType=daily-question&envId=2024-02-27)

## description

Given the `root` of a binary tree, return _the length of the diameter of the tree_.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the `root`.

The length of a path between two nodes is represented by the number of edges between them.

### Example 1:

![image](https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg)

```text
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
```

### Example 2:

```text
Input: root = [1,2]
Output: 1
```

### Constraints:

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-100 <= Node.val <= 100`


## Solution

```python
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ans = 0
        def depth(node):
            if not node: return 0
            left = depth(node.left)
            right = depth(node.right)
            self.ans = max(self.ans, left + right)
            return max(left, right) + 1
        depth(root)
        return self.ans
```

```python

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.diameter = 0

    def depth(self, root):
        left = self.depth(root.left) if root.left else 0
        right = self.depth(root.right) if root.right else 0

        self.diameter = max(self.diameter, left+right)
        return 1+max(left, right)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.depth(root)
        return self.diameter
```