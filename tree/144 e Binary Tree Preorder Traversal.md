# 144. Binary Tree Preorder Traversal

Given the root of a binary tree, return the preorder traversal of its nodes' values.

ex1\
![image](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)
```cpp
Input: root = [1,null,2,3]
Output: [1,2,3]
```

ex2
```cpp
Input: root = []
Output: []
```

ex3
```cpp
Input: root = [1]
Output: [1]
```

Constraints\
```cpp
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
```

idea:

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
    void preTraversal(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        result.push_back(node->val);
        preTraversal(node->left, result);
        preTraversal(node->right, result);

    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preTraversal(root, result);
        return result;
    }
};
```











