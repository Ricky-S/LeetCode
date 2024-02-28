# [513. Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value/description/?envType=daily-question&envId=2024-02-28)

## description

Given the `root` of a binary tree, return _the leftmost value in the last row of the tree_.

### Example 1:

![image](https://assets.leetcode.com/uploads/2021/02/14/tree.jpg)

```text
Input: root = [2,1,3]
Output: 1
```

### Example 2:

```text
Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
```

### Constraints:

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-2^31 <= Node.val <= 2^31 - 1`
- **Note**: This question is the same as 199: https://leetcode.com/problems/binary-tree-right-side-view/


## Solution

```python
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        queue = [root]
        while queue:
            node = queue.pop(0)
            if node.right:
                queue.append(node.right)
            if node.left:
                queue.append(node.left)
        return node.val
```
