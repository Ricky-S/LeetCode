# [94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/?envType=daily-question&envId=2023-12-09)

## Description

Given the `root` of a binary tree, return *the inorder traversal of its nodes' values*.

### Example 1:

![image](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

```
Input: root = [1,null,2,3]
Output: [1,3,2]
```

### Example 2:

```
Input: root = []

Output: []
```

### Example 3:

```
Input: root = [1]

Output: [1]
```

## Constraints:

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`
- Follow up: Recursive solution is trivial, could you do it iteratively?

## Solution:

```python
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        def dfs(root):
            if not root:
                return
            dfs(root.left)
            res.append(root.val)
            dfs(root.right)
        dfs(root)
        return res
```

```python
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            res.append(root.val)
            root = root.right
        return res
```

```python
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        stack = []
        current = root

        while current or stack:
            # Reach the left most Node of the current Node
            while current:
                # Place pointer to a tree node on the stack 
                # before traversing the node's left subtree
                stack.append(current)
                current = current.left
            
            # Current must be NULL at this point
            current = stack.pop()
            result.append(current.val)

            # We have visited the node and its left subtree.
            # Now, it's right subtree's turn
            current = current.right

        return result
```