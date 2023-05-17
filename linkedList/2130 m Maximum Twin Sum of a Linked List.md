# 2130. Maximum Twin Sum of a Linked List

In a linked list of size `n`, where `n` is even, the ith node (0 indexed) of the linked list is known as the twin of the `n - i - 1`th node, if 0 <= i <= n / 2-1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

example 1:
![](https://assets.leetcode.com/uploads/2021/12/03/eg1drawio.png)
```
Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 
```

example 2:
![](https://assets.leetcode.com/uploads/2021/12/03/eg2drawio.png)
```
Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 
```

example 3:
![](https://assets.leetcode.com/uploads/2021/12/03/eg3drawio.png)
```
Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
```

constraints:
- The number of nodes in the list is an even integer in the range [2, $10^5$].
- 1 <= Node.val <= $10^5$

idea:

use fast and slow head to find the middle node.

reverse the second half of the linked list.

use two heads to find the maximum sum.


```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow {head};
        ListNode* fast {head};
        while (fast && fast -> next) {

            // cout << slow->val << endl;
            // cout << fast->val << endl;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* nextp {nullptr};
        ListNode* prev {nullptr};
        while (slow) {
            nextp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextp;
        }
        // cout << temp->val << endl;
        int sum {0};
        while (prev) {
            sum = max(sum, head->val+prev->val);
            head = head->next;
            prev = prev->next;
        }

        return sum;
    }
};
```