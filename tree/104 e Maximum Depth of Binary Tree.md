# 104. Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

ex1

![image](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)
```cpp
Input: root = [3,9,20,null,null,15,7]
Output: 3
```

ex2
```cpp
Input: root = [1,null,2]
Output: 2
```


Constraints\
```cpp
The number of nodes in the tree is in the range [0, 10^4].
-100 <= Node.val <= 100
```

idea:

traveral by level.



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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int level { 0 };
        if (root != NULL) que.push(root);
        else return 0;
        while (!que.empty()) {
            level++;
            int size = que.size();
            // vector<int> vec;
            // 
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                // vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return level;
    }
};
```











