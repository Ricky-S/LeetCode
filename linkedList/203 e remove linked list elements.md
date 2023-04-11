Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.


Example 1:\
![image](https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg)\

```
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
```

Example 2:
```
Input: head = [], val = 1
Output: []
```

Example 3:
```
Input: head = [7,7,7,7], val = 7
Output: []
```


Idea:\
first node and other nodes should be processed separately. 


$O(n)$
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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        ListNode* current = head;
        while (current != NULL && current->next != NULL) {
            if (current->next->val == val) {
                ListNode* tmp = current->next;
                current->next = current->next->next;
                delete tmp;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};
```

























