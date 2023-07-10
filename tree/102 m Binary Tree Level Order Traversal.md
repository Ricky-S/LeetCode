# [102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)

## Description

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

### Example 1:

![image](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```

### Example 2:

```
Input: root = [1]
Output: [[1]]
```

### Example 3:

```
Input: root = []
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range [0, 2000].


- -1000 <= Node.val <= 1000

Idea:

level order traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};
```

My solution:

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>{};
        vector<vector<int>> res;
        res.push_back(vector<int>{root->val});
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            int len = qu.size();
            vector<int> eleLevel;
            for(int i = 0; i < len; i++) {
                TreeNode* front = qu.front();
                if (front->left) {
                    qu.push(front->left);
                    eleLevel.push_back(front->left->val);
                }
                if (front->right) {
                    qu.push(front->right);
                    eleLevel.push_back(front->right->val);
                }
                qu.pop();
            }
            if(!eleLevel.empty()) res.push_back(eleLevel);
        }
        return res;
    }
};
```