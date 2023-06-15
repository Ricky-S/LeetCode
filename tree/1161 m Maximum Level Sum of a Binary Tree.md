# [1161. Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)

## description

Given the `root` of a binary tree, the level of its root is `1`, the level of its children is `2`, and so on.

Return the **smallest** level `X` such that the sum of all the values of nodes at level `X` is **maximal**.

**Example 1:**

![image](https://assets.leetcode.com/uploads/2019/05/03/capture.JPG)

```text
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
```

**Example 2:**

```text
Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.

- `-10^5 <= Node.val <= 10^5`


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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN;
        int maxLevel = 0;
        int level = 0;
        while (!q.empty()) {
            level++;
            int size = q.size();
            int sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum > maxSum) {
                maxSum = sum;
                maxLevel = level;
            }
        }
        return maxLevel;
    }
};
```

My solution:

```cpp
class Solution {
public:

    int maxLevelSum(TreeNode* root) {
        int resSum = INT_MIN, resLevel = 1;
        int level = 1;
        queue<TreeNode*> qu;
        qu.push(root);
        while(qu.size()) {
            int size = qu.size(); 
            int sum = 0;
            while(size--) {
                TreeNode* tn=qu.front(); 
                qu.pop();
                sum += tn->val;
                if (tn->left) qu.push(tn->left);
                if (tn->right) qu.push(tn->right);
            }
            // cout << sum << endl;
            if (sum > resSum) {
                resSum = sum;
                resLevel = level;
            }
            level++;
        }
        return resLevel;
    }
};
```