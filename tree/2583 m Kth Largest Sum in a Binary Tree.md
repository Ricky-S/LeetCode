# [2583. Kth Largest Sum in a Binary Tree](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/)

## description

You are given the `root` of a binary tree and a positive integer` k`.

The **level sum** in the tree is the sum of the values of the nodes that are on the same level.

Return the `kth` **largest** *level sum* in the tree (not necessarily distinct). If there are fewer than `k` levels in the tree, return `-1`.

**Note** that two nodes are on the same level if they have the same distance from the root.

**Example 1:**

![image](https://assets.leetcode.com/uploads/2022/12/14/binaryytreeedrawio-2.png)

```text
Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.
```

**Example 2:**

![image](https://assets.leetcode.com/uploads/2022/12/14/treedrawio-3.png)

```text
Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.
```

Constraints:


- The number of nodes in the tree is `n`.
- `2 <= n <= 105`
- `1 <= Node.val <= 10^6`
- `1 <= k <= n`


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
    void lfs(TreeNode* root, vector<long long> &res) {
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size(); 
            long long sum = 0;
            while(size--) {
                TreeNode* tn=qu.front(); 
                qu.pop();
                sum += tn->val;
                if (tn->left) qu.push(tn->left);
                if (tn->right) qu.push(tn->right);
            }
            res.push_back(sum);
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> res;
        lfs(root, res);
        sort(res.begin(), res.end(), greater());
        // for (int i = 0; i< res.size(); i++) {
        //     cout << res[i] << endl;
        // }
        if(res.size() < k) return -1;
        return res[k-1];
    }
};
```

```python
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        res = []
        def lfs(root):
            qu = collections.deque()
            qu.append(root)
            while qu:
                size = len(qu)
                sum = 0
                while size:
                    tn = qu.popleft()
                    sum += tn.val
                    if tn.left: qu.append(tn.left)
                    if tn.right: qu.append(tn.right)
                    size -= 1
                res.append(sum)
        lfs(root)
        res.sort(reverse=True)
        if len(res) < k: return -1
        return res[k-1]
```

My Solution:

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        
        qu = deque()
        qu.append(root)
        ans = []
        while qu:
            size = len(qu)
            sum_level = 0
            for i in range(size):
                node = qu.popleft()
                # qu = qu[1:]
                if node.left:
                    qu.append(node.left)
                if node.right:
                    qu.append(node.right)
                sum_level += node.val
            ans.append(sum_level)
        if len(ans) < k:
            return -1
        else:
            ans.sort(reverse=True)
            return ans[k-1]
```