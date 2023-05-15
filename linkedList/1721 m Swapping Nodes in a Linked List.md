# 1721. Swapping Nodes in a Linked List

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

Example 1:

![image](https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg)

```
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
```

Example 2:

```
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
```

Example 3:

```
Input: head = [1], k = 1
Output: [1]
```

Example 4:

```
Input: head = [1,2], k = 1
Output: [2,1]
```

Example 5:

```
Input: head = [1,2,3], k = 2
Output: [1,2,3]
```

Constraints:

- The number of nodes in the list is n.
- 1 <= k <= n <= 10^5
- 0 <= Node.val <= 100



Idea:

1. find the kth node from the beginning, and the kth node from the end.
2. swap the value of the two nodes.
3. return the head.



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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* l1 {nullptr};
        ListNode* l2 {nullptr};
        for (auto p = head; p!=nullptr; p = p->next) {
            if (l2 != nullptr){
                l2 = l2->next;
            }
            if(--k == 0) {
                l1 = p;
                l2 = head;
                // cout << l1->val<< endl;
            }
        }
        swap(l1->val, l2->val);
        return head;
    }
};
```

























