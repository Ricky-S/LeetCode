# [103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

## Description

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

### Example 1:

![image](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
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


- -100 <= Node.val <= 100


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            leftToRight = !leftToRight;
            res.push_back(level);
        }
        return res;
    }
};
```

My solution:

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>{};
        vector<vector<int>> res;
        res.push_back(vector<int>{root->val});
        queue<TreeNode*> qu;
        qu.push(root);
        int zigzag = 0;
        while (!qu.empty()) {
            int len = qu.size();
            vector<int> eleLevel;
            zigzag++;
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
            if(zigzag % 2 == 1) {
                reverse(eleLevel.begin(), eleLevel.end());                                 
            }
            if(!eleLevel.empty()) res.push_back(eleLevel);
        }
        return res;        
    }
};
```