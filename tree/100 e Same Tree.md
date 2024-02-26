# [100. Same Tree](https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-26)

## Description

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

### Example 1:
![image](https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg)
```
Input: p = [1,2,3], q = [1,2,3]
Output: true
```

### Example 2:
![image](https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg)
```
Input: p = [1,2], q = [1,null,2]
Output: false
```

### Example 3:
![image](https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg)
```
Input: p = [1,2,1], q = [1,1,2]
Output: false
```

**Constraints:**

- The number of nodes in both trees is in the range [0, 100].
- -10^4 <= Node.val <= 10^4


## Solution

```python

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # Base case: If both trees are empty, they are identical.
        if not p and not q:
            return True
        # If one of the trees is empty and the other is not, they are not identical.
        if not p or not q:
            return False
        
        # Compare the values of the current nodes.
        if p.val != q.val:
            return False
        
        # Recursively check the left and right subtrees.
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
```