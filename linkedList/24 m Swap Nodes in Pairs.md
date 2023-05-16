# 24. Swap Nodes in Pairs

## **medium**

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

example 1:
![image](https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg)
```cpp
Input: head = [1,2,3,4]
Output: [2,1,4,3]
```

example 2:
```
Input: head = []
Output: []
```

example 3:
```
Input: head = [1]
Output: [1]
```

Constraints:
- The number of nodes in the list is in the range [0, 100].
- 0 <= Node.val <= 100

Idea:
1. swap the value of the two nodes.
2. return the head.

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        // ListNode* tmp;
        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next; 
            ListNode* tmp1 = cur->next->next->next; 

            cur->next = cur->next->next;   
            cur->next->next = tmp;          
            cur->next->next->next = tmp1;  

            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};
```





























