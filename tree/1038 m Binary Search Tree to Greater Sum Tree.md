# [1038. Binary Search Tree to Greater Sum Tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/?envType=daily-question&envId=2024-06-25)

## Description

Given the `root` of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a *binary search tree* is a tree that satisfies these constraints:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

**Example 1:**

!https://assets.leetcode.com/uploads/2019/05/02/tree.png

```
Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

```

**Example 2:**

```
Input: root = [0,null,1]
Output: [1,null,1]

```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 100]`.
- `0 <= Node.val <= 100`
- All the values in the tree are **unique**.

**Note:** This question is the same as 538: https://leetcode.com/problems/convert-bst-to-greater-tree/


## Solution

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        def dfs(node, sum):
            if not node:
                return sum
            sum = dfs(node.right, sum)
            node.val += sum
            sum = node.val
            sum = dfs(node.left, sum)
            return sum
        dfs(root, 0)
        return root
```

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        def dfs(node, val):
            if node.right:
                val = dfs(node.right, val)
            val += node.val
            node.val = val
            if node.left:
                val = dfs(node.left, val)
            return val
        dfs(root, 0)
        return root
        
```