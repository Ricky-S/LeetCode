# [530. Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/)

## description

Given the `root` of a Binary Search Tree (BST), return _the minimum absolute difference between the values of any two different nodes in the tree_.

### Example 1:

![image](https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg)

```text
Input: root = [4,2,6,1,3]
Output: 1
```

### Example 2:

![image](https://assets.leetcode.com/uploads/2021/02/05/bst2.jpg)

```text
Input: root = [1,0,48,null,null,12,49]
Output: 1
```

### Constraints:

- The number of nodes in the tree is in the range `[2, 10^4]`.
- `0 <= Node.val <= 10^5`

Idea:

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrderTraversal(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        inOrderTraversal(node->left, result);
        result.push_back(node->val);
        inOrderTraversal(node->right, result);
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> result;
        inOrderTraversal(root, result);
        int minDiff = INT_MAX;
        for (int i = 1; i < result.size(); i++) {
            minDiff = min(minDiff, result[i] - result[i - 1]);
        }
        return minDiff;
    }
};
```

OR 

```cpp
class Solution {
public:
    int inorderTraverse(TreeNode* root, int& val, int& min_dif) {
        if (root->left != NULL)
            inorderTraverse(root->left, val, min_dif);
        if (val >= 0) 
            min_dif = min(min_dif, root->val - val);
        val = root->val;
        if (root->right != NULL) 
            inorderTraverse(root->right, val, min_dif);
        return min_dif;
    }
    int getMinimumDifference(TreeNode* root) {
        int min_dif = INT_MAX, val = -1;
        return inorderTraverse(root, val, min_dif);
    }
};
```
